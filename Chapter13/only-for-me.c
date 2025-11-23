#include <bcc/proto.h>

// TODO: Update these for your own IP address (10.10.2.226)
#define FIRST_OCTET 10
#define SECOND_OCTET 10
#define THIRD_OCTET 2
#define FOURTH_OCTET 226

int only_for_me(struct __sk_buff *skb)
{
	unsigned char ip_octets[4];
	u8 *cursor = NULL;
	struct ethernet_t *ethernet = cursor_advance(cursor, sizeof(*ethernet));
	if (ethernet->type == 0x800) {
		struct ip_t *ip = cursor_advance(cursor, sizeof(*ip));
		if (ip->nextp == 6) {

			ip_octets[0] = ip->dst & 0xff;
			ip_octets[1] = (ip->dst >> 8) & 0xff;
			ip_octets[2] = (ip->dst >> 16) & 0xff;
			ip_octets[3] = (ip->dst >> 24) & 0xff;

			if (ip_octets[3] == FIRST_OCTET && ip_octets[2] == SECOND_OCTET && ip_octets[1] == THIRD_OCTET && ip_octets[0] == FOURTH_OCTET)
				bpf_trace_printk("packet for us!\n");
		}
	}
	return 0;
}
