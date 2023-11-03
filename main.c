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
          }
        getchar(); // Limpa o caractere de nova linha pendente
        break;
          case 5:
            if (clientes.qtd > 0) {
              char cpf[12];
              int deposito;
              printf("Digite o CPF do cliente que recebera o deposito: ");
              scanf("%s", cpf);
              getchar();
              printf("Digite o valor a ser depositado: ");
              scanf("%d", &deposito);
              int resultado = depositoCliente(&clientes, cpf, deposito);
              if (resultado == 1){
                // Salvar o cliente após o débito bem-sucedido
                salvarCliente(clientes, "Clientes.bin");
                printf("Cliente recebeu o depósito com sucesso.\n");
              } else {
                printf("Cliente não encontrado, senha incorreta ou saldo insuficiente.\n");
              }
              getchar(); // Limpa o caractere de nova linha pendente
              break;
            }
      case 6:
        if (clientes.qtd > 0){
          char cpf_remetente[12];
          int senha;
          char cpf_trans[12];
          int valor;
          printf("Digite o CPF do cliente que enviara o valor: ");
          scanf("%s", cpf_remetente);
          getchar();
          printf("Digite o CPF do Cliente que irá RECEBER:  ");
          scanf("%s", cpf_trans);
          printf("Digite sua senha: ");
          scanf("%d", &senha);
          printf("Digite o valor a ser transferido: ");
          scanf("%d", &valor);
          int resultado = transferencia(&clientes, cpf_remetente, senha, cpf_trans, valor);
          if (resultado == 1){
            salvarCliente(clientes, "Clientes.bin");
            printf("Transferência realizada com sucesso!!");
          } else{
            printf("Ocorreu um erro durante a transferência\n");
          }
          salvarCliente(clientes,"Clientes.bin");
        }
      case 7:
        printf("Programa encerrado. \n");
        return 0;
            getchar(); // Limpa o caractere de nova linha pendente
            break;
    }
  }
}