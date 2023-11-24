#pragma once

#include "Menu.hpp"
#include "UsuarioMenu.hpp"

#include <string>

class LembreteMenu : public PrimeiroMenu {
public:
  /// @brief Constroi o menu dos lembretes  
  LembreteMenu(std::string *login_email);

  /// @brief Constroi proximo menu 
  ///
  /// @return O proximo menu que o usuario escolheu
  PrimeiroMenu *next(unsigned option) override;
};