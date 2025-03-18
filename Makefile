ALLDEPS += Makefile

O=build

PROG=load

SRCS += main.c libhydrogen/hydrogen.c

include mkglue/prog.mk
