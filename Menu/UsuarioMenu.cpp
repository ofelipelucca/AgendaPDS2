#pragma once

#include "UsuarioMenu.hpp"
#include "LembreteMenu.hpp"
#include "CompromissoMenu.hpp"
#include "TarefaMenu.hpp"

#include <iostream>
#include <string>

UsuarioMenu::UsuarioMenu(std::string* user_nome, std::string* user_email) {
  
  setTitulo("Que bom ter voce de volta, " + *user_email + "!");
  setSubtitulo("Calendario da semana:");
  setOpcoes({"1 --> Compromissos", "2 --> Lembretes", "3 --> Tarefas"});
  setUsuario(*user_email);

  Calendario user_calendario;

  user_calendario.imprimirCalendario(); ///< Imprimindo o calendario da semana
}

PrimeiroMenu *UsuarioMenu::next(unsigned option) {

  switch (option) {
    case 1: {

      std::cout << std::endl << "Aqui estao seus lembretes salvos: " << std::endl; 
      
      ImprimirLembretes::verLembretes(&getUsuario());
      
      return new LembreteMenu(&getUsuario());
      ///vai para o menu dos lembretes (a criar)
      /// conferir se o parametro é o usuário mesmo
    }
    case 2: {

      std::cout << std::endl << "Aqui estao seus compromissos salvos: " << std::endl;
      
      ImprimirCompromissos::verCompromissos(&getUsuario());
      
      return new CompromissoMenu(&getUsuario());
      ///vai para o menu dos Compromissos (a criar)
      /// conferir se o parametro é o usuário mesmo
    }
    case 3: {

      std::cout << std::endl << "Aqui estao suas tarefas salvas: " << std::endl;
      
      ImprimirTarefas::verTarefas(&getUsuario());

      return new TarefaMenu(&getUsuario());
      ///vai para o menu das Tarefas (a criar) 
      /// conferir se o parametro é o usuário mesmo
    }
  }

  // TODO: próximo menu
  return nullptr;
}
