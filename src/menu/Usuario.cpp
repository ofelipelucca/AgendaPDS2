#pragma once

#include "../include/menu/Usuario.hpp"
#include "../include/menu/Lembrete.hpp"
#include "../include/menu/Compromisso.hpp"
#include "../include/menu/Tarefa.hpp"

#include <iostream>
#include <string>
#include <ctime>

#define STRING(num) #num

UsuarioMenu::UsuarioMenu(std::string* user_email) {
  
  setTitulo("Que bom ter voce de volta, " + *user_email + "!");
  setSubtitulo("Calendario da semana:");
  setOpcoes({"1 --> Lembretes", "2 --> Compromissos", "3 --> Tarefas", "4 --> Deslogar", "5 --> Sair"});
  setUsuario(*user_email);

  Calendario user_calendario;

  // Pega a data atual do computador do usuario
  std::time_t t = std::time(nullptr);
  std::tm* now = std::localtime(&t);

  // Transforma em uma string no formato: DD/MM/AAAA
  std::string dia = STRING(now->tm_mday);
  dia += '/';
  dia += STRING(now->tm_mon + 1);
  dia += '/';
  dia += STRING(now->tm_year + 1900);

  user_calendario.imprimirCalendario(dia); ///< Imprimindo o calendario da semana
}

PrimeiroMenu *UsuarioMenu::next(unsigned option, PrimeiroMenu *old_menu) {

  switch (option) {
    case 1: {

      std::cout << std::endl << "Aqui estao seus lembretes salvos: " << std::endl; 
      
      ImprimirLembretes::verLembretes(&getUsuario());
      
      return new LembreteMenu(&getUsuario());
    }

    case 2: {

      std::cout << std::endl << "Aqui estao seus compromissos salvos: " << std::endl;
      
      ImprimirCompromissos::verCompromissos(&getUsuario());
      
      return new CompromissoMenu(&getUsuario());
    }

    case 3: {

      std::cout << std::endl << "Aqui estao suas tarefas salvas: " << std::endl;
      
      ImprimirTarefas::verTarefas(&getUsuario());

      return new TarefaMenu(&getUsuario());
    }

    case 4: {
      
      std::cout << "Voltando..." << std::endl;
      return old_menu;
    }

    case 5: {
      
      std::cout << "Saindo do progama..." << std::endl;
      return nullptr;
    }

    default: {

      std::cout << "Opcao invalida!" << std::endl;
      std::cout << "Escolha uma opcao valida!" << std::endl;
      return new UsuarioMenu(&getUsuario());
    }
  }
}
