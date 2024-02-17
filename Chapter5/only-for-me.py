from bcc import BPF
import socket

bpf = BPF(src_file = "only-for-me.c")
fn_ofm = bpf.load_func("only_for_me", BPF.SOCKET_FILTER)
BPF.attach_raw_socket(fn_ofm, "eth0")
bpf.trace_print()
