#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kprobes.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Joseph Beshay");
MODULE_AUTHOR("Swair Shah");
MODULE_DESCRIPTION("a Hello-Kernel Module");

long sys_open_callback(int dfd, const char __user *filename, int flags, umode_t mode) {
    printk("do_sys_open: %s\n",filename);
    jprobe_return();
    return 0;
}

static struct jprobe my_jprobe = {
    .kp = {
        .symbol_name = "do_sys_open",
    },
    .entry = (kprobe_opcode_t *) sys_open_callback,
};

static int __init init_function(void) {
    int ret;

    if ((ret = register_jprobe(&my_jprobe)) <0) {
        printk("register_jprobe failed, returned %d\n", ret);
        return -1;
    }
    printk("Planted jprobe at %p, handler addr %p\n",
            my_jprobe.kp.addr, my_jprobe.entry);
    return 0;
}

static void __exit end_function(void) {
    unregister_jprobe(&my_jprobe);
    printk("jprobe unregistered\n");
}

module_init(init_function);
module_exit(end_function);
