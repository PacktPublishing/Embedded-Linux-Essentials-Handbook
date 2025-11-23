#include <linux/init.h>
#include <linux/module.h>

static int __init test_init(void)
{
	printk(KERN_INFO "Hello World!\n");
	return 0;
}

static void __exit test_exit(void)
{
	printk(KERN_INFO "Goodbye World!\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_AUTHOR("Mohammed Billoo");
MODULE_DESCRIPTION("Hello World kernel module");
MODULE_LICENSE("GPL");

