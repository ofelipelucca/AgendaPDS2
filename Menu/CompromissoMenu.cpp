#include "CompromissoMenu.hpp"
#include <iostream>

// Implementação dos métodos da classe CompromissoMenu

CompromissoMenu::CompromissoMenu(std::string *login_email) {
    setUsuario(*login_email);
    setTitulo("Menu de Compromissos");
    setSubtitulo("Escolha uma opção:");
    setOpcoes({"1 --> Adicionar novo Compromisso", "2 --> Remover Compromisso", "5 --> Editar Compromisso " "4 --> Voltar", "5 --> Sair"});
    setUsuario(*user_email);
}

PrimeiroMenu *CompromissoMenu::next(unsigned option, PrimeiroMenu *old_menu) {
    
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

        ListaCompromisso::adicionarCompromisso(new_compromisso, &getUsuario());

        // não achei uma função dessa para compromisso
        if (ListaCompromisso::buscarCompromisso(& ) != nullptr) {

            std::cout << "A compromisso adicionada com sucesso!" << std::endl;
        }
        else {

            std::cout << "Nao foi possivel adicionar A nova compromisso." << std::endl;
        }

            
            return new CompromissoMenu(&getUsuario());
        }
        case 2: {
       
        std::string titulo_Compromisso;
        std::cout << std::endl << "Digite o título da Tarefa que deseja remover: " << std::endl;
        std::cin >> titulo_Compromisso;

        std::cout << "Buscando pelo Compromisso..." << std::endl;
        
        //precisa criar a função a baixo
        Compromisso* compromisso = ListaTarefa::buscarCompromisso(&titulo_Compromisso);

        if (compromisso != nullptr) {
             

             // parei de editar aqui
             
            ListaTarefa::removerTarefa(tarefa, &getUsuario()); ///< Removendo a Tarefa

            std::cout << "A Tarefa com Título '" << titulo_Tarefa << "' foi removida com sucesso!" << std::endl;
        }
        else {

            std::cout << "A Tarefa com Título '" << titulo_Tarefa << "' nao foi encontrada." << std::endl;
        }

            
            return new CompromissoMenu(&getUsuario());
        }
        case 3: {

            // Implementar a remoção de um compromisso
            // Chame a função para remover compromisso aqui
            std::cout << "Removendo Compromisso..." << std::endl;
            
            return new CompromissoMenu(&getUsuario());
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
            return new CompromissoMenu(&getUsuario());
    }
}
}
