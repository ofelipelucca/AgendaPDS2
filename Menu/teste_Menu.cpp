#include "../doctest.hpp"

#include "CompromissoMenu.hpp"
#include "LembreteMenu.hpp"
#include "LoginMenu.hpp"
#include "Menu.hpp"
#include "TarefaMenu.hpp"
#include "UsuarioMenu.hpp"

TEST_CASE("Criando o menu de compromissos") {
    std::string email = "pedroperreira31@gmail.com";

    CompromissoMenu menu(&email);
    CHECK_EQ(menu.getUsuario(), email);
}

TEST_CASE("Criando o menu de lembretes") {
    std::string email = "pedroperreira31@gmail.com";

    LembreteMenu menu(&email);
    CHECK_EQ(menu.getUsuario(), email);
}

TEST_CASE("Criando o menu de tarefas") {
    std::string email = "pedroperreira31@gmail.com";

    TarefaMenu menu(&email);
    CHECK_EQ(menu.getUsuario(), email);
}

TEST_CASE("Criando o menu do usuário") {
    std::string email = "pedroperreira31@gmail.com";

    UsuarioMenu menu(&email);
    CHECK_EQ(menu.getUsuario(), email);
}
