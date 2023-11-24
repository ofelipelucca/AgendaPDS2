#pragma once
#include <string>
#include <unordered_map>
   
class Usuario {
public:
   Usuario(std::string& nome, std::string& sobrenome, std::string& idade, std::string& email);
    
   /// @brief Busca pelo nome do usuario 
   ///
   /// @return String do nome
   std::string getnome() const;
   
   /// @brief Busca pelo email do usuario 
   ///
   /// @return String do email
   std::string getemail() const; 
    
   /// @brief Muda o email de um usuario
   ///
   /// @param texto O email a ser alterado
   void mudaremail (std::string texto);
      
private:
   std::string _nome; ///< Armazena o primeiro nome do usuario
   std::string _sobrenome; ///< Armazena o sobrenome do usuario
   std::string _idade; ///< Armazena a idade do usuario
   std::string _email; ///< Armazena o email do usuario
};

class ListaUsuario {
public:
  ListaUsuario();
  ~ListaUsuario();

  /// @brief Adiciona um Usuario a lista de Usuarios
  ///
  /// @param usuario O Usuario a ser adicionado
  void adicionarUsuario(Usuario* usuario);

  /// @brief Remove um Usuario da lista de Usuarios
  ///
  /// @param usuario O Usuario a ser removido
  void removerUsuario(Usuario* usuario);

  /// @brief Checar se o usuario existe
  ///
  /// @details Verifica se o email ja esta cadastrado
  ///
  /// @param usuario O usuario a ser verificado
  ///
  /// @return True se o usuario existe, false caso contrario 
  bool checkUsuario(Usuario& usuario);

private:
  std::unordered_map<std::string, Usuario> _listadeusuario; ///< Armazena a lista de usuarios
};  