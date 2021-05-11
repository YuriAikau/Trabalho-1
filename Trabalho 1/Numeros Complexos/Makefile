OBJ = obj
SRC = source

# .c files
C_SOURCE=$(wildcard ./source/*.c)
 
# .h files
H_SOURCE=$(wildcard ./source/*.h)
 
# Object files
OBJS=$(subst .c,.o,$(subst source,obj,$(C_SOURCE)))

all: dir main exe

exe: $(OBJS)
	gcc $^ -o testes	

%.o: ./$(SRC)/%.c ./$(SRC)/%.h
	gcc -c $< -o ./$(OBJ)/$@ -lm

compila: $(C_SOURCE)
	gcc -c $^ -lm

main:
	gcc -c ./$(SRC)/main.c -o ./$(OBJ)/main.o -lm

dir:
	mkdir $(OBJ)

clean:
	rm $(OBJ)/*.o
	rmdir $(OBJ)
