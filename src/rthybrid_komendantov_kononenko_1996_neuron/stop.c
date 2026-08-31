#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron.h"
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/stop.h"
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_stop(void *instance)
{
    return instance ? RTSYN_ABI_STATUS_OK : RTSYN_ABI_STATUS_INVALID_ARGUMENT;
}
