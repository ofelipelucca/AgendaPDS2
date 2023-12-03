#include "../include/core/Usuario.hpp"
#include "../include/menu/Usuario.hpp"
#include "../include/menu/Tarefa.hpp"
#include "../include/menu/Lembrete.hpp"
#include "../include/menu/Compromisso.hpp"

#include <iostream>
#include <string>

TarefaMenu::TarefaMenu(std::string *login_email) {

  setTitulo("Menu de Tarefas! ");
  setSubtitulo("Escolha uma opçao:");
  setOpcoes({"1 --> Adicionar um nova Tarefa", "2 --> Remover um Tarefa", "3 --> Editar uma Tarefa", "4 --> Voltar", "5 --> Sair"});
  setUsuario(*login_email);
}

PrimeiroMenu *TarefaMenu::next(unsigned option, PrimeiroMenu *old_menu) {
  
    std::string usuario_atual = getUsuario();

  switch (option) {
    
    case 1: {
        
        std::string nova_tarefa_titulo;
        std::cout << "Insira um título para sua Tarefa" << std::endl;
        std::cin >> nova_tarefa_titulo;

        std::string nova_tarefa_descricao;
        std::cout << "Insira uma descricao para sua Tarefa" << std::endl;
        std::cin >> nova_tarefa_descricao;

        std::string nova_tarefa_data;
        std::cout << "Insira uma data para sua Tarefa no formato DD/MM/AAA" << std::endl;
        std::cin >> nova_tarefa_data;

        unsigned nova_tarefa_prioridade;
        std::cout << "Insira uma prioridade para sua Tarefa: " << std::endl;
        std::cout << "1 --> menos importante, 2 --> importante, 3 --> muito importante" << std::endl;
        std::cin >> nova_tarefa_prioridade;

        std::string nova_tarefa_estado;
        std::cout << "Insira um estado para sua Tarefa: " << std::endl;
        std::cout << "feito , em progresso, não feito " << std::endl;
        std::cin >> nova_tarefa_estado;
        
        std::cout << "Adicionando Tarefa..." << std::endl;

        Tarefa* new_Tarefa = new Tarefa(nova_tarefa_titulo, nova_tarefa_descricao, nova_tarefa_data, nova_tarefa_prioridade, nova_tarefa_estado );

        ListaTarefa::adicionarTarefa(new_Tarefa, &usuario_atual);

        // não achei uma função dessa para Tarefa
        if (ListaTarefa::buscarTarefa(nova_tarefa_titulo) != nullptr) {

            std::cout << "A Tarefa adicionada com sucesso!" << std::endl;
        }
        else {

            std::cout << "Nao foi possivel adicionar A nova Tarefa." << std::endl;
        }
        
        return new TarefaMenu(&usuario_atual);
    }
    case 2: {

        std::string titulo_Tarefa;
        std::cout << std::endl << "Digite o título da Tarefa que deseja remover: " << std::endl;
        std::cin >> titulo_Tarefa;

        std::cout << "Buscando pela Tarefa..." << std::endl;
        
        //precisa criar a função a baixo
        Tarefa* tarefa = ListaTarefa::buscarTarefa(titulo_Tarefa);

        if (tarefa != nullptr) {

            ListaTarefa::removerTarefa(tarefa, &usuario_atual); ///< Removendo a Tarefa

            std::cout << "A Tarefa com Título '" << titulo_Tarefa << "' foi removida com sucesso!" << std::endl;
        }
        else {

            std::cout << "A Tarefa com Título '" << titulo_Tarefa << "' nao foi encontrada." << std::endl;
        }

        return new TarefaMenu(&usuario_atual);
    }
    case 3: {

        std::string titulo_Tarefa;
        std::cout << std::endl << "Digite o título da Tarefa que deseja editar: " << std::endl;
        std::cin >> titulo_Tarefa;

        std::cout << "Buscando pela Tarefa..." << std::endl;
        
        Tarefa* tarefa = ListaTarefa::buscarTarefa(titulo_Tarefa);

        if (tarefa != nullptr) {

            std::cout << "Alterando a Tarefa..." << std::endl
            << "Título: " << tarefa->getTitulo() << std::endl
            << "Descricao: " << tarefa->getDescricao() << std::endl
            << "Data: " << tarefa->getData() << std::endl
            << "Prioridade: " << tarefa->getPrioridade() << std::endl
            << "Estado: " << tarefa->getEstado() << std::endl;
            
            std::cout << std::endl << "Voce deseja..." << std::endl
            << "1 --> Editar Título" << std::endl
            << "2 --> Editar Descricao" << std::endl
            << "3 --> Editar Data" << std::endl
            << "4 --> Editar Prioridade" << std::endl
            << "5 --> Editar Estado" << std::endl;

            unsigned opcao_editar;

            switch (opcao_editar) {
                case 1: {

                    std::string novo_titulo;
                    std::cout << "Digite um novo Título pata a Tarefa:" << std::endl;
                    std::cin >> novo_titulo;

                    std::cout << "Alterando Título...";

                    tarefa->setTitulo(novo_titulo);

                    Tarefa* tarefa_alterado = ListaTarefa::buscarTarefa(novo_titulo);  

                    if (tarefa_alterado != nullptr && tarefa_alterado->getData() == tarefa->getData() && tarefa_alterado->getDescricao() == tarefa->getDescricao()) {

                        std::cout << "O Título da tarefa foi alterado com sucesso para: " << tarefa->getTitulo() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar o Título da tarefa." << std::endl;
                    }
                }
                case 3: {

                    std::string nova_data;
                    std::cout << "Digite uma nova data para a tarefa (no formato: DD/MM/AAAA):" << std::endl;
                    std::cin >> nova_data;

                    std::cout << "Alterando data...";

                    tarefa->setData(nova_data);  

                    if (tarefa->getData() == nova_data) {

                        std::cout << "A data da tarefa foi alterada com sucesso para: " << tarefa->getData() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar a data da tarefa." << std::endl;
                    }
                }
                case 2: {

                    std::string novo_descricao;
                    std::cout << "Digite uma nova Descricao pata a Tarefa:" << std::endl;
                    std::cin >> novo_descricao;

                    std::cout << "Alterando Descricao...";

                    tarefa->setDescricao(novo_descricao);  

                    if (tarefa->getDescricao() == novo_descricao) {

                        std::cout << "A Descricao da tarefa foi alterada com sucesso para: " << tarefa->getDescricao() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar a Descricao da tarefa." << std::endl;
                    }
                }

                case 4: { 
                    unsigned nova_prioridade;
                    std::cout << "Digite a nova prioridade da tarefa entre:" << std::endl;
                    std::cout << "'1 --> menos importante, 2 --> importante, 3 --> muito importante'" << std:: endl;
                    std::cin >> nova_prioridade;

                    std::cout << "Alterando prioridade...";

                    tarefa->setPrioridade(nova_prioridade);  

                    if (tarefa->getPrioridade() == nova_prioridade) {
                     
                     std::cout << "A prioridade da tarefa foi alterada com sucesso para: " << tarefa->getPrioridade() << "!" << std::endl;
                    
                    }
                    else {

                        std::cout << "Nao foi possivel alterar a prioridade da tarefa." << std::endl;
                    }
                }

                case 5: { 
                    std::string nova_estado;
                    std::cout << "Digite uma novo estado para a tarefa entre : " << std::endl;
                    std::cout << "'feito , em progresso, não feito' " << std::endl;
                    std::cin >> nova_estado;

                    std::cout << "Alterando estado...";

                    tarefa->setEstado(nova_estado);
 

                    if (tarefa->getEstado() == nova_estado) {

                        std::cout << "O esatado da tarefa foi alterado com sucesso para: " << tarefa->getEstado() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar o estado da tarefa." << std::endl;
                    }
                }
            } 
        }
        else {

            std::cout << "A tarefa com Título '" << titulo_Tarefa << "' nao foi encontrada." << std::endl;
        }

        return new TarefaMenu(&usuario_atual);
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
        return new TarefaMenu(&usuario_atual);
    }
  }
}
