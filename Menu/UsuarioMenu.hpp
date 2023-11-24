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
  /// @brief Constrói um menu do Usuário.  
  UsuarioMenu(std::string *login_nome, std::string *login_email);

  /// @brief Constrói próximo menu 
  ///
  /// @return O próximo menu que o usuario escolheu.
  PrimeiroMenu *next(unsigned option) override;
};
