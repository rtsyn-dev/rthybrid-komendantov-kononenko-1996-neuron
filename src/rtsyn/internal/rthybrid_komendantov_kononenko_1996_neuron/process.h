/**
 * @file rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/process.h
 * @brief process callback declaration for RTHybrid Komendantov-Kononenko 1996 Neuron.
 */
#ifndef RTSYN_INTERNAL_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PROCESS_H
#define RTSYN_INTERNAL_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PROCESS_H
#include <rtsyn/abi.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
rtsyn_abi_status_t RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_process(void *instance, const rtsyn_abi_runtime_context_t *context);
#ifdef __cplusplus
}
#endif
#endif
