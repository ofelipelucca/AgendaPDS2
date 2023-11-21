#include "Tarefa.hpp"
#include "Exceções.hpp"
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>

std::string Tarefa::getTitulo() const {

    return this->titulo; ///< Retorna o titulo
}

unsigned Tarefa::getPrioridade() const {

    return this->prioridade; ///< Retorna a prioridade
}

std::string Tarefa::getEstado() const {

    return this->estado; ///< Retorna o estado
}

void Tarefa::setTitulo(const std::string& novoTitulo) {

    try {
        const size_t MAX_CARACTERES = 50; ///< Limite de caracteres para o novo titulo

        /// Verifica se o novo titulo eh valido
        if (!novoTitulo.length() >= MAX_CARACTERES || !novoTitulo.empty()) {

            this->titulo = novoTitulo; ///< Atribui o novo titulo
        }
        else {

            throw std::invalid_argument("Titulo invalido");
        }
    } 
    catch (const std::exception& e) {
        
        std::cout << "Titulo deve possuir entre 1 e 50 caracteres" << std::endl;
        
        handleExcecao(e);
    }
}

void Tarefa::setDescricao(const std::string& novaDescricao) {

    try {
        const size_t MAX_CARACTERES = 120; ///< Limite de caracteres para a nova descricao

        /// Verifica se a nova descricao eh valida
        if (!novaDescricao.length() || !novaDescricao.empty()) {

            this->descricao = novaDescricao; //< Atribui a nova descricao
        }
        else {
        
            throw std::invalid_argument("Descricao invalida");
        }
    }
    catch (const std::exception& e) {
        
        std::cout << "Descricao deve possuir entre 1 e 120 caracteres" << std::endl;
        
        handleExcecao(e);
    }
}

void Tarefa::setData(const std::string& novaData) {

    try {
        /// Verifica o formato da nova data
        std::istringstream iss(novaData);
        int dia, mes, ano;
        char limitador; ///< Limitador deve ser '/'

        if (!(iss >> dia >> limitador >> mes >> limitador >> ano) || limitador != '/') {
            
            throw std::invalid_argument("Formato da data invalido");
        }

        /// Obtem a data atual do sistema
        auto timepoint_agora = std::chrono::system_clock::now();
    
        /// Converte time_point para time_t
        std::time_t time_t_agora = std::chrono::system_clock::to_time_t(timepoint_agora);
    
        /// Converte time_t para uma struct tm
        struct std::tm* tmAtual = std::localtime(&time_t_agora);

        // Cria uma representacao da nova data
        std::tm tmNovaData = {0}; ///< Inicializa o struct da nova data
        tmNovaData.tm_mday = dia; ///< Atribui o dia da nova data
        tmNovaData.tm_mon = mes - 1; ///< Atribui o mes da nova data (os meses são de 0 a 11)
        tmNovaData.tm_year = ano - 1900; ///< Atribui o ano da nova data (os anos são contados a partir de 1900)

        /// Converte a nova data de time_t para time_point
        auto timepoint_novadata = std::chrono::system_clock::from_time_t(std::mktime(&tmNovaData));

        // Verifica se a nova data esta no futuro
        if (timepoint_novadata <= timepoint_agora) {
        
            throw std::logic_error("Data no passado");
        }

        this->data = novaData; ///< Atribui a nova data
    }
    catch (const std::invalid_argument& e) {
        
        std::cout << "Data deve estar no formato DD/MM/AAAA" << std::endl;
        
        handleExcecao(e);
    }
    catch (const std::logic_error& e) {

        std::cout << "Impossivel adicionar uma tarefa ou compromisso para datas anteriores a atual" << std::endl;
        
        handleExcecao(e);
    }
    catch (const std::exception& e) {
    
        handleExcecao(e);
    }
}

void Tarefa::setPrioridade(const unsigned novaPrioridade) {
    try {
        /// Verifica se a nova prioridade eh valida
        if (novaPrioridade == 1 || novaPrioridade == 2 || novaPrioridade == 3) {
        
            this->prioridade = novaPrioridade; ///< Atribui a nova prioridade
        }
        else {

            throw std::invalid_argument("Prioridade invalida");
        }
    }
    catch (const std::exception& e) {

        std::cout << "A prioridade deve ser: " << std::endl
        << "    - '1' para menos importante" << std::endl
        << "    - '2' para importante" << std::endl
        << "    - '3' para mais importante" << std::endl;
        
        handleExcecao(e);
    }
}

void Tarefa::setEstado(const std::string& novoEstado) {

    try {    
        /// Verifica se o novo estado eh valido
        if (novoEstado == "feito" || novoEstado == "em progresso" || novoEstado == "não feito") {
        
            this->estado = novoEstado; ///< Atribui o novo estado
        }
        else {

            throw std::invalid_argument("Estado invalido");
        }
    }
    catch (const std::exception& e) {

        std::cout << "O estado deve ser: " << std::endl
        << "    - 'feito'" << std::endl 
        << "    - 'em progresso'" << std::endl 
        << "    - 'nao feito'" << std::endl;

        handleExcecao(e);
    }    
}