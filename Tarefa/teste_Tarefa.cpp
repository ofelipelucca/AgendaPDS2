#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include "Tarefa.hpp"

TEST_CASE("Criando uma instância de Tarefa") {
    Tarefa t("Estudar", "Estudar para a prova de PDS2 do dia 30/11", "20/11/2023", 3, "não feito");

    SUBCASE("Verificando os campos do objeto") {
        CHECK_EQ(t.getTitulo(), "Estudar");
        CHECK_EQ(t.getDescricao(), "Estudar para a prova de PDS2 do dia 30/11");
        CHECK_EQ(t.getData(), "20/11/2023");
        CHECK_EQ(t.getPrioridade(), 3);
        CHECK_EQ(t.getEstado(), "não feito");
    }

    SUBCASE("Salvando o objeto na lista de tarefas") {
        ListaTarefa xs();

        xs.adicionarTarefa(t, "pedroperreira31@gmail.com");
        CHECK_EQ(xs.tamanho(), 1);

        xs.removerTarefa(t, "pedroperreira31@gmail.com");
        CHECK_EQ(xs.tamanho(), 0);
    }
}

TEST_CASE("Alterando uma Tarefa") {
    Tarefa t("Estudar", "Estudar para a prova de PDS2 do dia 30/11", "28/11/2023", 3, "não feito");

    t.setTitulo("VPLs");
    t.setDescricao("Terminar de fazer as VPLs");
    t.setData("03/12/2023");
    t.setPrioridade(2);
    t.setEstado("em progresso");

    CHECK_EQ(t.getTitulo(), "VPLs");
    CHECK_EQ(t.getDescricao(), "Terminar de fazer as VPLs");
    CHECK_EQ(t.getData(), "03/12/2023");
    CHECK_EQ(t.getPrioridade(), 2);
    CHECK_EQ(t.getEstado(), "em progresso");
}

TEST_CASE("Criando uma instância de Compromisso") {
    Compromisso c("24/11/2023", "UFMG", "Reunião", "Reunião com o grupo para terminar o trabalho", "16:30:00", "não feito", 2);
    
    SUBCASE("Verificando os campos do objeto") {
        CHECK_EQ(c.getLocal(), "UFMG");
        CHECK_EQ(c.getHorario(), "16:30:00");
    }

    SUBCASE("Salvando o objeto na lista de compromissos") {
        ListaCompromisso xs();

        xs.adicionarCompromisso(c, "pedroperreira31@gmail.com");
        CHECK_EQ(xs.tamanho(), 1);

        xs.removerCompromisso(c, "pedroperreira31@gmail.com");
        CHECK_EQ(xs.tamanho(), 0);
    }
}

TEST_CASE("Alterando um Compromisso") {
    Compromisso c("24/11/2023", "UFMG", "Reunião", "Reunião com o grupo para terminar o trabalho", "16:30:00", "não feito", 2);

    c.setCor("azul");
    c.setLocal("CEU");
    c.setHorario("10:00:00");

    CHECK_EQ(c.getCor(), "\033[38;2;25;84;247m");
    CHECK_EQ(c.getLocal(), "CEU");
    CHECK_EQ(c.getHorario(), "10:00:00");
}
