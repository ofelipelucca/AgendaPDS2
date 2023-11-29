#pragma once

#include "Menu.hpp"
#include "UsuarioMenu.hpp"

#include <string>

class LembreteMenu : public PrimeiroMenu {
public:
  /// @brief Constroi o menu dos lembretes  
  LembreteMenu(std::string *login_email);

  /// @brief Constroi o proximo menu
  ///
  /// @param opcao A opção que o usuário escolheu
  ///
  /// @param old_menu Um ponteiro que aponta para o menu anterior
  ///
  /// @return Um ponteiro para o próximo menu
  PrimeiroMenu *next(unsigned option, PrimeiroMenu *old_menu) override;
};
