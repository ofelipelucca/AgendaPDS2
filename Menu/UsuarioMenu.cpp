#pragma once

#include "UsuarioMenu.hpp"

#include <iostream>
#include <string>


UsuarioMenu::UsuarioMenu() {
  opcoes.push_back("1 --> Lembretes");
  opcoes.push_back("2 --> Compromissos");
  opcoes.push_back("3 --> Tarefas");
}

PrimeiroMenu *UsuarioMenu::next(unsigned option) {
  switch (option) {
  case 1: {
    
    imprimirCalendario();
    //imprime o calendario da semana 

    std::cout << '\n' '\n' << "Aqui estão seus lembretes: " << std::endl;
    std::cout << '\n' << verLembretes() << std::endl;
    // imprime os lembretes atuais 
    
    ///...
     
    return new LembreteMenu();
    ///vai para o menu dos lembretes (a criar)
    /// conferir se o parametro é o usuário mesmo
  }
  case 2: {
    imprimirCalendario();
    //imprime o calendario da semana 

    std::cout << '\n' '\n' << "Aqui estão seus Compromissos: " << std::endl;
    std::cout <<'\n' << verCompromissos() << std::endl;
    /// imprime os Compromissos atuais 
    
    ///...
     
    return new CompromissoMenu();
    ///vai para o menu dos Compromissos (a criar)
    /// conferir se o parametro é o usuário mesmo
  }
  case 3: {
    imprimirCalendario();
    //imprime o calendario da semana 

    std::cout << '\n' << "Aqui estão suas Tarefas: " << std::endl;
    std::cout << '\n' << verTarefas() << std::endl;
    /// imprime as Tarefas atuais 
    
    ///...
     return new TarefaMenu();
    ///vai para o menu das Tarefas (a criar) 
    /// conferir se o parametro é o usuário mesmo
  }
  }

  // TODO: próximo menu
  return nullptr;
}
