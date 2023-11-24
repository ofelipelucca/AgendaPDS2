#pragma once

#include <string>
#include <unordered_map>
   
class Lembrete {
public:
    Lembrete(const std::string& horario, const std::string& mensagem, const std::string& data);

    /// @brief Busca pela data do lembrete
    ///
    /// @return String da data 
    std::string getData() const;
    
    /// @brief Busca pelo horario do lembrete
    ///
    /// @return String do horario
    std::string getHorario() const;

    /// @brief Busca pela mensagem do lembrete
    ///
    /// @return String da mensagem
    std::string getMensagem() const;
    
    /// @brief Muda a data de um lembrete
    ///
    /// @param novaData A nova data a ser adicionada
    ///
    /// @attention A data informada deve estar no formato: DD/MM/AAAA
    void setData(const std::string& novaData);

    /// @brief Muda o horario de um compromisso
    ///
    /// @param novoHorario O novo horario a ser colocado
    ///
    /// @attention O horario informado deve estar no formato: HH:MM:SS
    void setHorario(const std::string& novoHorario);

    /// @brief Adiciona uma mensagem para um lembrete
    ///
    /// @param texto A mensagem a ser adicionada
    void setMensagem(std::string texto);
    
private:
    std::string _data; ///< Armazena a data do lembrete
    std::string _horario; ///< Armazena o horario do lembrete
    std::string _mensagem; ///< Armazena a mensagem do lembrete
};

class ListaLembrete {
public:
    /// @brief Adiciona um Lembrete a lista de Lembretes
    ///
    /// @param lembrete O lembrete a ser adicionado
    static void adicionarLembrete(Lembrete* lembrete, std::string* user_email);
    
    /// @brief Remove um lembrete da lista
    ///
    /// @param lembrete O lembrete a ser removido
    static void removerLembrete(Lembrete* lembrete, std::string* user_email);

    /// @brief Procura pelo lembrete pela mensagem
    ///
    /// @param mensagem A mensagem do lembrete a ser buscado
    static Lembrete* buscarLembrete(std::string* mensagem);

protected:
    static std::unordered_map<std::string, Lembrete*> _listadeLembretes; ///< Armazena todos os lembretes ativos
};

class ImprimirLembretes : public ListaLembrete {
public:
    /// @brief Imprime todos lembretes da lista 
    ///
    /// @param user_email O email do usuario logado
    static void verLembretes(std::string* user_email);
};
