obj-m += test-module.o

all:
	make -C $(PWD)/../linux M=$(PWD) modules
clean:
	make -C $(PWD)/../linux M=$(PWD) clean
