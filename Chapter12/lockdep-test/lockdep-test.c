#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/module.h>

static struct task_struct *t1;
static spinlock_t l1;
static spinlock_t l2;

int thread_function(void *params)
{
	while (1) {
		spin_lock(&l1);
		spin_lock(&l2);
		msleep(1000);
		spin_unlock(&l2);
		spin_unlock(&l1);
	}
	return 0;
}

static int __init lockdep_test_init(void)
{
	spin_lock_init(&l1);
	spin_lock_init(&l2);
	t1 = kthread_create(thread_function, NULL, "locktest-fn");
	if (t1) {
  		wake_up_process(t1);
	}

	return 0;
}

static void __exit lockdep_test_exit(void)
{
	kthread_stop(t1);
}

MODULE_LICENSE("GPL");
module_init(lockdep_test_init);
module_exit(lockdep_test_exit);

