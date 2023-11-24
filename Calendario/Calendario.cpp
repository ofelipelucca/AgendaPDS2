#include "Calendario.hpp"

void Calendario::inserir(std::string key, std::vector<std::string> value) {

    _mapaHorario.insert(std::pair<std::string, std::vector<std::string>>(key, value));
}

unsigned Calendario::size_mapaHorario() {

    return _mapaHorario.size();
}

void Calendario::inserir(std::string key) {

    _agenda.insert(std::pair<std::string, std::map<std::string, std::vector<std::string>>>(key, _mapaHorario));
    _mapaHorario.clear();
}

unsigned Calendario::size_agenda() {

    return _agenda.size();
}

void Calendario::imprimirCalendario(std::string dia) {

    std::map<std::string, std::vector<std::string>>::iterator it = (_agenda.find(dia)->second).begin();

    std::cout << "Atividades do dia " << dia << ": " << std::endl << std::endl;

    while (it != (_agenda.find(dia)->second).end()) {
        std::cout << "Horário: " << it->first << std::endl << std::endl << "Atividades: " << std::endl << std::endl;

        if ((it->second).size() == 0) {
            std::cout << "Nenhuma atividade registrada!" << std::endl << std::endl;
        }

        for (int i=0; i < (it->second).size(); i++) {
            
            std::cout << (it->second)[i] << std::endl;
        }
        it++;
    }
}
