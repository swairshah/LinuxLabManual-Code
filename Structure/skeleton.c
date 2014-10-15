#include <linux/module.h>  /* Needed by all modules */
#include <linux/kernel.h>  /* Needed for KERN_INFO */
#include <linux/init.h>    /* Needed for the macros */

MODULE_LICENSE("license type");
MODULE_AUTHOR("Author name");
MODULE_DESCRIPTION("what does your module do?");

static int __init init_function(void) {  
    /*
     * What to do when you load the module
     */
    return 0;
}

static void __exit end_function(void) {
    /*
     * What to do when you upload the module
     */
}

/* explicitly specify module init and
 * end functions
 */
module_init(init_function);
module_exit(end_function);
