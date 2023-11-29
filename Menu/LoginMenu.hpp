#pragma once

#include "Menu.hpp"
#include "UsuarioMenu.hpp"
#include "../Usuario/Usuario.hpp"

class MenuLogin : public PrimeiroMenu {
public:
  /// @brief Constroi o menu de login
  MenuLogin();

  /// @brief Constroi o proximo menu 
  ///
  /// @return O proximo menu que o usuario escolheu.
  PrimeiroMenu *next(unsigned opcao, PrimeiroMenu *old_menu) override;
};
