#include "Notificação.hpp"
#include "../Tarefa/Tarefa.hpp"
#include "../Lembrete/Lembrete.hpp"

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

Notificacao::Notificacao(const int horaAntes, const int minAntes) {
    _minAntes = minAntes;
    _horaAntes = horaAntes;
    _estado = true;
}

void Notificacao::notificar(Compromisso* compromisso) {
    time_t timer;
    struct tm *horarioLocal;
    time(&timer); // Obtem informações de data e hora
    horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

    int horaAtual = horarioLocal->tm_hour;
    int minAtual = horarioLocal->tm_min;

    int horaCompromisso = compromisso->getHorario()[0] + compromisso->getHorario()[1];
    int minCompromisso = compromisso->getHorario()[3] + compromisso->getHorario()[4];

    if (_estado && horaCompromisso - _horaAntes == horaAtual && minCompromisso - _minAntes == minAtual) {
        cout << compromisso->getDescricao() << " Daqui a: " << _horaAntes << "h e " << _minAntes << "min" << endl;
    }
}

void Notificacao::notificar(Lembrete* lembrete) {
    time_t timer;
    struct tm *horarioLocal;
    time(&timer); // Obtem informações de data e hora
    horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

    int horaAtual = horarioLocal->tm_hour;
    int minAtual = horarioLocal->tm_min;
    
    int horaLembrete = lembrete->getHorario()[0] + lembrete->getHorario()[1];
    int minLembrete = lembrete->getHorario()[3] + lembrete->getHorario()[4];

    if (_estado && horaLembrete - _horaAntes == horaAtual && minLembrete - _minAntes == minAtual) {
        cout << lembrete->getMensagem() << " Daqui a: " << _horaAntes << "h e " << _minAntes << "min" << endl;
    }
}

void Notificacao::ativarNotificacao() {
    _estado = true;
}

void Notificacao::desativarNotificacao() {
    _estado = false;
}

bool Notificacao::checkEstado() {
    return _estado;
}
