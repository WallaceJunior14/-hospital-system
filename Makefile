APPS = ./apps
OUTPUT = ./output
INCLUDE = ./includes
LIB = ./lib
OBJ = ./obj
SRC = ./src

FLAGS = -O3 -Wall

# Alvo padrão
all: libed app

# Criação das pastas necessárias
create: 
	mkdir -p $(OUTPUT)
	mkdir -p $(OBJ)
	mkdir -p $(LIB)

# Compilar os arquivos objeto da biblioteca
libed: $(LIB)/libed.a

$(LIB)/libed.a: $(OBJ)/bst_id.o $(OBJ)/bst_name.o
	ar -rcs $@ $^

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h | create
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

# Compilar o aplicativo
app: $(OUTPUT)/main

$(OUTPUT)/%: $(APPS)/%.c $(LIB)/libed.a | create
	gcc $(FLAGS) $< $(LIB)/libed.a -I $(INCLUDE) -o $@

# Rodar o aplicativo
run:
	$(OUTPUT)/main

# Exportar a biblioteca
export_lib: libed

# Limpar os arquivos compilados
clean:
	rm -f $(OUTPUT)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(OUTPUT)/*
