#include "../include/menu/Menu.hpp"

#include <iostream>

std::string PrimeiroMenu::getUsuario() const {

  return this->_user_email;
} 

void PrimeiroMenu::setUsuario(std::string user_email) {

  this->_user_email = user_email;
}

void PrimeiroMenu::setTitulo(std::string novoTitulo) {
  
  this->_titulo = novoTitulo;
}

void PrimeiroMenu::setSubtitulo(std::string novoSubstitulo) {

  this->_sub_titulo = novoSubstitulo;
}

void PrimeiroMenu::setOpcoes(std::vector<std::string> novasOpcoes) {

  this->_opcoes = novasOpcoes;
}

void PrimeiroMenu::renderizar() const {

  std::string border(_titulo.size() + 5, '=');
  std::cout << border << '\n';
  std::cout << "|| " << _titulo << "||" << '\n';
  std::cout << border << "\n\n";

  std::cout << _sub_titulo << '\n' << '\n';

  for (std::string opt : _opcoes) {
    
    std::cout << opt << '\n';
  }
  
  std::cout << border << "\n\n";
  
  std::cout << std::endl << "> Escolha: ";
}
