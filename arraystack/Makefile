CC=g++
DEPS = array_stack.h
TGE = array_stack
OBJ = test.o
CFLAGS = -g -Wall -I.

$(TGE):$(OBJ)
	$(CC) -o $@ $^ 

%.o:%.cpp
	$(CC) -g -c $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	rm -f $(OBJ) $(TGE) 


