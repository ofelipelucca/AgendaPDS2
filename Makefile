# <<<<<<< HEAD

# CXX = g++
# CXXFLAGS = -std=c++17 -Wall -Wextra

# # Diretórios dos arquivos fonte e objetos
# SRC_DIR = src
# OBJ_DIR = obj
# TEST_DIR = test
# INCLUDE_DIR = include

# # Arquivos fonte
# SRCS = $(wildcard $(SRC_DIR)/**/*.cpp) main.cpp
# OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# # Alvos
# TARGET = AgendaPDS2
# TEST_TARGET = test

# # Compilar tudo
# .PHONY: all
# all: build test run

# # Compilar aplicação principal
# .PHONY: build
# build: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# # Compilar testes
# .PHONY: test
# test: $(TEST_TARGET)
# 	./$(TEST_TARGET)

# $(TEST_TARGET): $(filter-out $(OBJ_DIR)/main.o, $(OBJS))
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# # Executar a aplicação
# .PHONY: run
# run: build
# 	./$(TARGET)

# # Compilar objetos
# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(INCLUDE_DIR)

# # Limpar arquivos temporários
# .PHONY: clean
# clean:
# 	rm -f $(OBJ_DIR)/*.o $(TARGET) $(TEST_TARGET)
# >>>>>>> 060eb6945b643ed0cf601fb903867b6bc924c781

alvo:
	g++ include/core/Calendario.hpp include/core/Excecoes.hpp include/core/Lembrete.hpp include/core/Notificacao.hpp include/core/Tarefa.hpp include/core/Usuario.hpp include/menu/Compromisso.hpp include/menu/Lembrete.hpp include/menu/Login.hpp include/menu/Menu.hpp include/menu/Tarefa.hpp include/menu/Usuario.hpp main.cpp -o a.exe
