#include "Menu.hpp"

#include <iostream>

void PrimeiroMenu::setTitulo(std::string novoTitulo) {
  
  this->_titulo = novoTitulo;
}

void PrimeiroMenu::setSubtitulo(std::string novoSubstitulo) {

  this->_subtitulo = novoSubstitulo;
}

void PrimeiroMenu::setOpcoes(std::vector<std::string> novasOpcoes) {

  this->_opcoes = novasOpcoes;
}

void PrimeiroMenu::renderizar() const {

  std::string border(_titulo.size() + 5, '=');
  std::cout << border << '\n';
  std::cout << "|| " << _titulo << "||" << '\n';
  std::cout << border << "\n\n";

  std::cout << _subtitulo << '\n' << '\n';

  for (std::string opt : _opcoes) {
    
    std::cout << opt << '\n';
  }
  
  std::cout << border << "\n\n";
  
  std::cout << std::endl << "> Escolha: ";
}