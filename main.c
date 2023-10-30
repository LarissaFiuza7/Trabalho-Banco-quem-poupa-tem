#include <stdio.h>
#include "biblioteca.h"
// Luiz Fernando de Oliveira Lopes RA: 22.123.013-9
// Larissa Santos Fiuza RA: 22.123.042-8
// Cria a estrutura de tarefa, dando 3 parâmetros, priroidade, categoria e descrição

int main() {
  ListaDeClientes clientes;
  clientes.qtd = 0;
  int sair = 0;

  ListaDeTransacoes Transacao;
  Transacao.qnt = 0;

  carregarCliente(&clientes, "Clientes.bin");
  carregarExtrato(&Transacao, "Transacoes.txt");

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
                salvarCliente(clientes, "Clientes.bin");
                salvarExtrato(Transacao, "Trasnacao.txt");
                printf("Cliente debitado com sucesso.\n");
            } else {
                printf("Cliente não encontrado ou senha incorreta.\n");
            }
        } else {
            printf("Nenhum cliente encontrado.\n");
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
        salvarExtrato(Transacao, "Trasnacao.txt");
        printf("Valor depositado com sucesso!.\n");
        } else{
        printf("Cliente não encontrado");
        }
      break;
      case 6:
      if (clientes.qtd > 0) {
        int cpf_contaDEB;
        int senha;
        int cpf_Trans;
        int valor_TRANS;
        printf("Digite o CPF do cliente a ser DEBITADO: ");
        scanf("%d", &cpf_contaDEB);
        getchar();
        printf("Digite a senha do cliente: ");
        scanf("%d", &senha);
        getchar();
        printf("Digite o CPF do cliente que vai RECEBER");
        scanf("%d", &cpf_Trans);
        printf("Digite o valor a ser transferido: ");
        scanf("%d", &valor_TRANS);
        transferenciaClientes(&clientes, cpf_contaDEB, senha, cpf_Trans, valor_TRANS);
        salvarCliente(clientes, "Clientes.bin");
        salvarExtrato(Transacao, "Trasnacao.txt");
        printf("Transferência realizada com sucesso.\n");
      } else{
        printf("Um dos clientes não foi encontrado");
      }
      break;
      case 7:
        if (Transacao.qnt > 0) {
          int cpf;
          int senha;
          printf("Digite o CPF do cliente: ");
          scanf("%d", &cpf);
          getchar(); // Limpa o caractere de nova linha pendente
          printf("Digite a senha:");
          scanf("%d", &senha);
          Extrato(&Transacao, cpf, senha);
          salvarExtrato(Transacao, "Trasnacao.txt");
        }
        break;
      case 8:
        sair = 1;
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  }

  printf("Programa encerrado. \n");
  return 0;
}
  

