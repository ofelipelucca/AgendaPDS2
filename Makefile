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


# Makefile para AgendaPDS2

# Compilador
CXX := g++
# Opções de compilação
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude

# Diretórios
SRCDIR := src
INCDIR := include
TESTDIR := test
BUILDDIR := build
BINDIR := bin

# Arquivos fonte
SOURCES := $(wildcard $(SRCDIR)/*/*.cpp)
TESTSOURCES := $(wildcard $(TESTDIR)/*/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
TESTOBJECTS := $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%_test.o,$(TESTSOURCES))
EXECUTABLE := $(BINDIR)/agenda

# Comando padrão
default: build

# Regras de compilação
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/%_test.o: $(TESTDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regras de construção
build: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Regras de teste
test: CXXFLAGS += -I$(TESTDIR)
test: $(TESTOBJECTS) $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(TESTOBJECTS) $(OBJECTS) -o $(EXECUTABLE)_test
	./$(EXECUTABLE)_test

# Regras de execução
run: build
	./$(EXECUTABLE)

# Limpeza
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: build test run clean