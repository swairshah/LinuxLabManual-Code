/* Make sure linux-headers are installed if not,
 * `sudo apt-get install linux-headers-$(uname -r)`
 * should do the trick on debian based distros
 */

#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>         /* Needed for the macros */
#include <linux/inotify.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Swair Shah");
MODULE_DESCRIPTION("a Hello-Kernel Module");

static int __init start_hook(void) {  
    printk(KERN_INFO "Loading hello-kernel module...\n");
    printk(KERN_INFO "Hello Kernel!\n");
    return 0;
}

static void __exit end_hook(void) {
    printk(KERN_INFO "Unloading the hello-kernel Module.\n");
}

module_init(start_hook);
module_exit(end_hook);
