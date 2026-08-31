/**
 * @file rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/set_param.h
 * @brief set_param callback declaration for RTHybrid Komendantov-Kononenko 1996 Neuron.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_SET_PARAM_H
#define RTSYN_INTERNAL_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_SET_PARAM_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_set_param(void *instance, uint32_t param_index, const void *value);
#ifdef __cplusplus
}
#endif
#endif
