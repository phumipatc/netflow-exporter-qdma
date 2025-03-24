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
	{ 0xf8c34c97, "pci_enable_device_mem" },
	{ 0x1a8c40f5, "pci_iomap" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8288e3bd, "dma_unmap_page_attrs" },
	{ 0x9314862d, "class_destroy" },
	{ 0x96848186, "scnprintf" },
	{ 0x8c79d81a, "__pci_register_driver" },
	{ 0x6df1aaf1, "kernel_sigaction" },
	{ 0x6063629a, "pci_request_regions" },
	{ 0x92b84d67, "genlmsg_put" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
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
	{ 0xc6f46339, "init_timer_key" },
	{ 0xb8ea2496, "pci_release_regions" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xeb321487, "__folio_put" },
	{ 0xc794958, "device_destroy" },
	{ 0x2cf56265, "__dynamic_pr_debug" },
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

MODULE_ALIAS("pci:v000010EEd0000A011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A211sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A311sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A212sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A114sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A214sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A314sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A118sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A218sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A01Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A11Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A21Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A31Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A121sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A221sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A321sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A122sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A222sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A322sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A124sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A224sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A324sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A128sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A228sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A328sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A02Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A12Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A22Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A32Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A031sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A131sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A231sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A331sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A132sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A232sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A332sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A134sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A234sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A334sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A138sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A238sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A338sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A03Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A13Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A23Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A33Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A141sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A241sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A341sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A142sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A242sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A342sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A044sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A144sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A244sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A344sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A444sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A544sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A644sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A744sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A048sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A148sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A248sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000A348sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C011sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C111sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C211sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C311sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C012sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C112sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C212sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C312sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C014sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C114sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C214sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C314sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C018sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C118sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C218sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C318sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C01Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C11Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C21Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C31Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C021sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C121sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C221sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C321sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C022sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C122sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C222sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C322sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C024sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C124sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C224sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C324sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C028sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C128sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C228sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C328sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C02Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C12Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C22Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C32Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C031sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C131sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C231sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C331sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C032sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C132sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C232sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C332sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C034sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C134sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C234sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C334sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C038sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C138sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C238sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C338sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C03Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C13Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C23Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C33Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C041sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C141sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C241sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C341sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C042sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C142sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C242sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C342sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C044sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C144sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C244sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C344sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C444sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C544sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C644sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C744sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C048sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C148sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C248sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C348sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C058sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C158sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C258sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010EEd0000C358sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "FFBC5242BEC113EAE1E86EC");
