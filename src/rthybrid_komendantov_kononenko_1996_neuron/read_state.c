#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron.h"
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/read_state.h"
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_read_state(const void *instance, uint32_t state_index, void *out_value)
{
    const rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *self = (const rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *)instance;
    if (!self || !out_value) return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    switch (state_index) {

    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_M: *(double *)out_value = self->vars[3]; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_H: *(double *)out_value = self->vars[4]; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_N: *(double *)out_value = self->vars[5]; return RTSYN_ABI_STATUS_OK;
    case RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_CA: *(double *)out_value = self->vars[7]; return RTSYN_ABI_STATUS_OK;

    default:
        return RTSYN_ABI_STATUS_INVALID_ARGUMENT;
    }
}
