#include "Calendario.hpp"

#define STRING(num) #num

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

void Calendario::imprimirCalendario(std::string data) {

    int dia = int(char(data[0]) + char(data[1])) - 1;
    int mes = char(data[3]) + char(data[4]);
    int ano = char(data[6]) + char(data[7]) + char(data[8]) + char(data[9]);

    for (unsigned cont=0; cont<7; cont++ ) {
        dia ++;

        if (dia > 30) {
            dia -= 30;
            mes ++;
        }

        if (mes > 12) {
            mes -= 12;
            ano ++;
        }

        std::string diaAtual = STRING(dia);
        diaAtual += '/';
        diaAtual += STRING(mes);
        diaAtual += '/';
        diaAtual += STRING(ano);

        auto it = (_agenda.find(diaAtual)->second).begin();

        std::cout << "Atividades do dia " << diaAtual << ": " << std::endl << std::endl;

        while (it != (_agenda.find(diaAtual)->second).end()) {
            std::cout << "Horário: " << it->first << std::endl << std::endl << "Atividades: " << std::endl << std::endl;

            if ((it->second).size() == 0) {
                std::cout << "Nenhuma atividade registrada!" << std::endl << std::endl;
            }

            for (unsigned i=0; i < (it->second).size(); i++) {
                
                std::cout << (it->second)[i] << std::endl;
            }
            it++;
        }
    }
}
