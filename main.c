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