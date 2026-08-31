#include <math.h>
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron.h"
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/set_param.h"
static double finite_or(double value, double fallback) { return isfinite(value) ? value : fallback; }
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_set_param(void *instance, uint32_t param_index, const void *value)
{
    rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *self = (rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *)instance;
    if (!self || !value) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;

    switch (param_index) {
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_BURST_DURATION: self->burst_duration_value = finite_or(*(const double *)value, 1.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_I: self->p[1] = finite_or(*(const double *)value, 0.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_CM: self->p[3] = finite_or(*(const double *)value, 0.02); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_NA_V: self->p[4] = finite_or(*(const double *)value, 0.11); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V_NA: self->p[5] = finite_or(*(const double *)value, 40.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_NA: self->p[8] = finite_or(*(const double *)value, 0.0231); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_NA_TTX: self->p[11] = finite_or(*(const double *)value, 400.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_K: self->p[6] = finite_or(*(const double *)value, 0.25); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_K_TEA: self->p[12] = finite_or(*(const double *)value, 10.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V_K: self->p[7] = finite_or(*(const double *)value, -70.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_B: self->p[9] = finite_or(*(const double *)value, 0.165); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V_B: self->p[10] = finite_or(*(const double *)value, -58.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_CA: self->p[13] = finite_or(*(const double *)value, 1.5); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V_CA: self->p[14] = finite_or(*(const double *)value, 150.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_CA_CA: self->p[15] = finite_or(*(const double *)value, 0.02); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_K_BETA: self->p[16] = finite_or(*(const double *)value, 15000.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_BETA: self->p[17] = finite_or(*(const double *)value, 0.00004); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_RHO: self->p[18] = finite_or(*(const double *)value, 0.002); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_K_S: self->p[19] = finite_or(*(const double *)value, 50.0); return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V0_MV: self->vars[0] = finite_or(*(const double *)value, -55.0); return RTSYN_ABI_STATUS_OK;
    default: return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }

}
