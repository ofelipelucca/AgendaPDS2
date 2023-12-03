#include "../include/menu/Compromisso.hpp"

#include <iostream>

// Implementação dos métodos da classe CompromissoMenu

CompromissoMenu::CompromissoMenu(std::string *login_email) {
    
    setTitulo("Menu de Compromissos");
    setSubtitulo("Escolha uma opção:");
    setOpcoes({"1 --> Adicionar novo Compromisso", "2 --> Remover Compromisso", "5 --> Editar Compromisso " "4 --> Voltar", "5 --> Sair"});
    setUsuario(*login_email);
}

PrimeiroMenu *CompromissoMenu::next(unsigned option, PrimeiroMenu *old_menu) {
    
    std::string usuario_atual = getUsuario();

    switch (option) {
        case 1: {
        std::string nova_compromisso_titulo;
        std::cout << "Insira um título para seu Compromisso" << std::endl;
        std::cin >> nova_compromisso_titulo;

        std::string nova_compromisso_descricao;
        std::cout << "Insira uma descricao para seu Compromisso" << std::endl;
        std::cin >> nova_compromisso_descricao;

        std::string nova_compromisso_data;
        std::cout << "Insira uma data para seu compromisso no formato DD/MM/AAA" << std::endl;
        std::cin >> nova_compromisso_data;

        unsigned nova_compromisso_prioridade;
        std::cout << "Insira uma prioridade para sua compromisso: " << std::endl;
        std::cout << "1 --> menos importante, 2 --> importante, 3 --> muito importante" << std::endl;
        std::cin >> nova_compromisso_prioridade;

        std::string nova_compromisso_estado;
        std::cout << "Insira um estado para sua compromisso: " << std::endl;
        std::cout << "feito , em progresso, não feito " << std::endl;
        std::cin >> nova_compromisso_estado;

        std::string nova_compromisso_local;
        std::cout << "Insira um local para seu compromisso: " << std::endl;
        std::cin >> nova_compromisso_local;

        std::string nova_compromisso_horario;
        std::cout << "Insira um horário para seu compromisso no formato HH:MM:SS : " << std::endl;
        std::cin >> nova_compromisso_horario;
        
        std::cout << "Adicionando compromisso..." << std::endl;

        Compromisso* new_compromisso = new Compromisso(nova_compromisso_data, nova_compromisso_local, nova_compromisso_titulo, nova_compromisso_descricao, nova_compromisso_horario, nova_compromisso_estado,  nova_compromisso_prioridade );

        ListaCompromisso::adicionarCompromisso(new_compromisso, &usuario_atual);

        // não achei uma função dessa para compromisso
        if (ListaCompromisso::buscarCompromisso(nova_compromisso_titulo) != nullptr) {

            std::cout << "A compromisso adicionada com sucesso!" << std::endl;
        }
        else {

            std::cout << "Nao foi possivel adicionar A nova compromisso." << std::endl;
        }

            
            return new CompromissoMenu(&usuario_atual);
        }
        case 2: {
       
        std::string titulo_Compromisso;
        std::cout << std::endl << "Digite o título da compromisso que deseja remover: " << std::endl;
        std::cin >> titulo_Compromisso;

        std::cout << "Buscando pelo Compromisso..." << std::endl;
        
        //precisa criar a função a baixo
        Compromisso* compromisso = ListaCompromisso::buscarCompromisso(titulo_Compromisso);

        if (compromisso != nullptr) {
            
            ListaCompromisso::removerCompromisso(compromisso, &usuario_atual); ///< Removendo a compromisso

            std::cout << "A compromisso com Título '" << titulo_Compromisso << "' foi removido com sucesso!" << std::endl;
        }
        else {

            std::cout << "A compromisso com Título '" << titulo_Compromisso << "' nao foi encontrado." << std::endl;
        }

            return new CompromissoMenu(&usuario_atual);
        }

        case 3: {

        std::string titulo_compromisso;
        std::cout << std::endl << "Digite o título do Compromisso que deseja editar: " << std::endl;
        std::cin >> titulo_compromisso;

        std::cout << "Buscando pela compromisso..." << std::endl;
        
        Compromisso* compromisso = ListaCompromisso::buscarCompromisso(titulo_compromisso);

        if (compromisso != nullptr) {

            std::cout << "Alterando o compromisso..." << std::endl
            << "Título: " << compromisso->getTitulo() << std::endl
            << "Descricao: " << compromisso->getDescricao() << std::endl
            << "Data: " << compromisso->getData() << std::endl
            << "Prioridade: " << compromisso->getPrioridade() << std::endl
            << "Estado: " << compromisso->getEstado() << std::endl
            << "Local: " << compromisso->getLocal() << std::endl
            << "Horário: " << compromisso->getHorario() << std::endl;
            
            std::cout << std::endl << "Voce deseja..." << std::endl
            << "1 --> Editar Título" << std::endl
            << "2 --> Editar Descricao" << std::endl
            << "3 --> Editar Data" << std::endl
            << "4 --> Editar Prioridade" << std::endl
            << "5 --> Editar Estado"<< std::endl
            << "6 --> Editar Local"<< std::endl
            << "7 --> Editar Horário"<< std::endl;

            unsigned opcao_editar;

            switch (opcao_editar) {
                case 1: {

                    std::string novo_titulo;
                    std::cout << "Digite um novo Título pata a compromisso:" << std::endl;
                    std::cin >> novo_titulo;

                    std::cout << "Alterando Título...";

                    compromisso->setTitulo(novo_titulo);

                    Compromisso* compromisso_alterado = ListaCompromisso::buscarCompromisso(novo_titulo);  

                    if (compromisso_alterado != nullptr && compromisso_alterado->getData() == compromisso->getData() && compromisso_alterado->getDescricao() == compromisso->getDescricao()) {

                        std::cout << "O Título do Compromisso foi alterado com sucesso para: " << compromisso->getTitulo() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar o Título do compromisso." << std::endl;
                    }
                }
                case 3: {

                    std::string nova_data;
                    std::cout << "Digite uma nova data para o compromisso (no formato: DD/MM/AAAA):" << std::endl;
                    std::cin >> nova_data;

                    std::cout << "Alterando data...";

                    compromisso->setData(nova_data);  

                    if (compromisso->getData() == nova_data) {

                        std::cout << "A data do compromisso foi alterada com sucesso para: " << compromisso->getData() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar a data do compromisso." << std::endl;
                    }
                }
                case 2: {

                    std::string novo_descricao;
                    std::cout << "Digite uma nova Descricao para o compromisso:" << std::endl;
                    std::cin >> novo_descricao;

                    std::cout << "Alterando Descricao...";

                    compromisso->setDescricao(novo_descricao);  

                    if (compromisso->getDescricao() == novo_descricao) {

                        std::cout << "A Descricao da compromisso foi alterada com sucesso para: " << compromisso->getDescricao() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar a Descricao do compromisso." << std::endl;
                    }
                }

                case 4: { 
                    unsigned nova_prioridade;
                    std::cout << "Digite a nova prioridade do compromisso entre:" << std::endl;
                    std::cout << "'1 --> menos importante, 2 --> importante, 3 --> muito importante'" << std:: endl;
                    std::cin >> nova_prioridade;

                    std::cout << "Alterando prioridade...";

                    compromisso->setPrioridade(nova_prioridade);  

                    if (compromisso->getPrioridade() == nova_prioridade) {
                     
                     std::cout << "A prioridade do compromisso foi alterada com sucesso para: " << compromisso->getPrioridade() << "!" << std::endl;
                    
                    }
                    else {

                        std::cout << "Nao foi possivel alterar a prioridade do compromisso." << std::endl;
                    }
                }

                case 5: { 
                    std::string nova_estado;
                    std::cout << "Digite uma novo estado para o compromisso entre : " << std::endl;
                    std::cout << "'feito , em progresso, não feito' " << std::endl;
                    std::cin >> nova_estado;

                    std::cout << "Alterando estado...";

                    compromisso->setEstado(nova_estado);
 

                    if (compromisso->getEstado() == nova_estado) {

                        std::cout << "O esatado do compromisso foi alterado com sucesso para: " << compromisso->getEstado() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar o estado do compromisso." << std::endl;
                    }
                }
                case 6: {

                    std::string novo_local;
                    std::cout << "Digite um novo Local para o compromisso:" << std::endl;
                    std::cin >> novo_local;

                    std::cout << "Alterando Local...";

                    compromisso->setLocal(novo_local);  

                    if (compromisso->getLocal() == novo_local) {

                        std::cout << "O Local do compromisso foi alterada com sucesso para: " << compromisso->getLocal() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar o Local do compromisso." << std::endl;
                    }

                }

                case 7: {

                    std::string nova_horario;
                    std::cout << "Digite um novo horário para o compromisso (no formato: HH:MM:SS):" << std::endl;
                    std::cin >> nova_horario;

                    std::cout << "Alterando Horário...";

                    compromisso->setHorario(nova_horario);  

                    if (compromisso->getHorario() == nova_horario) {

                        std::cout << "O horário do compromisso foi alterada com sucesso para: " << compromisso->getHorario() << "!" << std::endl;
                    }
                    else {

                        std::cout << "Nao foi possivel alterar o horário do compromisso." << std::endl;
                    }

                }

            } 
        }
        else {

            std::cout << "O compromisso com Título '" << titulo_compromisso << "' nao foi encontrado." << std::endl;
        }

            return new CompromissoMenu(&usuario_atual);

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
            return new CompromissoMenu(&usuario_atual);
    }
}
}
