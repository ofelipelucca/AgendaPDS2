#pragma once
#include <string>
#include <list>
   
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
   std::string nome; ///< Armazena o primeiro nome do usuario
   std::string sobrenome; ///< Armazena o sobrenome do usuario
   std::string idade; ///< Armazena a idade do usuario
   std::string email; ///< Armazena o email do usuario
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

  /// @brief Mostra os Usuario da lista de Usuarios
  void verUsuarios() const;

private:
  std::list<Usuario> _listadeusuario; ///< Armazena a lista de usuarios
};
