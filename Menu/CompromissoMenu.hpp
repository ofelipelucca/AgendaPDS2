#pragma once

#include "Menu.hpp"
#include "UsuarioMenu.hpp"

#include <string>

class CompromissoMenu : public PrimeiroMenu {
public:
  /// @brief Constroi o menu dos compromissos  
  CompromissoMenu(std::string *login_email);

  /// @brief Constroi proximo menu 
  ///
  /// @return O proximo menu que o usuario escolheu
  PrimeiroMenu *next(unsigned option) override;
};