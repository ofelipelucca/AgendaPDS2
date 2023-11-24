#include "Usuario.hpp"
#include "../Exceçoes/Exceções.hpp"

#include <iostream>
#include <string>
#include <sstream>
 
Usuario::Usuario(std::string& nome, std::string& sobrenome, std::string& idade, std::string& email) {
    _nome = nome;
    _sobrenome = sobrenome;
    _idade = idade;
    _email = email;
}

std::string Usuario::getNome() const {

    return this->_nome; ///< Retorna o nome
}
std::string Usuario::getEmail() const {
    
    return this->_email; ///< Retorna o email
}

void Usuario::mudarEmail(std::string* novo_email) {
    try {
        
        if (checkUsuario(novo_email)) throw std::logic_error("O email fornecido ja esta em uso");

        std::istringstream iss(*novo_email);
        std::string usuario, dominio;

        /// Quebra o novo email em partes, para fazer as verificacoes necessarias
        std::getline(iss, usuario, '@');
        std::getline(iss, dominio);

        /// Verifica se o usuario ou dominio estao preenchidos
        if (usuario == "" || dominio == "") {
        
            throw std::invalid_argument("Email incompleto"); 
        }

        /// Verifica se o dominio esta preenchido corretamente
        if (dominio != "gmail.com" && dominio != "yahoo.com" && dominio != "outlook.com") {

            throw std::invalid_argument("Dominio do email invalido");
        }

        this->_email = *novo_email; ///< Atribui o novo email
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Email deve estar no formato: usuario@dominio.com" << std::endl
        << "Dominios aceitos:" << std::endl
        << "    - 'gmail.com'" << std::endl
        << "    - 'yahoo.com'" << std::endl
        << "    - 'outlook.com'" << std::endl;

        handleExcecao(e);
    }
    catch (const std::exception& e) {

        handleExcecao(e);
    }
}

void ListaUsuario::adicionarUsuario(Usuario* usuario) {
    
    _listadeusuario.insert(std::make_pair(usuario->getEmail(), *usuario)); ///< Adicionando o email do usuario logado na lista
}

void ListaUsuario::removerUsuario(Usuario* usuario) {

    _listadeusuario.erase(usuario->getEmail()); ///< Removendo o Usuario da lista
}

bool ListaUsuario::checkUsuario(std::string* email) const {

    auto it = _listadeusuario.find(*email); ///< Procura o usuario na lista pelo email

    return (it != _listadeusuario.end());
}

bool ListaUsuario::checkUsuario(std::string* email, std::string* nome) const {

    auto it = _listadeusuario.find(*email); ///< Procura o usuario na lista pelo email

    return (it != _listadeusuario.end() && it->second.getEmail() == *email);
}