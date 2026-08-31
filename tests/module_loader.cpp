#include <gtest/gtest.h>
#include <rtsyn/module_loader.h>

#ifndef RTSYN_TEST_MODULE_PATH
#error RTSYN_TEST_MODULE_PATH must contain the built plugin path
#endif

TEST(ModuleLoader, LoadsDescriptor)
{
    rtsyn_module_loader_t *loader = rtsyn_module_loader_create(RTSYN_TEST_MODULE_PATH);
    ASSERT_NE(loader, nullptr);
    const rtsyn_abi_node_descriptor_t *descriptor =
        rtsyn_module_loader_get_descriptor(loader);
    ASSERT_NE(descriptor, nullptr);
    EXPECT_STREQ(descriptor->name, "rthybrid_komendantov_kononenko_1996_neuron");
    rtsyn_module_loader_destroy(loader);
}
