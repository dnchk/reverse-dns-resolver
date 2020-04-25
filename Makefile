CC = gcc
LD = gcc
OBJS = main.o resolver.o
DEPS = resolver.h
TARGET = dns_resolver
CFLAGS = -Wall -Werror

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
