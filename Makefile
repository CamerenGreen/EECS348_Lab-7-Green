CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGETS = football temperature

all: $(TARGETS)

football: football.o football_main.o
	$(CC) $(CFLAGS) -o $@ $^

temperature: temperature.o temperature_main.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGETS) *.o

.PHONY: all clean
