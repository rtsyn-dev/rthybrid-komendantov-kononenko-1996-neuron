#include <stddef.h>
        #include "rtsyn/rthybrid_komendantov_kononenko_1996_neuron.h"
        #include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron.h"
        #include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/create.h"
        #include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/destroy.h"
        #include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/process.h"
        #include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/read_state.h"
        #include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/set_param.h"
        #include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/start.h"
        #include "rtsyn/internal/rthybrid_komendantov_kononenko_1996_neuron/stop.h"

        static const rtsyn_abi_port_descriptor_t rtsyn_rthybrid_komendantov_kononenko_1996_neuron_ports[RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_COUNT] = {
            [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_ISYN_NA] =
        {
            .name = "isyn_na",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_BURST_DURATION_S] =
        {
            .name = "burst_duration_s",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_IN,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_VM_V] =
        {
            .name = "vm_v",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_VM_MV] =
        {
            .name = "vm_mv",
            .value_type = RTSYN_ABI_VALUE_F64,
            .direction = RTSYN_ABI_PORT_DIRECTION_OUT,
        },
        };

        static const rtsyn_abi_param_descriptor_t rtsyn_rthybrid_komendantov_kononenko_1996_neuron_params[RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_COUNT] = {
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_BURST_DURATION] =
        {
            .name = "burst_duration",
            .description = "Burst duration in seconds, or -1 to use the input port",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_I] =
        {
            .name = "I",
            .description = "Injected current",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_CM] =
        {
            .name = "cm",
            .description = "Membrane capacitance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_NA_V] =
        {
            .name = "g_na_v",
            .description = "Voltage-dependent sodium conductance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V_NA] =
        {
            .name = "v_na",
            .description = "Sodium reversal potential",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_NA] =
        {
            .name = "g_na",
            .description = "Sodium conductance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_NA_TTX] =
        {
            .name = "g_na_ttx",
            .description = "TTX-sensitive sodium conductance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_K] =
        {
            .name = "g_k",
            .description = "Potassium conductance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_K_TEA] =
        {
            .name = "g_k_tea",
            .description = "TEA-sensitive potassium conductance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V_K] =
        {
            .name = "v_k",
            .description = "Potassium reversal potential",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_B] =
        {
            .name = "g_b",
            .description = "B current conductance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V_B] =
        {
            .name = "v_b",
            .description = "B current reversal potential",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_CA] =
        {
            .name = "g_ca",
            .description = "Calcium conductance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V_CA] =
        {
            .name = "v_ca",
            .description = "Calcium reversal potential",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_G_CA_CA] =
        {
            .name = "g_ca_ca",
            .description = "Calcium-dependent calcium conductance",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_K_BETA] =
        {
            .name = "k_beta",
            .description = "Calcium beta gain",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_BETA] =
        {
            .name = "beta",
            .description = "Calcium beta parameter",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_RHO] =
        {
            .name = "rho",
            .description = "Calcium dynamics rho",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_K_S] =
        {
            .name = "k_s",
            .description = "Calcium removal scale",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_V0_MV] =
        {
            .name = "v0_mV",
            .description = "Initial membrane potential",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
};

        static const rtsyn_abi_state_descriptor_t rtsyn_rthybrid_komendantov_kononenko_1996_neuron_states[RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_COUNT] = {
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_M] =
        {
            .name = "m",
            .description = "m gate",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_H] =
        {
            .name = "h",
            .description = "h gate",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_N] =
        {
            .name = "n",
            .description = "n gate",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
    [RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_CA] =
        {
            .name = "ca",
            .description = "calcium state",
            .value_type = RTSYN_ABI_VALUE_F64,
        },
};

        static const rtsyn_abi_node_descriptor_t rtsyn_rthybrid_komendantov_kononenko_1996_neuron_descriptor = {
            .name = "rthybrid_komendantov_kononenko_1996_neuron",
            .node_type = RTSYN_ABI_NODE_PLUGIN,
            .port_count = RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PORT_COUNT,
            .ports = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_ports,
            .param_count = RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_PARAM_COUNT,
            .params = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_params,
            .state_count = RTSYN_RTHYBRID_KOMENDANTOV_KONONENKO_1996_NEURON_STATE_COUNT,
            .states = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_states,
            .callbacks = {
                .create = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_create,
                .set_param = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_set_param,
                .read_state = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_read_state,
                .start = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_start,
                .process = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_process,
                .stop = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_stop,
                .destroy = rtsyn_rthybrid_komendantov_kononenko_1996_neuron_destroy,
            },
        };

        RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_rthybrid_komendantov_kononenko_1996_neuron_get_descriptor(void)
        {
            return &rtsyn_rthybrid_komendantov_kononenko_1996_neuron_descriptor;
        }

        RTSYN_ABI_EXPORT const rtsyn_abi_node_descriptor_t *RTSYN_ABI_CALL rtsyn_module_get_descriptor(void)
        {
            return rtsyn_rthybrid_komendantov_kononenko_1996_neuron_get_descriptor();
        }
