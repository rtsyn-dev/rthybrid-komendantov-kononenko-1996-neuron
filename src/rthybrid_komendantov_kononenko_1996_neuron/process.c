#include <math.h>
#include <string.h>
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron.h"
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/process.h"

static double period_seconds_from_context(const rtsyn_abi_runtime_context_t *context)
{
    if (!context || context->period_ns == 0U) return 0.001;
    return (double)context->period_ns / 1000000000.0;
}

static int read_f64(const rtsyn_abi_runtime_context_t *context, uint32_t port_index, double *out_value)
{
    if (!context || !context->api || !context->api->read || !out_value) return 0;
    double value = 0.0;
    if (context->api->read(context, port_index, &value) != RTSYN_ABI_STATUS_OK) return 0;
    if (!isfinite(value)) return 0;
    *out_value = value;
    return 1;
}

static void clamp_f64(double *value, double fallback)
{
    if (!isfinite(*value)) {
        *value = fallback;
    } else if (fabs(*value) > 1e6) {
        *value = *value > 0.0 ? 1e6 : -1e6;
    }
}

typedef void (*rtsyn_rk4_deriv_fn_t)(const double *state, double *deriv, void *user_data);
static void rk4_step(double *state, size_t n, double dt, rtsyn_rk4_deriv_fn_t deriv_fn, void *user_data)
{
    double k1[8] = {0};
    double k2[8] = {0};
    double k3[8] = {0};
    double k4[8] = {0};
    double tmp[8] = {0};
    if (!state || !deriv_fn || n == 0 || n > 8 || dt <= 0.0) return;
    deriv_fn(state, k1, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + 0.5 * dt * k1[i];
    deriv_fn(tmp, k2, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + 0.5 * dt * k2[i];
    deriv_fn(tmp, k3, user_data);
    for (size_t i = 0; i < n; ++i) tmp[i] = state[i] + dt * k3[i];
    deriv_fn(tmp, k4, user_data);
    for (size_t i = 0; i < n; ++i) state[i] += (dt / 6.0) * (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]);
}


    enum { V=0, M_B=1, H_B=2, M=3, H=4, N=5, M_CA=6, CA=7 };
    enum { DT=0, I=1, SYN=2, CM=3, G_NA_V=4, V_NA=5, G_K=6, V_K=7, G_NA=8, G_B=9, V_B=10, G_NA_TTX=11, G_K_TEA=12, G_CA=13, V_CA=14, G_CA_CA=15, K_BETA=16, BETA=17, RHO=18, K_S=19 };
    typedef struct { const double *p; double syn; } rthybrid_komendantov_kononenko_1996_neuron_ctx_t;
    static double eclip(double x) { if (x > 700.0) return exp(700.0); if (x < -700.0) return exp(-700.0); return exp(x); }
    static double i_na_v(const double v[8], const double p[20]) { return p[G_NA_V] * (1.0 / (1.0 + eclip(-0.2 * (v[V] + 45.0)))) * (v[V] - p[V_NA]); }
    static double i_k(const double v[8], const double p[20]) { return p[G_K] * (v[V] - p[V_K]); }
    static double i_na(const double v[8], const double p[20]) { return p[G_NA] * (v[V] - p[V_NA]); }
    static double i_b(const double v[8], const double p[20]) { return p[G_B] * v[M_B] * v[H_B] * (v[V] - p[V_B]); }
    static double f_m_b(const double v[8]) { return (1.0 / (1.0 + eclip(0.4 * (v[V] + 34.0))) - v[M_B]) / 0.05; }
    static double f_h_b(const double v[8]) { return (1.0 / (1.0 + eclip(-0.55 * (v[V] + 43.0))) - v[H_B]) / 1.5; }
    static double i_na_ttx(const double v[8], const double p[20]) { return p[G_NA_TTX] * v[M] * v[M] * v[M] * v[H] * (v[V] - p[V_NA]); }
    static double i_k_tea(const double v[8], const double p[20]) { return p[G_K_TEA] * v[N] * v[N] * v[N] * v[N] * (v[V] - p[V_K]); }
    static double f_m(const double v[8]) { return (1.0 / (1.0 + eclip(-0.4 * (v[V] + 31.0))) - v[M]) / 0.0005; }
    static double f_h(const double v[8]) { return (1.0 / (1.0 + eclip(0.25 * (v[V] + 45.0))) - v[H]) / 0.01; }
    static double f_n(const double v[8]) { return (1.0 / (1.0 + eclip(-0.18 * (v[V] + 25.0))) - v[N]) / 0.015; }
    static double i_ca(const double v[8], const double p[20]) { return p[G_CA] * v[M_CA] * v[M_CA] * (v[V] - p[V_CA]); }
    static double f_m_ca(const double v[8]) { return (1.0 / (1.0 + eclip(-0.2 * v[V])) - v[M_CA]) / 0.01; }
    static double i_ca_ca(const double v[8], const double p[20]) { return p[G_CA_CA] * (1.0 / (1.0 + eclip(-0.06 * (v[V] + 45.0)))) * (1.0 / (1.0 + eclip(p[K_BETA] * (v[CA] - p[BETA])))) * (v[V] - p[V_CA]); }
    static double f_ca(const double v[8], const double p[20]) { return p[RHO] * ((-i_ca(v, p) / 808.310846) - (p[K_S] * v[CA])); }
    static void deriv(const double *v, double *r, void *user_data) {
        const rthybrid_komendantov_kononenko_1996_neuron_ctx_t *ctx = (const rthybrid_komendantov_kononenko_1996_neuron_ctx_t *)user_data;
        const double *p = ctx->p;
        double syn = isfinite(ctx->syn) ? ctx->syn : 0.0;
        r[V] = (-(i_na_ttx(v,p)+i_k_tea(v,p)+i_k(v,p)+i_na(v,p)+i_na_v(v,p)+i_b(v,p)+i_ca(v,p)+i_ca_ca(v,p)) + p[I] - syn) / p[CM];
        r[M_B] = f_m_b(v); r[H_B] = f_h_b(v); r[M] = f_m(v); r[H] = f_h(v);
        r[N] = f_n(v); r[M_CA] = f_m_ca(v); r[CA] = f_ca(v,p);
    }
    static int vars8_finite(const double v[8]) {
        for (size_t i = 0; i < 8; ++i) if (!isfinite(v[i])) return 0;
        return 1;
    }


rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_process(void *instance, const rtsyn_abi_runtime_context_t *context)
{
    rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *self = (rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *)instance;
    if (!self || !context || !context->api || !context->api->write)
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;

    (void)read_f64(context, RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_ISYN_NA, &self->input_syn);
    (void)read_f64(context, RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_BURST_DURATION_S, &self->input_burst_duration);
    double period_seconds = period_seconds_from_context(context);
    self->freq = 1.0 / period_seconds;
    self->burst_duration = self->burst_duration_value <= -1.0 ? self->input_burst_duration : self->burst_duration_value;
    if (self->burst_duration <= 0.0) self->burst_duration = 1e-9;
    self->p[DT] = 0.0001;
    self->s_points = 1;
    rthybrid_komendantov_kononenko_1996_neuron_ctx_t ctx = { .p = self->p, .syn = self->input_syn };
    for (size_t i = 0; i < self->s_points; ++i) {
        double previous[8];
        memcpy(previous, self->vars, sizeof(previous));
        rk4_step(self->vars, 8, self->p[DT], deriv, &ctx);
        if (!vars8_finite(self->vars)) {
            memcpy(self->vars, previous, sizeof(previous));
            break;
        }
    }
    double vm_v = self->vars[V] / 1000.0;
    double vm_mv = self->vars[V];
    (void)context->api->write(context, RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_VM_V, &vm_v);
    (void)context->api->write(context, RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_VM_MV, &vm_mv);
    return RTSYN_ABI_STATUS_OK;

}
