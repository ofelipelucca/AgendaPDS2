Certifique-se de ajustar os caminhos e flags de compilação conforme necessário para o seu ambiente.
Para usar o Makefile, basta executar os comandos make build, make test ou make run no terminal. Certifique-se de ter o g++ instalado em seu sistema.
Este Makefile assume que você tem a seguinte estrutura de diretórios:

- AgendaPDS2
  - .vscode
    - settings.json
  - doc
    - Doxyfile
      - html
        - //arquivos de documentação 
      
      - rtf 
        - //arquivos de documentação

    - Cartoes CRC.pdf
  - include
    - core
      - Calendario.hpp
      - Excecoes.hpp
      - Lembrete.hpp
      - Notificacao.hpp
      - Tarefa.hpp
      - Usuario.hpp
    - menu
      - Compromisso.hpp
      - Lembrete.hpp
      - Login.hpp
      - Menu
      - Tarefa.hpp
      - Usuario.hpp

  - src
   - core
      - Calendario.cpp
      - Excecoes.cpp
      - Lembrete.cpp
      - Notificacao.cpp
      - Tarefa.cpp
      - Usuario.cpp
    - menu
      - Compromisso.cpp
      - Lembrete.cpp
      - Login.cpp
      - Menu.cpp
      - Tarefa.cpp
      - Usuario.cpp
  - test
    - core
      - Calendario.cpp
      - Lembrete.hpp
      - Notificacao.hpp
      - Tarefa.hpp
      - Usuario.hpp

    - storage
      - doctest.hpp
      - driver.cpp
  - main.cpp
  - Makefile
  - README.md
-----------------------------------------------------------------------------------------------------------------------------------------------------------


# Configurações do compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

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
