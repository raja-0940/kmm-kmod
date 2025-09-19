ifndef KVER
KVER=$(shell uname -r)
endif

ifndef KERNEL_SRC_DIR
KERNEL_SRC_DIR =/lib/modules/$(KVER)/build
endif

ifndef MY_MODULE
MY_MODULE=kmm_ci_b.o
endif

ccflags-y += -I$(KERNEL_SRC_DIR)/include
obj-m += kmm_ci_a.o
obj-m += $(MY_MODULE)

all:
	make -C $(KERNEL_SRC_DIR) $(MAKE_OPTS) M=$(PWD) modules

