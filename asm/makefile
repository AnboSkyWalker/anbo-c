
CC=gcc

SRC_ASM_INTEL=asm-intel.c
DST_ASM_INTEL=asm-intel

SRC_ASM_ATT=asm-att.c
DST_ASM_ATT=asm-att

all: $(DST_ASM_INTEL) $(DST_ASM_ATT)

$(DST_ASM_INTEL):
	$(CC) $(SRC_ASM_INTEL) -o $(DST_ASM_INTEL) -masm=intel

$(DST_ASM_ATT):
	$(CC) $(SRC_ASM_ATT) -o $(DST_ASM_ATT)

.PHONY:
	clean

clean:
	rm -rf $(DST_ASM_INTEL) $(DST_ASM_ATT)

