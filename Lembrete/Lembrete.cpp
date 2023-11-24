#include "Lembrete.hpp"
#include "../Exceçoes/Exceções.hpp"

#include <string>
#include <iostream>

Lembrete::Lembrete(const std::string& horario, const std::string& mensagem, const std::string& data) {
    _data = data;
    _horario = horario;
    _mensagem = mensagem;
}

std::string Lembrete::getData() const {

    return this->_data; ///< Retorna a data
}

std::string Lembrete::getHorario() const {

    return this->_horario; ///< Retorna o horario
}

std::string Lembrete::getMensagem() const {

    return this->_mensagem; ///< Retorna a mensagem
}

void Lembrete::alterarMensagem(std::string nova_mensagem) {
    
    try {
        /// Verifica se a nova mensagem esta vazia, ou se a nova mensagem eh igual a mensagem atual
        if (!nova_mensagem.empty() || nova_mensagem != this->_mensagem) {

            this->_mensagem = nova_mensagem; ///< Atribui a nova mensagem
        } 
        else {

            throw std::invalid_argument("Mensagem invalida");
        }
    }
    catch (const std::exception& e) {

        std::cout << "A mensagem deve ser diferente da mensagem atual" << std::endl;

        handleExcecao(e);
    }
}

void ListaLembrete::adicionarLembrete(Lembrete* lembrete) {
    
    _listadeLembretes.push_back(*lembrete); ///< Adicionando o lembrete na lista
}

void ListaLembrete::removerLembrete(Lembrete* lembrete) {

    _listadeLembretes.remove(*lembrete); ///< Removendo o lembrete da lista
}

void ListaLembrete::verLembretes() {
    for (const auto& lembrete : _listadeLembretes) {
        std::cout << lembrete.getMensagem() << " " << "Data: " << lembrete.getData() << "Horario: " << lembrete.getHorario() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
