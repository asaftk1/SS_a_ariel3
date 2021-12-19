CC =gcc
AR =ar
OBJECTS_MAIN= main.o
OBJECTS_my_func= my_func.o
FLAGS= -Wall -g 
all : stringProg

stringProg: $(OBJECTS_MAIN) libclassmy_func.a
	$(CC) $(FLAGS)  -o stringProg $(OBJECTS_MAIN) libclassmy_func.a

func: libclassmy_func.a
libclassmy_func.a: $(OBJECTS_my_func) 
	$(AR) -rcs libclassmy_func.a $(OBJECTS_my_func) 
	
.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg
