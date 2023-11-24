#pragma once

#include <string>
#include <vector>

class PrimeiroMenu {
public:
  /// @brief Destrutor para destruiçao de subclasses
  virtual ~PrimeiroMenu() = default;

  /// @return O proximo menu.
  virtual PrimeiroMenu *next(unsigned opcao) = 0;

  /// @brief Renderiza as opçoes do menu.
  virtual void renderizar() const;
  
private:
  std::string titulo = "Gerenciador de Tarefas e Compromissos "; ///< Armazena o titulo do menu
  std::string segundotitulo = "Escolha uma opção:"; ///< Armazena o subtitulo do menu
  std::vector<std::string> opcoes = {"0 --> Sair"}; ///< Armazena as opçoes do menu+
  PrimeiroMenu *_anterior;
};