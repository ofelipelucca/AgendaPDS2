#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "Menu.hpp"
#include "Usuario.hpp"
#include "../core/Usuario.hpp"

class MenuLogin : public PrimeiroMenu {
public:
  /// @brief Constroi o menu de login
  MenuLogin();

  /// @brief Constroi o proximo menu
  ///
  /// @param opcao A opção que o usuário escolheu
  ///
  /// @param old_menu Um ponteiro que aponta para o menu anterior
  ///
  /// @return Um ponteiro para o próximo menu
  PrimeiroMenu *next(unsigned opcao, PrimeiroMenu *old_menu) override;
};

#endif