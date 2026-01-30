#include <common.h>
#include <command.h>

static int do_packt(struct cmd_tbl *cmd, int flag, int argc, char *const argv[])
{
	printf("Hello Packt World!\n");
	return 0;
}

U_BOOT_CMD(packt, 1, 1, do_packt, "Simple Packt command", ""
);

