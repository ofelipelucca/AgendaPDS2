#include "Menu.hpp"

#include <iostream>

void PrimeiroMenu::renderizar() const {
  std::string border(titulo.size() + 5, '=');
  std::cout << border << '\n';
  std::cout << "|| " << titulo << "||" << '\n';
  std::cout << border << "\n\n";

  std::cout << segundotitulo << '\n' << '\n';

  for (std::string opt : opcoes) {
    std::cout << opt << '\n';
  }
  
  std::cout << border << "\n\n";
  
  std::cout << std::endl << "> Opções: ";
}