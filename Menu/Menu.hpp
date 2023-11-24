#pragma once

#include <string>
#include <vector>

class PrimeiroMenu {
public:
  /// @brief Destrutor para destruiçao de subclasses
  virtual ~PrimeiroMenu() = default;

  /// @return O proximo menu.
  virtual PrimeiroMenu *next(unsigned opcao) = 0;

  /// @brief Busca pelo usuario logado
  ///
  /// @return String com email do usuario logado
  std::string getUsuario() const;

  /// @brief Guarda o usuario logado
  ///
  /// @param user_email O email do usuario logado 
  void setUsuario(std::string user_email);

  /// @brief Muda o titulo do menu
  ///
  /// @param novoTitulo O novo titulo do menu
  void setTitulo(std::string novoTitulo);

  /// @brief Muda o subtitulo do menu
  ///
  /// @param novoSubtitulo O novo subtitulo do menu
  void setSubtitulo(std::string novoSubtitulo);

  /// @brief Muda as opcoes do menu
  ///
  /// @param novasOpcoes As novas opcoes a serem adicionadas
  void setOpcoes(std::vector<std::string> novasOpcoes);

  /// @brief Renderiza as opçoes do menu.
  virtual void renderizar() const;
  
private:
  std::string _user_email; ///< Armazena o email do usuario logado
  std::string _titulo = "Gerenciador de Tarefas e Compromissos "; ///< Armazena o titulo do menu
  std::string _subtitulo = "Escolha uma opção:"; ///< Armazena o subtitulo do menu
  std::vector<std::string> _opcoes = {"1 --> Entrar", "2 --> Sair"}; ///< Armazena as opçoes do menu
  PrimeiroMenu *_anterior; ///< Armazena o ponteiro para o menu anterior
};