#pragma once

#include "LoginMenu.hpp"
#include "Menu.hpp"
#include "../Usuario/Usuario.hpp"
#include "../Tarefa/Tarefa.hpp"
#include "../Lembrete/Lembrete.hpp"
#include "../Calendario/Calendario.hpp"

#include <string>

class UsuarioMenu : public PrimeiroMenu {
public:
  /// @brief Constroi o menu do usuario.  
  UsuarioMenu(std::string *login_email);

  /// @brief Constroi o proximo menu
  ///
  /// @param opcao A opção que o usuário escolheu
  ///
  /// @param old_menu Um ponteiro que aponta para o menu anterior
  ///
  /// @return Um ponteiro para o próximo menu
  PrimeiroMenu *next(unsigned option, PrimeiroMenu *old_menu) override;
};
