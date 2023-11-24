#pragma once

#include "Menu.hpp"
#include "UsuarioMenu.hpp"
#include "../Usuario/Usuario.hpp"

class MenuLogin : public PrimeiroMenu {
public:
  /// @brief Constrói um menu de login.
  MenuLogin();

  /// @brief Constrói próximo menu 
  ///
  /// @return O próximo menu que o usuario escolheu.
  PrimeiroMenu *next(unsigned opcao) override;
};
