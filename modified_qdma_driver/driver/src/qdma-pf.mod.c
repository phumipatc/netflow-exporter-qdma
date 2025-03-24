#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x45675a9b, "pci_save_state" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x9abb160c, "get_user_pages_fast" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x6be1fa7d, "__class_create" },
	{ 0x9ca9a08, "param_ops_uint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xead9d06f, "pci_msix_vec_count" },
	{ 0x7c12e672, "pci_enable_device" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xc2f4ac9f, "pci_bus_max_busnr" },
	{ 0xf8c34c97, "pci_enable_device_mem" },
	{ 0x1a8c40f5, "pci_iomap" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x6a51a2c9, "pci_vfs_assigned" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8288e3bd, "dma_unmap_page_attrs" },
	{ 0x9314862d, "class_destroy" },
	{ 0x96848186, "scnprintf" },
	{ 0x8c79d81a, "__pci_register_driver" },
	{ 0xa436f43, "pci_num_vf" },
	{ 0x6df1aaf1, "kernel_sigaction" },
	{ 0x6063629a, "pci_request_regions" },
	{ 0x92b84d67, "genlmsg_put" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0x91cb99a9, "pci_sriov_get_totalvfs" },
	{ 0x9645b9bb, "__put_devmap_managed_page_refs" },
	{ 0xdc0e4855, "timer_delete" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xe2964344, "__wake_up" },
	{ 0xcccec57, "kmem_cache_create" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xb45e7624, "pci_unregister_driver" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x57b91c18, "wake_up_process" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2d896063, "dma_map_page_attrs" },
	{ 0x92997ed8, "_printk" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xfe916dc6, "hex_dump_to_buffer" },
	{ 0x5706106, "pci_enable_msix_range" },
	{ 0xa916b694, "strnlen" },
	{ 0x4ce9352, "__alloc_skb" },
	{ 0x618911fc, "numa_node" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x1951606f, "__free_pages" },
	{ 0x85da403a, "kmem_cache_alloc" },
	{ 0x86c4673f, "_dev_info" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x9c6b1793, "cdev_add" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x3bb30f10, "_dev_err" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x6453dc55, "netlink_unicast" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xe7204928, "device_create" },
	{ 0x942758eb, "kfree_skb_reason" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x475aba98, "kmem_cache_free" },
	{ 0xb3a199cf, "dma_alloc_attrs" },
	{ 0x826c393d, "debugfs_remove" },
	{ 0xc0954478, "nla_put" },
	{ 0x9166fada, "strncpy" },
	{ 0x99627c47, "pci_aer_clear_nonfatal_status" },
	{ 0x9ed12e20, "kmalloc_large" },
	{ 0x6cc39b85, "sysfs_create_group" },
	{ 0xb47063bd, "kthread_stop" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x8518a4a6, "_raw_spin_trylock_bh" },
	{ 0xcc605959, "pci_iounmap" },
	{ 0x89e0a27d, "pci_restore_state" },
	{ 0xfb578fc5, "memset" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x5ae1ed48, "__alloc_pages" },
	{ 0xfe0c6c85, "pci_set_master" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xeaa48c9a, "kthread_bind" },
	{ 0x29f747bb, "param_ops_string" },
	{ 0xae773e1b, "pcie_capability_clear_and_set_word_unlocked" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x1737c78, "kthread_create_on_node" },
	{ 0x7ce3afb9, "dma_set_coherent_mask" },
	{ 0xca6dde5e, "set_page_dirty" },
	{ 0x7c125db4, "sysfs_remove_group" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xfd2791f4, "debugfs_create_file" },
	{ 0x1afdc50e, "dma_free_attrs" },
	{ 0xf088124d, "pcie_get_readrq" },
	{ 0x167e7f9d, "__get_user_1" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xb8ea2496, "pci_release_regions" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xeb321487, "__folio_put" },
	{ 0xc794958, "device_destroy" },
	{ 0x2cf56265, "__dynamic_pr_debug" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xea09535e, "pci_disable_sriov" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xd271faaa, "pci_disable_msix" },
	{ 0xdfd1add6, "pci_disable_device" },
	{ 0xc26132e4, "pcie_set_readrq" },
	{ 0x34c218b4, "dma_set_mask" },
	{ 0xb08ec0e, "genl_unregister_family" },
	{ 0x878aee78, "kmalloc_trace" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x91eb9b4, "round_jiffies" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x93d6f986, "debugfs_create_dir" },
	{ 0x4d5f43c1, "genl_register_family" },
	{ 0xb5b54b34, "_raw_spin_unlock" },
	{ 0x619c7e8e, "pci_enable_sriov" },
	{ 0x732e83c6, "cdev_init" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe2c17b5d, "__SCT__might_resched" },
	{ 0x84fe8709, "kmalloc_caches" },
	{ 0xa7cb3c86, "cdev_del" },
	{ 0x722365e, "kmem_cache_destroy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x49c1c9d6, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v000010EEd00009011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009211sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009311sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009212sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009114sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009214sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009314sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009118sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009218sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000901Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000911Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000921Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000931Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009121sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009221sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009321sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009122sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009222sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009322sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009124sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009224sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009324sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009128sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009228sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009328sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000902Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000912Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000922Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000932Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009031sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009131sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009231sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009331sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009132sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009232sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009332sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009134sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009234sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009334sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009138sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009238sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009338sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000903Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000913Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000923Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000933Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00006AA0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009141sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009241sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009341sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009142sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009242sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009342sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009044sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009144sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009244sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009344sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009048sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009148sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009248sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd00009348sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B211sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B311sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B212sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B114sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B214sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B314sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B118sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B218sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B01Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B11Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B21Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B31Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B121sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B221sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B321sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B122sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B222sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B322sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B124sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B224sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B324sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B128sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B228sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B328sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B02Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B12Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B22Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B32Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B031sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B131sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B231sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B331sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B132sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B232sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B332sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B134sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B234sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B334sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B138sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B238sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B338sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B03Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B13Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B23Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B33Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B141sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B241sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B341sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B142sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B242sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B342sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B044sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B144sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B244sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B344sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B048sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B148sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B248sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B348sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B058sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B158sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B258sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000B358sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "FFBC5242BEC113EAE1E86EC");
