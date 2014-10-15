#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>


long jdo_sys_open(int dfd, const char __user *filename, int flags, umode_t mode)
{
	printk("do_sys_open: %s\n",filename);
	jprobe_return();
	return 0;
}

static struct jprobe my_jprobe = {
	.kp = {
		.symbol_name = "do_sys_open",
	},
	.entry = (kprobe_opcode_t *) jdo_sys_open,
};

static int __init my_init(void)
{
	int ret;

	if ((ret = register_jprobe(&my_jprobe)) <0) {
		printk("register_jprobe failed, returned %d\n", ret);
		return -1;
	}
	printk("Planted jprobe at %p, handler addr %p\n",
	       my_jprobe.kp.addr, my_jprobe.entry);
	return 0;
}

static void __exit my_exit(void)
{
	unregister_jprobe(&my_jprobe);
	printk("jprobe unregistered\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
