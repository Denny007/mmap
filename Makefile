PRO1 := mtest1 
PRO2 := mtest2

all:$(PRO1) $(PRO2)



#all sources
#SRCS-y += $(wildcard ./*.c)

OBJ1 = mmap_test1.o
OBJ2 = mmap_test2.o


CC = gcc

$(PRO1):$(OBJ1)
	$(CC) -o $@ $(OBJ1)

$(PRO2):$(OBJ2)
	$(CC) -o $@ $(OBJ2)


%.o:%.c
	$(CC) -g -Wall -c -o $@ $<


.PHONY:clean
clean:
	rm -rf *.o $(PRO1) $(PRO2)
