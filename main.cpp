#include "../AgendaPDS2/include/menu/Menu.hpp"
#include "../AgendaPDS2/include/menu/Login.hpp"
#include "../AgendaPDS2/include/menu/Usuario.hpp"
#include "../AgendaPDS2/include/menu/Lembrete.hpp"
#include "../AgendaPDS2/include/menu/Compromisso.hpp"
#include "../AgendaPDS2/include/menu/Tarefa.hpp"

#include <iostream>

int main() {
  MenuLogin *login = new MenuLogin();
  login->renderizar();
  // renderiza a pagina do menu
  
  unsigned escolha;
  std::cin >> escolha;

  PrimeiroMenu *menu = login->next(escolha, nullptr);
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
