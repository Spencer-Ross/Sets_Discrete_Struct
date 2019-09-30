main: pa1.o addElement.o builder.o ismember.o set.h
	gcc -g -o main pa1.o addElement.o builder.o ismember.o
pa1.o: pa1.c set.h
	gcc -c pa1.c
addElement.o: addElement.c set.h
	gcc -c addElement.c
builder.o: builder.c set.h
	gcc -c builder.c
ismember.o: ismember.c set.h
	gcc -c ismember.c
clean:
	rm *.o && rm main
tar:
	tar cvf pa1CSE215.tar pa1.c addElement.c builder.c ismember.c set.h makefile main
gzip:
	gzip pa1CSE215.tar
tgz:
	mv pa1CSE215.tar.gz pa1CSE215.tgz
