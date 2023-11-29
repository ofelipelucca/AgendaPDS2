#include "doctest.hpp"
#include "Tarefa.hpp"

TEST_CASE("Criando uma instância de Tarefa") {
    std::string str1 = "Estudar";
    std::string str2 = "Estudar para a prova de PDS2";
    std::string str3 = "29/11/2023";
    std::string str4 = "não feito";

    Tarefa t(str1, str2, str3, 2, str4);

    SUBCASE("Verificando os campos do objeto") {
        CHECK_EQ(t.getTitulo(), "Estudar");
        CHECK_EQ(t.getDescricao(), "Estudar para a prova de PDS2 do dia 30/11");
        CHECK_EQ(t.getData(), "20/11/2023");
        CHECK_EQ(t.getPrioridade(), 3);
        CHECK_EQ(t.getEstado(), "não feito");
    }

    SUBCASE("Salvando o objeto na lista de tarefas") {
        ListaTarefa xs;
        std::string str = "pedroperreira31@gmail.com";

        xs.adicionarTarefa(&t, &str);
        CHECK_EQ(xs.tamanho(), 1);

        xs.removerTarefa(&t, &str);
        CHECK_EQ(xs.tamanho(), 0);
    }
}

TEST_CASE("Alterando uma Tarefa") {
    std::string str1 = "Estudar";
    std::string str2 = "Estudar para a prova de PDS2";
    std::string str3 = "29/11/2023";
    std::string str4 = "não feito";

    Tarefa t(str1, str2, str3, 2, str4);

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
    std::string str1 = "24/11/2023";
    std::string str2 = "UFMG";
    std::string str3 = "Reunião";
    std::string str4 = "Reunião com o grupo para terminar o trabalho";
    std::string str5 = "16:30:00";
    std::string str6 = "não feito";

    Compromisso c(str1, str2, str3, str4, str5, str6, 2);
    
    SUBCASE("Verificando os campos do objeto") {
        CHECK_EQ(c.getLocal(), "UFMG");
        CHECK_EQ(c.getHorario(), "16:30:00");
    }

    SUBCASE("Salvando o objeto na lista de compromissos") {
        ListaCompromisso xs;
        std::string str = "pedroperreira31@gmail.com";

        xs.adicionarCompromisso(&c, &str);
        CHECK_EQ(xs.tamanho(), 1);

        xs.removerCompromisso(&c, &str);
        CHECK_EQ(xs.tamanho(), 0);
    }
}

TEST_CASE("Alterando um Compromisso") {
    std::string str1 = "24/11/2023";
    std::string str2 = "UFMG";
    std::string str3 = "Reunião";
    std::string str4 = "Reunião com o grupo para terminar o trabalho";
    std::string str5 = "16:30:00";
    std::string str6 = "não feito";

    Compromisso c(str1, str2, str3, str4, str5, str6, 2);

    c.setCor("azul");
    c.setLocal("CEU");
    c.setHorario("10:00:00");

    CHECK_EQ(c.getCor(), "\033[38;2;25;84;247m");
    CHECK_EQ(c.getLocal(), "CEU");
    CHECK_EQ(c.getHorario(), "10:00:00");
}
