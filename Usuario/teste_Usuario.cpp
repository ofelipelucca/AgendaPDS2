#include "doctest.hpp"
#include "Usuario.hpp"

TEST_CASE("Criando uma instância de Usuario") {
    std::string str1 = "Pedro";
    std::string str2 = "Perreira";
    std::string str3 = "pedroperreira31@gmail.com";
    std::string str4 = "20";

    Usuario p(str1, str2, str4, str3);

    SUBCASE("Verificando os campos do objeto") {
        CHECK_EQ(p.getNome(), "Pedro Perreira");
        CHECK_EQ(p.getIdade(), "20");
        CHECK_EQ(p.getEmail(), "pedroperreira31@gmail.com");
    }

    SUBCASE("Salvando o objeto na lista de usuarios") {
        std::string str1 = "pedroperreira31@gmail.com";
        std::string str2 = "João Bastos";

        ListaUsuario xs;

        xs.adicionarUsuario(&p);
        CHECK(xs.checkUsuario(&str1));
        CHECK_FALSE(xs.checkUsuario(&str1, &str2));

        xs.removerUsuario(&p);
        CHECK_FALSE(xs.checkUsuario(&str1));
    }
}

TEST_CASE("Alterando um Usuario") {
    std::string str1 = "Pedro";
    std::string str2 = "Perreira";
    std::string str3 = "pedroperreira31@gmail.com";
    std::string str4 = "20";

    Usuario p(str1, str2, str4, str3);

    std::string str5 = "18";
    std::string str6 = "gabrielsouza82@yahoo.com";

    p.setNome("Gabriel", "Souza");
    p.setIdade(&str5);
    p.setEmail(&str6);

    CHECK_EQ(p.getNome(), "Gabriel Souza");
    CHECK_EQ(p.getIdade(), "18");
    CHECK_EQ(p.getEmail(), "gabrielsouza82@yahoo.com");
}
