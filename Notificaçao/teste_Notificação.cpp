#include "doctest.hpp"
#include "Notificação.hpp"

TEST_CASE("Criando uma instância de Notificacao") {
    Notificacao n(0, 10);

    SUBCASE("Desativando a notificação") {
        CHECK(n.checkEstado());

        n.desativarNotificacao();
        CHECK_FALSE(n.checkEstado());
    }

    SUBCASE("Ativando a notificação") {
        n.desativarNotificacao();
        CHECK_FALSE(n.checkEstado());

        n.ativarNotificacao();
        CHECK(n.checkEstado());
    }
}
