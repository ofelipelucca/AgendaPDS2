#pragma once

#include "UsuarioMenu.hpp"

#include <iostream>
#include <string>

UsuarioMenu::UsuarioMenu(std::string* user_nome, std::string* user_email) {
  
  setTitulo("Que bom ter voce de volta, " + *user_email);
  setSubtitulo("Calendario da semana:");
  setOpcoes({"1 --> Compromissos", "2 --> Lembretes", "3 --> Tarefas"});
  setUsuario(*user_email);
}

PrimeiroMenu *UsuarioMenu::next(unsigned option) {
  switch (option) {
  case 1: {
    
    imprimirCalendario();
    //imprime o calendario da semana 

    std::cout << '\n' '\n' << "Aqui estão seus lembretes: " << std::endl;
    std::cout << '\n' << ListaLembrete::verLembretes(getUsuario()) << std::endl;
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
