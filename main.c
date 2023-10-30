#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main() {
  ListaDeClientes clientes;
  clientes.qtd = 0;
  int sair = 0;

  carregarCliente(&clientes, "Clientes.bin");

  while (!sair) {
    printf("\nMenu:\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Deletar Cliente\n");
    printf("3. Listar Clientes\n");
    printf("4. Debito\n");
    printf("5. Deposito\n");
    printf("6. Transferencia\n");
    printf("7. Extrato\n");
    printf("8. Sair\n");
    printf("Escolha uma opção: ");

    char entrada[1000];
    fgets(entrada, sizeof(entrada), stdin);
    int opcao = atoi(entrada);

    switch (opcao) {
      case 1:
        cadastrarCliente(&clientes);
        salvarCliente(clientes, "Clientes.bin");
        break;
      case 2:
        if (clientes.qtd > 0) {
          int cpf;
          printf("Digite o CPF do cliente que será deletado: ");
          scanf("%d", &cpf);
          getchar(); // Limpa o caractere de nova linha pendente
          deletarCliente(&clientes, cpf);
          salvarCliente(clientes, "Clientes.bin");
        } else {
          printf("Não há clientes cadastrados. Nada para deletar.\n");
        }
        break;
      case 3:
        listarCliente(clientes);
        break;
      case 4:
        if (clientes.qtd > 0) {
          int cpf;
          int debito;
          int senha;
          printf("Digite o CPF do cliente a ser debitado: ");
          scanf("%d", &cpf);
          printf("Digite a senha do cliente: ");
          scanf("%d", &senha);
          getchar(); // Limpa o caractere de nova linha pendente
          printf("Digite o valor a ser debitado: ");
          scanf("%d", &debito);
          int resultado = debitoCliente(&clientes, cpf, senha, debito);
          if (resultado == 1) {
            printf("Cliente debitado com sucesso.\n");
          } else {
            printf("Cliente não encontrado ou senha incorreta.\n");
          }
        } else {
          printf("Nenhum cliente encontrado.\n");
        }
        break;
      case 8:
        printf("Programa encerrado.\n");
        sair = 1;
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  }

  return 0;
}