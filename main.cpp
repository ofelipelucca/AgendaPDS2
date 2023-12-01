#include "../include/menu/Menu.hpp"
#include "../include/menu/Login.hpp"
#include "../include/menu/Usuario.hpp"
#include "../include/menu/Lembrete.hpp"
#include "../include/menu/Compromisso.hpp"
#include "../include/menu/Tarefa.hpp"

#include <iostream>

int main() {
  MenuLogin login;
  login.renderizar();
  // renderiza a pagina do menu
  
  unsigned escolha;
  std::cin >> escolha;

  PrimeiroMenu *menu = login.next(escolha, nullptr);
  //pega a escolha do usuário e atribue a função

  while (menu != nullptr) {
    menu->renderizar();
    std::cin >> escolha;

    PrimeiroMenu *old_menu = menu;
    menu = menu->next(escolha, old_menu);

    delete old_menu;
  }
  
  return 0;
}
