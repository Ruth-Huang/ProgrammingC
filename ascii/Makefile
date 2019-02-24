all: ascii

ascii: ascii.o old_link_list.o
	gcc -o ascii ascii.o old_link_list.o

ascii.o: ascii.c 
	gcc -c ascii.c

old_link_list.o: old_link_list.c
	gcc -c old_link_list.c

clean:
	rm *.o ascii
