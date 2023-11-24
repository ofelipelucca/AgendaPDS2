#include "Calendario.hpp"

#include <iostream>
#include <map>
#include <vector>

void Calendario::inserir(std::string key, std::vector<std::string> value) {
    _mapaHorario.insert(std::pair<std::string, std::vector<std::string>>(key, value));
}

void Calendario::inserir(std::string key) {
    _agenda.insert(std::pair<std::string, std::map<std::string, std::vector<std::string>>>(key, _mapaHorario));
}

void Calendario::imprimirCalendario(std::string dia) {
    std::map<std::string, std::vector<std::string>>::iterator it = (_agenda.find(dia)->second).begin();

    std::cout << "Atividades do dia " << dia << ": " << std::endl << std::endl;

    while (it != (_agenda.find(dia)->second).end()) {
        std::cout << "Horário: " << it->first << std::endl << std::endl << "Atividades: " << std::endl << std::endl;

        if ((it->second).size() == 0) {
            std::cout << "Nada" << std::endl << std::endl;
        }

        for (int i=0; i < (it->second).size(); i++) {
            std::cout << (it->second)[i] << std::endl;
        }
        it++;
    }
}
