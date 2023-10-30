#include <stdio.h>
#include "biblioteca.h"
// Luiz Fernando de Oliveira Lopes RA: 22.123.013-9
// Larissa Santos Fiuza RA: 22.123.042-8
// Cria a estrutura de tarefa, dando 3 parâmetros, priroidade, categoria e descrição

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
      
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  }

  printf("Programa encerrado. \n");
  return 0;
}


