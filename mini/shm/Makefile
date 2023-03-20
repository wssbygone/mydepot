.PHONY:all
all:shmread shmwrite

shmwrite:shmwrite.c
	gcc -o $@ $^

shmread:shmread.c 
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f shmwrite shmread
