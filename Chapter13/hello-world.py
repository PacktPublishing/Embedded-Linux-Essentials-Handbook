from bcc import BPF

BPF(src_file="hello-world.c").trace_print()
