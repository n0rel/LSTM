CFLAGS = -O
CC = g++

all: LSTM clean

LSTM: main.o LSTMCell.o
	$(CC) $(CFLAGS) -o LSTM main.o LSTMCell.o

main.o:
	$(CC) $(CFLAGS) -c src/main.cpp

LSTMCell.o:
	$(CC) $(CFLAGS) -c src/LSTMCell.cpp

clean:
	rm -f *.o
