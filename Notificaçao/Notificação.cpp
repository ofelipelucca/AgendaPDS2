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

    time_t timer;
    struct tm *horarioLocal;
    time(&timer); // Obtem informações de data e hora
    horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

    _horaAtual = horarioLocal->tm_hour;
    _minAtual = horarioLocal->tm_min;
}

void Notificacao::notificar(Compromisso* compromisso) {
    int horaCompromisso = compromisso->getHorario()[0] + compromisso->getHorario()[1];
    int minCompromisso = compromisso->getHorario()[3] + compromisso->getHorario()[4];

    if (_estado && horaCompromisso - _horaAntes == _horaAtual && minCompromisso - _minAntes == _minAtual) {
        cout << compromisso->getDescricao() << " Daqui a: " << _horaAntes << "h e " << _minAntes << "min" << endl;
    }
}

void Notificacao::notificar(Lembrete* lembrete) {
    int horaLembrete = lembrete->getHorario()[0] + lembrete->getHorario()[1];
    int minLembrete = lembrete->getHorario()[3] + lembrete->getHorario()[4];

    if (_estado && horaLembrete - _horaAntes == _horaAtual && minLembrete - _minAntes == _minAtual) {
        cout << lembrete->getMensagem() << " Daqui a: " << _horaAntes << "h e " << _minAntes << "min" << endl;
    }
}

void Notificacao::desativarNotificacao() {
    _estado = false;
}
