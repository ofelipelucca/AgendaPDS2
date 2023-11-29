#pragma once

#include "../Lembrete/Lembrete.hpp"
#include "UsuarioMenu.hpp"
#include "LembreteMenu.hpp"
#include "CompromissoMenu.hpp"
#include "TarefaMenu.hpp"

#include <iostream>
#include <string>

LembreteMenu::LembreteMenu(std::string* user_email) {
  
  setTitulo("Menu de Lembretes! ");
  setSubtitulo("Escolha uma opçao:");
  setOpcoes({"1 --> Adicionar um novo lembrete", "2 --> Remover um lembrete", "3 --> Editar um lembrete", "4 --> Voltar", "5 --> Sair"});
  setUsuario(*user_email);
}

PrimeiroMenu *LembreteMenu::next(unsigned option, PrimeiroMenu *old_menu) {
  
  switch (option) {
    case 1: {

        std::string novo_lembrete_data;
        std::cout << "Insira uma data para seu lembrete" << std::endl;
        std::cin >> novo_lembrete_data;

        std::string novo_lembrete_horario;
        std::cout << "Insira um horario para seu lembrete" << std::endl;
        std::cin >> novo_lembrete_horario;

        std::string novo_lembrete_mensagem;
        std::cout << "Insira uma mensagem para seu lembrete" << std::endl;
        std::cin >> novo_lembrete_mensagem;

        std::cout << "Adicionando lembrete..." << std::endl;

        Lembrete* new_lembrete = new Lembrete(novo_lembrete_horario, novo_lembrete_mensagem, novo_lembrete_data);

        ListaLembrete::adicionarLembrete(new_lembrete, &getUsuario());

        if (ListaLembrete::buscarLembrete(&novo_lembrete_mensagem) != nullptr) {

            std::cout << "O lembrete foi adicionado com sucesso!" << std::endl;
        }
        else {

            std::cout << "Nao foi possivel adicionar o novo lembrete." << std::endl;
        }
        
        return new LembreteMenu(&getUsuario());
    }
    case 2: {

        std::string mensagem_lembrete;
        std::cout << std::endl << "Digite a mensagem do lembrete que deseja remover: " << std::endl;
        std::cin >> mensagem_lembrete;

        std::cout << "Buscando por lembrete..." << std::endl;
        
        Lembrete* lembrete = ListaLembrete::buscarLembrete(&mensagem_lembrete);

        if (lembrete != nullptr) {

            ListaLembrete::removerLembrete(lembrete, &getUsuario()); ///< Removendo o lembrete

            std::cout << "O lembrete com mensagem '" << mensagem_lembrete << "' foi removido com sucesso!" << std::endl;
        }
        else {

            std::cout << "O lembrete com mensagem '" << mensagem_lembrete << "' nao foi encontrado." << std::endl;
        }

        return new LembreteMenu(&getUsuario());
    }
    case 3: {

        std::string mensagem_lembrete;
        std::cout << std::endl << "Digite a mensagem do lembrete que deseja editar: " << std::endl;
        std::cin >> mensagem_lembrete;

        std::cout << "Buscando por lembrete..." << std::endl;
        
        Lembrete* lembrete = ListaLembrete::buscarLembrete(&mensagem_lembrete);

        if (lembrete != nullptr) {

            std::cout << "Alterando o lembrete..." << std::endl
            << "Mensagem: " << lembrete->getMensagem() << std::endl
            << "Data: " << lembrete->getData() << std::endl
            << "Horario: " << lembrete->getHorario() << std::endl;
            
            std::cout << std::endl << "Voce deseja..." << std::endl
            << "1 --> Editar mensagem" << std::endl
            << "2 --> Editar data" << std::endl
            << "3 --> Editar horario" << std::endl;

            unsigned opcao_editar;

            switch (opcao_editar) {
                case 1: {

                    std::string nova_mensagem;
                    std::cout << "Digite uma nova mensagem para o lembrete:" << std::endl;
                    std::cin >> nova_mensagem;

                    std::cout << "Alterando mensagem...";

                    lembrete->setMensagem(nova_mensagem);

                    Lembrete* lembrete_alterado = ListaLembrete::buscarLembrete(&nova_mensagem);  

                    if (lembrete_alterado != nullptr && lembrete_alterado->getData() == lembrete->getData() && lembrete_alterado->getHorario() == lembrete->getHorario()) {

                        std::cout << "A mensagem do lembrete foi alterada com sucesso para: " << lembrete->getMensagem() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar a mensagem do lembrete." << std::endl;
                    }
                }
                case 2: {

                    std::string nova_data;
                    std::cout << "Digite uma nova data para o lembrete (no formato: DD/MM/AAAA):" << std::endl;
                    std::cin >> nova_data;

                    std::cout << "Alterando data...";

                    lembrete->setData(nova_data);  

                    if (lembrete->getData() == nova_data) {

                        std::cout << "A data do lembrete foi alterada com sucesso para: " << lembrete->getData() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar a data do lembrete." << std::endl;
                    }
                }
                case 3: {

                    std::string novo_horario;
                    std::cout << "Digite um novo horario para o lembrete (no formato: HH:MM:SS):" << std::endl;
                    std::cin >> novo_horario;

                    std::cout << "Alterando horario...";

                    lembrete->setHorario(novo_horario);  

                    if (lembrete->getHorario() == novo_horario) {

                        std::cout << "O horario do lembrete foi alterado com sucesso para: " << lembrete->getHorario() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar o horario do lembrete." << std::endl;
                    }
                }
            } 
        }
        else {

            std::cout << "O lembrete com mensagem '" << mensagem_lembrete << "' nao foi encontrado." << std::endl;
        }

        return new LembreteMenu(&getUsuario());
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
        return new LembreteMenu(&getUsuario());
    }
  }
}