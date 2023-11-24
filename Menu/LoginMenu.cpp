#include "Menu.hpp"
#include "LoginMenu.hpp"
#include "UsuarioMenu.hpp"
#include "../Usuario/Usuario.hpp"

#include <iostream>
#include <string>

MenuLogin::MenuLogin() {
  _opcoes.push_back("1 --> Entrar");
  _opcoes.push_back("2 --> Cadastrar Usuario");
}

PrimeiroMenu *MenuLogin::next(unsigned option) {
  
  switch (option) {
    
    case 1: {

      std::string login_email;
      std::cout << "> Digite seu email: ";
      std::cin >> login_email;

      std::string login_nome;
      std::cout << "> Digite seu nome: ";
      std::cin >> login_nome;

      /// Verifica se o usuario esta cadastrado no sistema com o email e nome fornecidos
      ListaUsuario user_login;
      
      if (user_login.checkUsuario(&login_email, &login_nome)) { 
        
        std::cout << "Logando em: " << login_nome << " (" << login_email << ")" << std::endl; 
        
        return new UsuarioMenu();
      }
      else {

        /// @todo Tratar o erro de login caso o usuario nao esteja registrado ainda (lançar exception e retornar para o menu login)
      }
    }
    
    case 2: {

      std::string register_email;
      std::string register_nome;
      std::string register_sobrenome;
      std::string register_idade; 

      std::cout << "> Insira o seu email: ";
      std::cin >> register_email;

      std::cout << "> Insira o seu primeiro nome: ";
      std::cin >> register_nome;
      
      std::cout << "> Insira o seu sobrenome: ";
      std::cin >> register_sobrenome;

      std::cout << "> Insira a sua idade: ";
      std::cin >> register_idade; 

      std::cout << "Cadastrando usuario..." << std::endl;

      Usuario* new_user = new Usuario(register_nome, register_sobrenome, register_idade, register_email);

      ListaUsuario new_user_register;

      new_user_register.adicionarUsuario(new_user);

      if (new_user_register.checkUsuario(&register_email, &register_nome)) {
        
        std::cout << "Usuario " << register_nome << " (" << register_email << ") cadastrado com sucesso!" << std::endl;
        
        return new UsuarioMenu();
      }
      else {

        /// @todo Nao foi possivel cadastrar o novo usuario, retornar para o menu login
      }
    }
  }

  /// @todo menu anterior
  return ;
}