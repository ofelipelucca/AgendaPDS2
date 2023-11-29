#include "Menu.hpp"
#include "LoginMenu.hpp"
#include "UsuarioMenu.hpp"
#include "../Usuario/Usuario.hpp"

#include <iostream>
#include <string>

MenuLogin::MenuLogin() {

  setTitulo("Seja bem-vindo ao Gerenciador de Tarefas! ");
  setSubtitulo("Escolha uma opcao:");
  setOpcoes({"1 --> Fazer login", "2 --> Fazer novo cadastro", "3 --> Sair do programa"});
}

PrimeiroMenu *MenuLogin::next(unsigned option) {
  
  switch (option) {
    case 1: {

      std::string login_email;
      std::cout << std::endl << "> Digite seu email: ";
      std::cin >> login_email;

      std::string login_nome;
      std::cout << "> Digite seu nome: ";
      std::cin >> login_nome;

      std::cout << "Fazendo login..." << std::endl << std::endl;

      /// Verifica se o usuario esta cadastrado no sistema com o email e nome fornecidos
      if (Usuario::checkUsuario(&login_email, &login_nome)) { 
        
        std::cout << "Logado com sucesso em: " << login_nome << " (" << login_email << ")!" << std::endl;
        
        return new UsuarioMenu(&login_email);
      }
      else {
        std::cout << "Usuario nao encontrado!" << std::endl << std::endl;
        std::cout << "Ainda nao possui uma conta? Seleciona a opcao 2 para criar um novo cadastro." << std::endl << std::endl;
        
        return new MenuLogin();
      }
    }
    
    case 2: {

      std::string register_email;
      std::cout << "> Insira o seu email: ";
      std::cin >> register_email;

      std::string register_nome;
      std::cout << "> Insira o seu primeiro nome: ";
      std::cin >> register_nome;
      
      std::string register_sobrenome;
      std::cout << "> Insira o seu sobrenome: ";
      std::cin >> register_sobrenome;

      std::string register_idade;
      std::cout << "> Insira a sua idade: ";
      std::cin >> register_idade;

      if (ListaUsuario::checkUsuario(&register_email)) {

        std::cout << "O email informado ja esta cadastrado, favor inserir outro!" << std::endl << std::endl;
        std::cout << "Se deseja acessar a plataforma, selecione a opcao 1." << std::endl << std::endl;

        return new MenuLogin();
      } else {

        std::cout << "Cadastrando usuario..." << std::endl;

        Usuario* new_user = new Usuario(register_nome, register_sobrenome, register_idade, register_email);
        
        ListaUsuario::adicionarUsuario(new_user);

        if (ListaUsuario::checkUsuario(&register_email, &register_nome)) {
          
          std::cout << "Usuario " << register_nome << " (" << register_email << ") cadastrado com sucesso!" << std::endl;
          
          return new UsuarioMenu(&getUsuario());
        }
        else {

          std::cout << "Nao foi possivel cadastrar o novo usuario!" << std::endl;

          return new MenuLogin();
        }
      }
    }

    case 3: {

      std::cout << "Saindo do programa..." <<  std::endl;
      return nullptr;
    }

    default: {

      std::cout << "Opcao invalida!" << std::endl;
      std::cout << "Escolha uma opcao valida!" << std::endl;
      return new MenuLogin();
    }
  }
}