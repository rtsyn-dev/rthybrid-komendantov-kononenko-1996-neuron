#include <stdlib.h>
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron.h"
#include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/destroy.h"
void RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_destroy(void *instance)
{
    free((rtsyn_rthybrid_komendantov_kononenko_1996_neuron_instance_t *)instance);
}
