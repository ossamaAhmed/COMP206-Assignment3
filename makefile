Assignment3 : reader shell linkedlist

reader : reader.c record.h
	gcc -o reader reader.c

shell : shell.c
	gcc -o shell shell.c

linkedlist : linkedlist.c linkedlist.h
	gcc -o linkedList linkedlist.c

clean :
	rm -f Assignment3 *.o
