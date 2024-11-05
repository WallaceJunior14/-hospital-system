APPS = ./apps
OUTPUT = ./output
INCLUDE = ./includes
LIB = ./lib
OBJ = ./obj
SRC = ./src

FLAGS = -O3 -Wall

all: libed app

create: 
	mkdir -p $(OUTPUT)
	mkdir -p $(OBJ)
	mkdir -p $(LIB)

libed: \
	$(OBJ)/bst_id.o \
	$(OBJ)/bst_name.o \


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h | create
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

app: $(OUTPUT)/main

$(OUTPUT)/%: $(APPS)/%.c $(OBJ)/*.o | create
	gcc $(FLAGS) $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run:
	$(OUTPUT)/main.out

export_lib: libed
	ar -rcs $(LIB)/libed.a $(OBJ)/*

clean:
	rm -f $(OUTPUT)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(OUTPUT)/*
