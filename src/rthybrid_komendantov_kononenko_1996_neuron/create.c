#include <math.h>
#include <stdlib.h>
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron.h"
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/create.h"

rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_create(void **out_instance)
{
    if (!out_instance) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *self = (rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *)malloc(sizeof(rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t));
    if (!self) return RTSYN_ABI_STATUS_ERROR;

    self->burst_duration = 1.0; self->burst_duration_value = 1.0; self->freq = 1000.0;
    self->s_points = 1; self->input_syn = 0.0; self->input_burst_duration = 1.0;
    self->p[1] = 0.0; self->p[2] = 0.0; self->p[3] = 0.02; self->p[4] = 0.11;
    self->p[5] = 40.0; self->p[6] = 0.25; self->p[7] = -70.0; self->p[8] = 0.0231;
    self->p[9] = 0.165; self->p[10] = -58.0; self->p[11] = 400.0; self->p[12] = 10.0;
    self->p[13] = 1.5; self->p[14] = 150.0; self->p[15] = 0.02; self->p[16] = 15000.0;
    self->p[17] = 0.00004; self->p[18] = 0.002; self->p[19] = 50.0;
    self->vars[0] = -55.0; self->vars[7] = 0.0;
    self->vars[1] = 1.0 / (1.0 + exp(0.4 * (self->vars[0] + 34.0)));
    self->vars[2] = 1.0 / (1.0 + exp(-0.55 * (self->vars[0] + 43.0)));
    self->vars[3] = 1.0 / (1.0 + exp(-0.4 * (self->vars[0] + 31.0)));
    self->vars[4] = 1.0 / (1.0 + exp(0.25 * (self->vars[0] + 45.0)));
    self->vars[5] = 1.0 / (1.0 + exp(-0.18 * (self->vars[0] + 25.0)));
    self->vars[6] = 1.0 / (1.0 + exp(-0.2 * self->vars[0]));

    *out_instance = self;
    return RTSYN_ABI_STATUS_OK;
}
