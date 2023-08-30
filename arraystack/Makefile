CC=g++
#CFLAGS=-I.
DEPS = array_stack.h
TGE = array_stack
OBJ = test.o array_stack.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

$(TGE): $(OBJ)
	$(CC) -o $@ $^ 

.PHONY:clean
clean:
	rm -f $(OBJ) $(TGE) 


