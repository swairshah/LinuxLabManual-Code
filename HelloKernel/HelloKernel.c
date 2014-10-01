/* Make sure linux-headers are installed if not,
 * `sudo apt-get install linux-headers-$(uname -r)`
 * should do the trick on debian based distros
 */

#include <linux/module.h> // include for all kernel modules
#include <linux/init.h>   // include for __init and __exit macros
#include <linux/kernel.h> // include for KERN_INFO
#include <linux/config.h> 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Swair Shah");
MODULE_DESCRIPTION("a Hello-Kernel Module");

static int __init hellomodule_init(void) {
    printk("Loading the HelloKernel Module.\n");
    printk("Hello Kernel!\n");
    return 0;
}

static void __exit hellomodule_exit(void) {
    printk("Unloading the HelloKernel Module.\n");
    return;
}

module_init(hellomodule_init);
module_init(hellomodule_exit);

