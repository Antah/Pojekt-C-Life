CC=clang
CFLAGS=-c -Wall
DEPS=data.h flags.h rules.h neighbours.h
OBJECTS=main.o flags.o loader.o newGen.o neighbours.o rules.o savePpm.o
all: life

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

life: $(OBJECTS)
	$(CC) $(OBJECTS)  -o life

main.o: main.c
	$(CC) $(CFLAGS) main.c

flags.o: flags.c
	$(CC) $(CFLAGS) flags.c

loader.o: loader.c
	$(CC) $(CFLAGS) loader.c

newGen.o: newGen.c
	$(CC) $(CFLAGS) newGen.c

neighbours.o: neighbours.c
	$(CC) $(CFLAGS) neighbours.c

rules.o: rules.c
	$(CC) $(CFLAGS) rules.c

savePpm.o: savePpm.c
	$(CC) $(CFLAGS) savePpm.c



clean:
	rm -rf *o hello
