IDIR = ../include

CC = gcc
CFLAGS = -g -I$(IDIR)

ODIR = obj

mapreduce: main.c $(IDIR)/main.h $(ODIR)/phase1.o $(ODIR)/phase2.o $(ODIR)/phase3.o $(ODIR)/phase4.o
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR)/phase1.o: phase1.c $(IDIR)/phase1.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/phase2.o: phase2.c $(IDIR)/phase2.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/phase3.o: phase3.c $(IDIR)/phase3.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/phase4.o: phase4.c $(IDIR)/phase4.h
	$(CC) -c -o $@ $< $(CFLAGS)



.PHONY: clean

clean:
	rm mapreduce
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~
	rm -rf MapperInput
	rm ReducerResult.txt
	rm FinalResult.txt
