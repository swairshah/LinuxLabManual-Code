/* Make sure linux-headers are installed if not,
 * `sudo apt-get install linux-headers-$(uname -r)`
 * should do the trick on debian based distros
 */

#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>         /* Needed for the macros */
#include <linux/inotify.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Swair Shah");
MODULE_DESCRIPTION("Module to Monitor File Events");

static struct inotify_event *event;
static struct inotify_handle *handle;

static void watch_file(void) {
}

static int __init start_hook(void) {  
    printk(KERN_INFO "Loading filewatch module...\n");
    watch_file();
    return 0;
}

static void __exit end_hook(void) {
    printk(KERN_INFO "Unloading the filewatch Module.\n");
}

module_init(start_hook);
module_exit(end_hook);
