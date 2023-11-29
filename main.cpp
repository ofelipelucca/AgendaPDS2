#include "Menu.hpp"
#include "LoginMenu.hpp"
#include "UsuarioMenu.hpp"
#include "LembreteMenu.hpp"
#include "CompromissoMenu.hpp"
#include "TarefaMenu.hpp"

#include <iostream>

int main() {
  
  MenuLogin login;
  login.renderizar();
  // renderiza a pagina do menu
  
  unsigned escolha;
  std::cin >> escolha;

  PrimeiroMenu *menu = login.next(escolha);
  //pega a escolha do usuário e atribue a função

  while (menu != nullptr) {
  menu->renderizar();
  std::cin >> escolha;

  Menu *old_menu = menu;
  menu = menu->next(escolha);

  delete old_menu;
}
  

  return 0;
}
