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

        const size_t MAX_CARACTERES = 45; ///< Limite de caracteres para a mensagem do lembrete
        
        /// Verifica se a nova mensagem esta vazia, se a nova mensagem eh igual a mensagem atual ou ultrapassa o limite de caracteres
        if (!nova_mensagem.empty() || nova_mensagem != this->_mensagem || nova_mensagem.length() < MAX_CARACTERES) {

            this->_mensagem = nova_mensagem; ///< Atribui a nova mensagem
        } 
        else {

            throw std::invalid_argument("Mensagem invalida");
        }
    }
    catch (const std::exception& e) {

        std::cout << "A mensagem deve ser diferente da mensagem atual e possuir no maximo 45 caracteres" << std::endl;

        handleExcecao(e);
    }
}

void ListaLembrete::adicionarLembrete(Lembrete* lembrete, std::string* user_email) {

    _listadeLembretes.insert(std::make_pair(*user_email, lembrete)); ///< Adicionando o lembrete na lista
}

void ListaLembrete::removerLembrete(Lembrete* lembrete, std::string* user_email) {
    
    /// Itera sobre a lista procurando pelo lembrete fornecido e o email do usuario logado
    auto it = std::find_if(
        _listadeLembretes.begin(), _listadeLembretes.end(), 
        [user_email, lembrete](const auto & p) 
        { return (p->first == user_email && p->second == lembrete); }
    );

    if (it != _listadeLembretes.end()) {
        
        _listadeLembretes.erase(it); ///< Remove o lembrete da lista
    }
}

unsigned ListaLembrete::tamanho() {

    return _listadeLembretes.size(); ///< Retorna o tamanho do mapa
}

void ImprimirLembretes::verLembretes(std::string* user_email) {
    
    /// Imprime os lembretes atuais da lista
    for (const auto& lembrete : _listadeLembretes) {

        /// Verifica se o lembrete pertence ao usuario logado
        if (lembrete.first == *user_email) {

            std::cout << "Lembrete: " << lembrete.second->getMensagem() << std::endl 
            << "Data: " << lembrete.second->getData() << std::endl
            << "Horario: " << lembrete.second->getHorario() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}
