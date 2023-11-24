#pragma once

#include <string>
#include <list>

/// @brief Obtem a cor para imprimir de acordo com o nivel de prioridade
///
/// @details Prioridade 1: Verde, Prioridade 2: Amarelo, Prioridade 3: Vermelho
///
/// @param prioridade A prioridade da tarefa ou compromisso
///
/// @return String com o codigo da cor (em formataçao ANSI) 
std::string setCorPrioridade(unsigned prioridade);

class Tarefa {
public:
  Tarefa(std::string& titulo, std::string& descricao, std::string& data, unsigned prioridade, std::string& estado);
    
  /// @brief Busca pelo titulo da tarefa 
  ///
  /// @return String do titulo
  std::string getTitulo() const;

  /// @brief Busca pela descriçao da tarefa
  /// 
  /// @return String da descriçao 
  std::string getDescricao() const;

  /// @brief Busca pela data da tarefa
  ///
  /// @return String da data
  std::string getData() const;

  /// @brief Busca pela prioridade da tarefa
  ///
  /// @return Unsigned (1, 2 ou 3)
  unsigned getPrioridade() const;
    
  /// @brief Busca pelo estado da tarefa
  ///
  /// @return String do estado (feito, em progresso, nao feito)
  std::string getEstado() const; 
  
  /// @brief Muda o titulo de uma tarefa
  ///
  /// @param novoTitulo O novo titulo a ser colocado
  void setTitulo(const std::string& novoTitulo);

  /// @brief Muda a descriçao de uma tarefa
  ///
  /// @param novaDescricao A nova descriçao a ser colocada
  void setDescricao(const std::string& novaDescricao);

  /// @brief Muda a data de uma tarefa
  ///
  /// @param novaData A nova data a ser colocada
  ///
  /// @attention A data informada deve estar no formato: DD/MM/AAAA
  void setData(const std::string& novaData);

  /// @brief Muda a prioridade de uma tarefa
  ///
  /// @param novaPrioridade A nova prioridade a ser colocada
  ///
  /// @attention A prioridade varia entre: 
  /// 1 --> menos importante, 2 --> importante, 3 --> muito importante.
  void setPrioridade(unsigned novaPrioridade);

  /// @brief Muda o estado de uma tarefa
  ///
  /// @param novoEstado O novo estado a ser colocado
  ///
  /// @attention O estado varia entre: feito deletar em seguida), em progresso, não feito (alertar).
  void setEstado(const std::string& novoEstado);
   
private:
  std::string _titulo; ///< Armazena o titulo da tarefa 
  std::string _descricao; ///< Armazena a descricao da tarefa
  std::string _data; ///< Armazena a data (em string) da tarefa 
  unsigned _prioridade; ///< Armazena a prioridade da tarefa 
  std::string _estado; ///< Armazena o estado da tarefa 
 };

class Compromisso : public Tarefa {
public:
  Compromisso(std::string& data, std::string& local,std::string& titulo, std::string& descricao, std::string& horario, std::string& estado, unsigned prioridade);

  /// @brief Busca pela cor do compromisso
  ///
  /// @return String com o codigo em formataçao ANSI da cor
  std::string getCor() const;

  /// @brief Busca pelo local do compromisso
  ///
  /// @return String do local  
  std::string getLocal() const;

  /// @brief Busca pelo horario do compromisso
  ///
  /// @return String do horario 
  std::string getHorario() const;

  /// @brief Muda a cor de um compromisso
  ///
  /// @details Necessario para organizaçao dos compromissos por cor
  ///
  /// @attention Cores aceitas: 'laranja', 'azul', 'roxo', 'rosa'
  ///
  /// @param novaCor A nova cor a ser adicionada
  void setCor(const std::string& novaCor);

  /// @brief Muda o local de um compromisso
  ///
  /// @param novoLocal O novo local a ser colocado 
  void setLocal(const std::string& novoLocal);

  /// @brief Muda o horario de um compromisso
  ///
  /// @param novoHorario O novo horario a ser colocado
  ///
  /// @attention O horario informado deve estar no formato: HH:MM:SS
  void setHorario(const std::string& novoHorario);

private:
  std::string _cor; ///< Armazena a cor do comprimisso, escolhida pelo usuario
  std::string _local; ///< Armazena o local do compromisso
  std::string _horario; ///< Armazena o horario do comprimisso
};

class ListaTarefa {
public:
  //ListaTarefa();
  //~ListaTarefa();

  /// @brief Adiciona uma tarefa na lista de tarefas
  ///
  /// @param tarefa a tarefa a ser adicionada
  void adicionarTarefa(Tarefa* tarefa);

  /// @brief Remove uma tarefa da lista de tarefas
  ///
  /// @param tarefa a Tarefa a ser removida
  void removerTarefa(Tarefa* tarefa);

  /// @brief Mostra a lista de tarefas
  void verTarefas() const;
  
private:
  std::list<Tarefa> _listadeTarefa; ///< Armazena a lista de tarefas
};

class ListaCompromisso {
public:
  //ListaCompromisso();
  //~ListaCompromisso();

  /// @brief Adiciona um compromisso a lista de compromissos
  ///
  /// @param compromisso O compromisso a ser adicionado
  void adicionarCompromisso(Compromisso* compromisso);

  /// @brief Remove um compromisso da lista de compromissos
  ///
  /// @param compromisso O compromisso a ser removido
  void removerCompromisso(Compromisso* compromisso);

  /// @brief Mostra os compromisso da lista de compromissos
  void verCompromissos() const;

private:
  std::list<Compromisso> _listadeCompromisso; ///< Armazena a lista de comprimissos
};
