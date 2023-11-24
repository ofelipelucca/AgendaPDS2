#pragma once

#include "../Tarefa/Tarefa.hpp"
#include "../Lembrete/Lembrete.hpp"

#include <string>
#include <ctime>
#include <chrono>

class Notificacao {
public:
    Notificacao(const int horaAntes, const int minAntes);
    
    /*
    /// @brief Busca pelos minutos de antecedencia da notificaçao 
    ///
    /// @return Inteiro com os minutos
    int getAntecedenciaMinutos() const;

    /// @brief Busca pelas horas de antecedencia da notificaçao
    ///
    /// @return Inteiro com as horas 
    int getAntecedenciaHoras() const;

    /// @brief Muda a antecedencia, em minutos, de uma notificaçao
    ///
    /// @param NovaAntecedencia A antecedencia a ser alterada
    ///
    /// @attention NovaAntecedencia deve variar entre: 1 e 59 minutos.
    void setAntecedenciaMinutos(int NovaAntecedencia);
    
    /// @brief Muda a antecedencia, em horas, de uma notificaçao
    ///
    /// @param NovaAntecedencia A antecedência a ser alterada
    ///
    /// @attention NovaAntecedencia deve variar entre: 1 e 23 horas
    void setAntecedenciaHoras(int NovaAntecedencia);
    */

    /*
    /// @brief Compara com o horario real e notifica uma tarefa no horario programado
    ///
    /// @param tarefa A tarefa a ser notificada
    void notificarTarefa(Tarefa* tarefa);
    */
    
    /// @brief Compara com o horario real e notifica um compromisso no horario programado
    ///
    /// @param compromisso O compromisso a ser notificado
    void notificar(Compromisso* compromisso);
    
    /// @brief Compara com o horario real e notifica um lembrete no horario programado
    ///
    /// @param lembrete O lembrete a ser notificado
    void notificar(Lembrete* lembrete);

    /// @brief Desativa uma notificação
    void desativarNotificacao();

private:
    int _minAntes; ///< Armazena os minutos de antecedencia da notificaçao (1 a 59) 
    int _horaAntes; ///< Armazena as horas de antecedencia da notificaçao (1 a 23)
    bool _estado; ///< Armazena o estado da notificação (ativada = true, desativada = false)
    int _minAtual; ///< Armazena os minutos atuais do computador
    int _horaAtual; ///< Armazena as horas atuais do computador
};
