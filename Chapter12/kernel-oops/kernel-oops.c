#include <linux/init.h>
#include <linux/module.h>

static void test_generate_oops(void)
{
	*(int *) 0 = 0;
}

static int __init test_oops_init(void)
{
	printk("Going to generate oops!\n");
	test_generate_oops();
	return 0;
}

static void __exit test_oops_exit(void)
{
	printk("Oops out!\n");
}

module_init(test_oops_init);
module_exit(test_oops_exit);

MODULE_AUTHOR("Mohammed Billoo");
MODULE_DESCRIPTION("Kernel oops test");
MODULE_LICENSE("GPL");

