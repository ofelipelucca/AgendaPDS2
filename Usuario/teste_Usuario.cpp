#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"

#include "Usuario.hpp"

TEST_CASE("Criando uma instância de Usuario") {
    Usuario p("Pedro", "Perreira", 20, "pedroperreira31@gmail.com");

    SUBCASE("Verificando os campos do objeto") {
        CHECK_EQ(p.getNome(), "Pedro Perreira");
        CHECK_EQ(p.getIdade(), "20");
        CHECK_EQ(p.getEmail(), "pedroperreira31@gmail.com");
    }

    SUBCASE("Salvando o objeto na lista de usuarios") {
        ListaUsuario xs();

        xs.adicionarUsuario(p);
        CHECK(xs.checkUsuario("pedroperreira31@gmail.com"));
        CHECK_FALSE(xs.checkUsuario("pedroperreira31@gmail.com", "João Bastos"));

        xs.removerUsuario(p);
        CHECK_FALSE(xs.checkUsuario("pedroperreira31@gmail.com"));
    }
}

TEST_CASE("Alterando um Usuario") {
    Usuario p("Pedro", "Perreira", 20, "pedroperreira31@gmail.com");

    p.setNome("Gabriel", "Souza");
    p.setIdade("18");
    p.setEmail("gabrielsouza82@yahoo.com");

    CHECK_EQ(p.getNome(), "Gabriel Souza");
    CHECK_EQ(p.getIdade(), "18");
    CHECK_EQ(p.getEmail(), "gabrielsouza82@yahoo.com");
}
