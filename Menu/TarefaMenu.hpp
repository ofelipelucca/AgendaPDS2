#pragma once

#include "Menu.hpp"
#include "UsuarioMenu.hpp"

#include <string>

class TarefaMenu : public PrimeiroMenu {
public:
  /// @brief Constroi o menu das tarefas  
  TarefaMenu(std::string *login_email);

  /// @brief Constroi próximo menu 
  ///
/// @return O proximo menu que o usuario escolheu
  PrimeiroMenu *next(unsigned option) override;
};