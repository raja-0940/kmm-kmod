#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Quentin Barrand");
MODULE_DESCRIPTION("A simple kernel module for KMM CI");

static char *myversion = "1.0.0";
module_param(myversion, charp, 0000);

MODULE_PARM_DESC(myversion, "Version string");
MODULE_VERSION(*myversion);

static int __init kmm_ci_init(void) {
    printk(KERN_INFO "Hello, World! from: %s\n", module_name(THIS_MODULE));
    printk(KERN_INFO "My version is: %s\n", myversion);
    return 0;
}

static void __exit kmm_ci_exit(void) {
    printk(KERN_INFO "Goodbye, World! from: %s\n", module_name(THIS_MODULE));
}

module_init(kmm_ci_init);
module_exit(kmm_ci_exit);
