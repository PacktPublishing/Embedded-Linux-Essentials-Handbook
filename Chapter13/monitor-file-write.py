from bcc import BPF

bpf = BPF(src_file="monitor-file-write.c")
bpf.attach_kprobe(event="vfs_write", fn_name="trace_write")
bpf.trace_print()
