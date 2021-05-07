reserve : main.c reserve.o
	gcc -o reserve main.c reserve.0
reserve.o : reserve.c reserve.h
	gcc -c reserve.c
clean :
	rm *.o reserve