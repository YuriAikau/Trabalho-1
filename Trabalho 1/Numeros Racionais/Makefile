OBJ = obj
SRC = source

# .c files
C_SOURCE=$(wildcard ./source/*.c)
 
# .h files
H_SOURCE=$(wildcard ./source/*.h)
 
# Object files
OBJS=$(subst .c,.o,$(subst source,obj,$(C_SOURCE)))


all: $(SRC)/main.c
	gcc $< ./$(OBJ)/Racionais.o -o teste -lm

%.o: ./$(SRC)/%.c ./$(SRC)/%.h
	gcc -c $< -o ./$(OBJ)/$@ -lm

clean:
	rm $(OBJ)/*.o
	rmdir $(OBJ)
