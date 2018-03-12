TARGET=try
CC =gcc
CFLAGS ?=-pedantic
all:
	$(CC) $(CFLAGS) libc-string.a -o $(TARGET).x $(TARGET).c

clean:
	$(RM) $(TARGET).x
