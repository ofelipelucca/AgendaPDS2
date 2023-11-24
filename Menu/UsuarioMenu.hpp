#pragma once
#include "LoginMenu.hpp"
#include "Menu.hpp"
#include "Usuario.hpp"
#include "Tarefa.hpp"
#include "Lembrete.hpp"
#include "Calendario.hpp"

#include <string>

class UsuarioMenu : public PrimeiroMenu {
public:
  /// @brief Constrói um menu do Usuário.  
  UsuarioMenu();

  /// @brief Constrói próximo menu 
  ///
  /// @return O próximo menu que o usuario escolheu.
  PrimeiroMenu *next(unsigned option) override;
};
