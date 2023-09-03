CC=g++
DEPS = link_stack.h
TGE = link_stack
OBJ = test.o
CFLAGS = -g  -I. -Wall

$(TGE):$(OBJ)
	$(CC) -o $@ $^ 

%.o:%.cpp
	$(CC) -g -c $(CFLAGS) -o $@ $^

.PHONY:clean
clean:
	rm -f $(OBJ) $(TGE) 


