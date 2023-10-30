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
        getchar(); // Limpa o caractere de nova linha pendente
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
        getchar(); // Limpa o caractere de nova linha pendente
        break;
      case 3:
        listarCliente(clientes);
        getchar(); // Limpa o caractere de nova linha pendente
        break;
      case 4:
        if (clientes.qtd > 0) {
          char cpf[12];
          int debito;
          int senha;

          printf("Digite o CPF do cliente a ser debitado: ");
          scanf("%s", cpf);

          printf("Digite o valor a ser debitado: ");
          scanf("%d", &debito);

          int resultado = debitoCliente(&clientes, cpf, senha, debito);

          if (resultado == 1) {
              // Salvar o cliente após o débito bem-sucedido
              salvarCliente(clientes, "Clientes.bin");
              printf("Cliente debitado com sucesso.\n");
          } else {
              printf("Cliente não encontrado, senha incorreta ou saldo insuficiente.\n");
          }

          return 0;
          }
        break;
      case 5:
      if (clientes.qtd > 0) {
        int cpf;
        int deposito;
        printf("Digite o CPF do cliente: ");
        scanf("%d", &cpf);
        getchar(); // Limpa o caractere de nova linha pendente
        printf("Digite o valor a ser depositado:");
        scanf("%d", &deposito);
        depositoCliente(&clientes, cpf, deposito);
        salvarCliente(clientes, "Clientes.bin");
        } else{
        printf("Cliente não encontrado");
        }
        getchar(); // Limpa o caractere de nova linha pendente
        break;
      case 8:
        printf("Programa encerrado.\n");
        sair = 1;
        getchar(); // Limpa o caractere de nova linha pendente
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  }

  return 0;
}
