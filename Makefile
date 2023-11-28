Certifique-se de ajustar os caminhos e flags de compilação conforme necessário para o seu ambiente.
Para usar o Makefile, basta executar os comandos make build, make test ou make run no terminal. Certifique-se de ter o g++ instalado em seu sistema.
Este Makefile assume que você tem a seguinte estrutura de diretórios:
- AgendaPDS2
  - src
    - Calendario
      - Calendario.cpp
      - Calendario.hpp
      - teste_Calendario.cpp
    - Exceções
      - Exceções.cpp
      - Exceções.hpp
    - Lembrete
      - Lembrete.cpp
      - Lembrete.hpp
      - teste_Lembrete.cpp
    - Menu
      - ...
    - Notificação
      - Notificação.cpp
      - Notificação.hpp
      - teste_Notificação.cpp
    - Tarefa
      - Tarefa.cpp
      - Tarefa.hpp
      - teste_Tarefa.cpp
    - Usuario
      - teste_Usuario.cpp
      - Usuario.cpp
      - Usuario.hpp
  - obj
  - Makefile
-----------------------------------------------------------------------------------------------------------------------------------------------------------


# Configurações do compilador
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Diretórios dos arquivos fonte e objetos
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Alvos
TARGET = AgendaPDS2
TEST_TARGET = test

# Compilar tudo
.PHONY: all
all: build test run

# Compilar aplicação principal
.PHONY: build
build: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar testes
.PHONY: test
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(filter-out $(OBJ_DIR)/main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) -o $@ $^

# Executar a aplicação
.PHONY: run
run: build
	./$(TARGET)

# Compilar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpar arquivos temporários
.PHONY: clean
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET) $(TEST_TARGET)
