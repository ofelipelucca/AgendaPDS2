#pragma once

#include "../Tarefa/Tarefa.hpp"
#include "../Lembrete/Lembrete.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <map>

class Calendario {
public:
    /// @brief Insere um grupo de atividades em um determinado horário
    ///
    /// @param key O horario das atividades
    ///
    /// @param value As atividades que serão inseridas
    void inserir(std::string key, std::vector<std::string> value);

    /// @brief Insere um horário com atividades(ou não) em um determinado dia
    ///
    /// @param key O dia
    ///
    /// @param value As atividades que serão inseridas
    void inserir(std::string key);  

    /// @brief Imprime o calendario do dia escolhido
    ///
    /// @param dia O dia escolhido
    void imprimirCalendario(std::string dia);

private:
    std::map<std::string, std::vector<std::string>> _mapaHorario; ///< Mapa para armazenar as atividades por horário
    std::map<std::string, std::map<std::string, std::vector<std::string>>> _agenda; ///< Mapa para armazenar os horários por dia
};
