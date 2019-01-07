
CC=gcc
CFLAGS_32=-m32
CFLAGS_64=-m64

SRC_FLOAT=float.c
SRC_FORMAT=format.c

DST_FLOAT=float
F32=$(DST_FLOAT)_32
F64=$(DST_FLOAT)_64

DST_FORMAT=format
FM32=$(DST_FORMAT)_32
FM64=$(DST_FORMAT)_64

all: $(F32) $(F64) $(FM32) $(FM64)

$(F32):
	$(CC) $(SRC_FLOAT) -o $(F32) $(CFLAGS_32)

$(F64):
	$(CC) $(SRC_FLOAT) -o $(F64) $(CFLAGS_64)

$(FM32):
	$(CC) $(SRC_FORMAT) -o $(FM32) $(CFLAGS_32)

$(FM64):
	$(CC) $(SRC_FORMAT) -o $(FM64) $(CFLAGS_64)

.PHONY:
	clean

clean:
	rm -rf $(F32) $(F64) $(FM32) $(FM64)

