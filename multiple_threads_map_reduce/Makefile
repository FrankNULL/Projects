CC = gcc
CFLAGS = -g -std=c99
CLINK = -lpthread

wcs: main.o producer.o consumer.o utils.o
	$(CC) -o $@ $^ $(CFLAGS) $(CLINK)

main.o: main.c header.h
	$(CC) -o $@ -c main.c $(CFLAGS)

producer.o: producer.c header.h
	$(CC) -o $@ -c producer.c $(CFLAGS)

consumer.o: consumer.c header.h
	$(CC) -o $@ -c consumer.c $(CFLAGS)

utils.o: utils.c header.h
	$(CC) -o $@ -c utils.c $(CFLAGS)

clean: 
	rm wcs main.o producer.o consumer.o utils.o




