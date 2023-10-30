#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

// Função de atualizar a lista toda vez que ela for usada
void salvarCliente(ListaDeClientes lt, const char *clientes) {
  FILE *arquivo = fopen(clientes, "wb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  fwrite(&lt, sizeof(ListaDeClientes), 1, arquivo);
  fclose(arquivo);
}
// Carregar a lista quando precisar acessá-la
void carregarCliente(ListaDeClientes *lt, const char *clientes) {
  FILE *arquivo = fopen(clientes, "rb");
  if (arquivo == NULL) {
    printf("Arquivo de lista não encontrado. Iniciando com lista vazia.\n");
    return;
  }

  fread(lt, sizeof(ListaDeClientes), 1, arquivo);
  fclose(arquivo);
}

// Função de cadastra cliente, dando os parâmetros necessaríos
void cadastrarCliente(ListaDeClientes *lt) {
  if (lt->qtd < 100) {
    Cliente novoCliente;
    //Cadastra o nome do cliente
    printf("Digite o nome do novo cliente: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    novoCliente.nome[strlen(novoCliente.nome) - 1] = '\0'; 
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descarta o caractere lido
    }
    //Cadastra o CPF do cliente
    printf("Digite o CPF do novo cliente: ");
    fgets(novoCliente.CPF, sizeof(novoCliente.CPF), stdin);
    novoCliente.CPF[strlen(novoCliente.CPF) - 1] = '\0';
    int d;
    while ((d = getchar()) != '\n' && d != EOF) {
        // Descarta o caractere lido
    }
    //Cadastra o tipo de conta do cliente
    printf("Digite o tipo de conta escolhido comum ou plus: ");
    fgets(novoCliente.tipo_conta, sizeof(novoCliente.tipo_conta), stdin);
    novoCliente.tipo_conta[strlen(novoCliente.tipo_conta) - 1] = '\0'; 
    int e;
    while ((e = getchar()) != '\n' && e != EOF) {
        // Descarta o caractere lido
    }
    //Cadastra o saldo do cliente
    printf("Digite o saldo inicial da conta");
    scanf("%d", &novoCliente.valor_inicial);
    getchar(); 
    //Cadastra a senha do cliente
    printf("Digite a senha: ");
    scanf("%d", &novoCliente.senha);
    getchar(); 
    // Remove o caractere de nova linha
    lt->clientes[lt->qtd] = novoCliente;
    lt->qtd++;
    printf("Cliente cadastrado com sucesso!\n");
  } else {
    printf("O armazenamento está cheio. Não é possível cadastrar novos Clientes.\n");
  }
}
//Função Deletar Cliente
int deletarCliente(ListaDeClientes *lt, int cpf) {
  char cpf_str[12];
  snprintf(cpf_str, sizeof(cpf_str), "%d", cpf);

  for (int i = 0; i < lt->qtd; i++) {
    if (strcmp(lt->clientes[i].CPF, cpf_str) == 0) {
      printf("Cliente excluído com sucesso\n");
      for (int j = i; j < lt->qtd - 1; j++) {
        lt->clientes[j] = lt->clientes[j + 1];
      }
      lt->qtd--;
      return 1;
    }
  }
  printf("Cliente não encontrado\n");
  return 0;
}

// Lista todos os clientes
void listarCliente(ListaDeClientes lt) {
  if (lt.qtd == 0) {
    printf("Não há clientes para serem listados.\n");
    return;
  }

  for (int i = 0; i < lt.qtd; i++) {
    printf("\nCliente: %s\n", lt.clientes[i].nome);
    printf("CPF: %s\n",lt.clientes[i].CPF);
    printf("Tipo de conta: %s\n", lt.clientes[i].tipo_conta);
    printf("Saldo: %d\n", lt.clientes[i].valor_inicial);
  }
}
// Função de Debito
int debitoCliente(ListaDeClientes *lt, const char *cpf, int senha, int debito) {
    int i;
    int index = -1;

    for (i = 0; i < lt->qtd; i++) {
        if (strcmp(lt->clientes[i].CPF, cpf) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("CPF não encontrado.\n");
        return 0;
    }

    printf("Digite sua senha: ");
    int Senha;
    scanf("%d", &Senha);

    if (lt->clientes[index].senha != Senha) {
        printf("Senha incorreta.\n");
        return 0;
    }

    if (strcmp(lt->clientes[index].tipo_conta, "Comum") == 0) {
        if (lt->clientes[index].valor_inicial - debito < -1000) {
            printf("Saldo insuficiente.\n");
            return 0;
        }
    } else if (strcmp(lt->clientes[index].tipo_conta, "Plus") == 0) {
        if (lt->clientes[index].valor_inicial - debito < -5000) {
            printf("Saldo insuficiente.\n");
            return 0;
        }
    }

    lt->clientes[index].valor_inicial -= debito;
    printf("Débito realizado com sucesso.\n");
    return 1;
}

//Função de Depósito
void depositoCliente(ListaDeClientes *lt, int cpf, int deposito) {
  char cpf_str[12]; 
  snprintf(cpf_str, sizeof(cpf_str), "%d", cpf);
  int i;
  for (i = 0; i < lt->qtd; i++) {
    if (strcmp(lt->clientes[i].CPF, cpf_str) == 0) {
        lt->clientes[i].valor_inicial += deposito;
        printf("Deposito realizado com sucesso.\n");
        break;
    }
}
    if (i < 0) {
        printf("CPF não encontrado.\n");
        return;
    }
}
