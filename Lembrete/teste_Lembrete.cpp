#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include "Lembrete.hpp"

TEST_CASE("Criando uma instância de Lembrete") {
    Lembrete l("09:40:00", "Consulta com o médico", "30/11/2023");

    SUBCASE("Verificando os campos do objeto") {
        CHECK_EQ(l.getData(), "30/11/2023");
        CHECK_EQ(l.getHorario(), "09:40:00");
        CHECK_EQ(l.getMensagem(), "Consulta com o médico");
    }

    SUBCASE("Salvando o objeto na lista de lembretes") {
        ListaLembrete xs();

        xs.adicionarLembrete(l, "pedroperreira31@gmail.com");
        CHECK_EQ(xs.tamanho(), 1);

        xs.removerLembrete(l, "pedroperreira31@gmail.com");
        CHECK_EQ(xs.tamanho(), 0);
    }
}

TEST_CASE("Alterando Um lembrete") {
    Lembrete l("09:40:00", "Consulta com o médico", "30/11/2023");

    l.alterarMensagem("Reunião");
    CHECK_EQ(l.getMensagem(), "Reunião");
}
