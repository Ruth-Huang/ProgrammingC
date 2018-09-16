all: stat

stat: stat.o mean.o stand_dev.o max_min.o
	gcc -o stat stat.o mean.o stand_dev.o max_min.o

stat.o: stat.c stat.h
	gcc -c stat.c

mean.o: mean.c
	gcc -c mean.c

stand_dev.o: stand_dev.c
	gcc -c stand_dev.c

max_min.o: max_min.c
	gcc -c max_min.c

clean: 
	rm *.o stat
