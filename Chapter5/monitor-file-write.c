#include <linux/fs.h>

// TODO: Change this based on your file
#define FILE_INODE 168567

int trace_write(struct pt_regs *ctx, struct file *file,
		char __user *buf, size_t count)
{
	if (file->f_path.dentry->d_inode->i_ino == FILE_INODE)
		bpf_trace_printk("Wrote to our file!");
	return 0;
}
