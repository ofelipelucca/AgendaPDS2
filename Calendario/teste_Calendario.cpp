#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include "Calendario.hpp"

TEST_CASE("Mapeando atividades para o calendário") {
    Calendario c;

    SUBCASE("Mapeando atividades para um horário") {
        c.inserir("10:00:00", {"Estudar para a prova"});
        c.inserir("15:00:00", {"Ir para faculdade", "Terminar o trabalho"});

        CHECK_EQ(c.size_mapaHorario(), 2);

        c.inserir("26/11/2023");

        CHECK_EQ(c.size_mapaHorario(), 0);
    }

    SUBCASE("Mapeando horários para um dia") {
        c.inserir("10:00:00", {"Estudar para a prova"});

        c.inserir("26/11/2023");
        CHECK_EQ(c.size_agenda(), 1);

        c.inserir("15:00:00", {"Ir para faculdade", "Terminar o trabalho"});

        c.inserir("03/12/2023");
        CHECK_EQ(c.size_agenda(), 2);
    }
}
