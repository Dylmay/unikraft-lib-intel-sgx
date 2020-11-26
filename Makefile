UK_DIRECTORY ?= /home/dylan/.unikraft
UK_ROOT      ?= $(UK_DIRECTORY)/unikraft
UK_LIBS      ?= $(UK_DIRECTORY)/libs
UK_PLATS     ?= $(UK_DIRECTORY)/plats
LIBS         ?= $(UK_LIBS)/newlib

ifneq ($(KERNELRELEASE),)
	isgx-y := \
		sgx_main.o \
		sgx_page_cache.o \
		sgx_ioctl.o \
		sgx_vma.o \
		sgx_util.o\
		sgx_encl.o \
		sgx_encl2.o
	obj-m += isgx.o
else
KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)


$(MAKECMDGOALS):
	@make -C $(UK_ROOT) A=$(PWD) L=$(LIBS) P=$(PLATS) $(MAKECMDGOALS)

ukbuild:
	@make -C $(UK_ROOT) A=$(PWD) L=$(LIBS) P=$(PLATS)


default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

install: default
	$(MAKE) INSTALL_MOD_DIR=kernel/drivers/intel/sgx -C $(KDIR) M=$(PWD) modules_install
	depmod -A
	sh -c "cat /etc/modules | grep -Fxq isgx || echo isgx >> /etc/modules"

endif

clean:
	rm -vrf *.o *.ko *.order *.symvers *.mod.c .tmp_versions .*o.cmd build/
