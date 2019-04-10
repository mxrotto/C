
typedef struct {
 int numero;
 double saldo;
} ContaBancaria;

void inicializa(ContaBancaria* conta, int numero);
void deposito (ContaBancaria* conta, double valor);
void saque (ContaBancaria* conta, double valor);
void imprime (ContaBancaria conta);
