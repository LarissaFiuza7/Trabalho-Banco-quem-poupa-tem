#ifndef PROJET_1_BIBLIOTECA_H
#define PROJET_1_BIBLIOTECA_H

// Cria um cadastro de um cliente usando os parâmetros das variáveis nome, cpf, tipo da conta, saldo inicial e a senha
typedef struct {
  char nome[100];
  char CPF[12];
  char tipo_conta[6];
  int valor_inicial;
  int senha;
} Cliente;

// Cria a lista de clientes
typedef struct {
  Cliente clientes[1000];
  int qtd;
} ListaDeClientes;

// Variaveis
void cadastrarCliente(ListaDeClientes *lt);
void salvarCliente(ListaDeClientes lt, const char *cliente);
void carregarCliente(ListaDeClientes *lt, const char *cliente);
int deletarCliente(ListaDeClientes *lt, int cpf);
#endif // PROJET_1_BIBLIOTECA_H