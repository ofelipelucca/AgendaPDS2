#pragma once
#include <string>
#include <list>
   
class Lembrete {
public:
    Lembrete(const std::string& horario, const std::string& mensagem, const std::string& data);

    /// @brief Busca pela data do lembrete
    ///
    /// @return String da data 
    std::string getdata() const;
    
    /// @brief Busca pelo horario do lembrete
    ///
    /// @return String do horario
    std::string gethorario() const;
    
    /// @brief Adiciona/Altera uma mensagem especifica de um lembrete
    ///
    /// @param texto A mensagem a ser mudada/adicionada
    void alterarMensagem (std::string texto);
    
private:
    std::string data; ///< Armazena a data do lembrete
    std::string horario; ///< Armazena o horario do lembrete
    std::string mensagem; ///< Armazena a mensagem do lembrete
};

class ListaLembrete {
public:
    /// @brief Adiciona um Lembrete a lista de Lembretes
    ///
    /// @param lembrete O lembrete a ser adicionado
    void adicionarLembrete(Lembrete* lembrete);
    
    /// @brief Remove um lembrete da lista
    ///
    /// @param lembrete O lembrete a ser removido
    void removerLembrete(Lembrete* lembrete);
    
private:
    std::list<Lembrete> listadeLembretes; ///< Armazena todos os lembretes ativos
};