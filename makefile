CC = g++

#compile options
CFLAGS = -c -g -Wall

TARGET = Library

DEPS = Main.o Library.o Book.o Login.o Student.o IssueBook.o Stack.o Queue.o

HEADERS = Library.h Book.h Login.h Student.h FileHandle.h IssueBook.h Stack.h Queue.h

RM = del
$(TARGET): $(DEPS)
	$(CC) $(DEPS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $<


clean:
	$(RM) *.o $(TARGET)