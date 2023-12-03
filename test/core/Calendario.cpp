#include "../storage/doctest.hpp"
#include "../include/core/Calendario.hpp"

TEST_CASE("Mapeando atividades para o calendário") {
    Calendario c;

    SUBCASE("Mapeando atividades para um horário") {
        c.inserir("10:00:00", {"Estudar para a prova"});
        c.inserir("15:00:00", {"Ir para faculdade", "Terminar o trabalho"});

        CHECK_EQ(c.sizeMapaHorario(), 2);

        c.inserir("26/11/2023");

        CHECK_EQ(c.sizeMapaHorario(), 0);
    }

    SUBCASE("Mapeando horários para um dia") {
        c.inserir("10:00:00", {"Estudar para a prova"});

        c.inserir("26/11/2023");
        CHECK_EQ(c.sizeAgenda(), 1);

        c.inserir("15:00:00", {"Ir para faculdade", "Terminar o trabalho"});

        c.inserir("03/12/2023");
        CHECK_EQ(c.sizeAgenda(), 2);
    }
}
