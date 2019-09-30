PULP_APP = main
PULP_APP_FC_SRCS = src/Uart_Debug.c src/main.c src/AFE4490.c


PULP_CFLAGS += -DNUM_CORES=$(CORE) -Iinc -O3 -g3  -fno-tree-loop-distribute-patterns
PULP_LDFLAGS = -lm -lg

include $(GAP_SDK_HOME)/tools/rules/pulp_rules.mk
