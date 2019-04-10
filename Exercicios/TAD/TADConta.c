#include <stdio.h>
#include "TADConta.h"

void inicializa(ContaBancaria* conta, int numero) {
    (*conta).numero = numero;
    (*conta).saldo = 0.0;
}
void deposito(ContaBancaria* conta, double valor) {
    (*conta).saldo += valor;
}
void saque(ContaBancaria* conta, double valor) {
    (*conta).saldo -= valor;
}
void imprime(ContaBancaria conta) {
    printf("Numero: %d\n", conta.numero);
    printf("Saldo: R$%g\n", conta.saldo);
}
