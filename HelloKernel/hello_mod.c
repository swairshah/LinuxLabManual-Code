/* Make sure linux-headers are installed if not,
 * `sudo apt-get install linux-headers-$(uname -r)`
 * should do the trick on debian based distros
 */

#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>         /* Needed for the macros */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Swair Shah");
MODULE_DESCRIPTION("a Hello-Kernel Module");

static int __init init_function(void) {  
    printk(KERN_INFO "Loading hello-kernel module...\n");
    printk(KERN_INFO "Hello Kernel!\n");
    return 0;
}

static void __exit end_function(void) {
    printk(KERN_INFO "Unloading the hello-kernel Module.\n");
}

module_init(init_function);
module_exit(end_function);
