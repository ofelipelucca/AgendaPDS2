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
  /// @return O proximo menu que o usuario escolheu.
  PrimeiroMenu *next(unsigned option) override;
};