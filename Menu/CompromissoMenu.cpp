#include "CompromissoMenu.hpp"
#include <iostream>

// Implementação dos métodos da classe CompromissoMenu

CompromissoMenu::CompromissoMenu(std::string *login_email) {
    setUsuario(*login_email);
    setTitulo("Menu de Compromissos");
    setSubtitulo("Escolha uma opção:");
    setOpcoes({"1 --> Ver Compromissos", "2 --> Adicionar Compromisso", "3 --> Remover Compromisso", "4 --> Voltar"});
}

PrimeiroMenu *CompromissoMenu::next(unsigned option) {
    PrimeiroMenu *proximoMenu = nullptr;

    switch (option) {
        case 1:
            // Implementar a visualização dos compromissos
            // Chame a função para mostrar os compromissos aqui
            std::cout << "Visualizando Compromissos..." << std::endl;
            break;
        case 2:
            // Implementar a adição de um compromisso
            // Chame a função para adicionar compromisso aqui
            std::cout << "Adicionando Compromisso..." << std::endl;
            break;
        case 3:
            // Implementar a remoção de um compromisso
            // Chame a função para remover compromisso aqui
            std::cout << "Removendo Compromisso..." << std::endl;
            break;
        case 4:
            // Voltar para o menu anterior (pode ser o Menu Principal ou outro)
            std::cout << "Voltando..." << std::endl;
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }

    // Retorna o próximo menu, se houver
    return proximoMenu;
}
