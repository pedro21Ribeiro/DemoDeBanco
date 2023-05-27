#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Eder Venancio, Pedro Silva, Victor Nascimento


struct pessoa{
  int id;
  int agencia;
  int contaCorrente;
  float saldo;
  char nome[50];
};

int contador = 0;
struct pessoa cliente[100];



//L I N H A
void linha(){
  printf("---------------------------------------------------------------------\n");
}

void adicionarCliente(int id){
  int agencia;
  int contaCorrente;
  float saldo;
  char nome[50];
  char str2[50];


  saldo = 0;

  printf("Digite o Nome (Máximo 50 caracteres):  ");
  scanf("%s", &nome);
  printf("Digite o Numero da Agencia:  ");
  scanf("%d", &agencia);
  printf("Digite o numero da conta:  ");
  scanf("%d", &contaCorrente);
  

  strcpy(cliente[id].nome, nome);
  cliente[id].agencia = agencia;
  cliente[id].contaCorrente = contaCorrente;
  cliente[id].saldo = saldo;
  cliente[id].id = id;
  
  contador++;
}

float consultarSaldo(int id){
  return (cliente[id].saldo);
}

void retirarSaldo(int id, float valor){
  if (valor > cliente[id].saldo){
    printf("\nOperação cancelada saldo insuficiente.\n");
  }
  else{
    cliente[id].saldo -= valor;
    printf("\nO saldo atual após a transação é: %0.2f \n", consultarSaldo(id));
  }
}


void consultarDados(int id)
{
  printf("\n ID Cliente: %d  |\n", cliente[id].id);
  printf("\n Nome do Cliente: %s  |\n", cliente[id].nome);
  printf("\n Agencia: %d  |\n", cliente[id].agencia);
  printf("\n Numero Conta Corrente: %d  |\n", cliente[id].contaCorrente);
  printf("\n Saldo: %0.2f  |\n", cliente[id].saldo);
}


void depositarSaldo(int id, float valor)
{
    cliente[id].saldo += valor;
    printf("\n O saldo atual após a transação é: %0.2f \n", consultarSaldo(id));
}




void menu()
{
  int operacao;
  
  printf("\nDigite a operação que deseja realizar \n1: Sacar \n2: Depositar \n3: Transferência\n4: Pix: \n5: Consultar Saldo: \n6: Consultar Todos os Dados\n7: Registrar Cliente\n8: Sair\n");
  scanf("%d", &operacao);
  switch(operacao){
    int id;
    int id2;
    float valor;
    case 1:
      // Sacar valor
        printf("\nDigite o id da conta que deseja sacar:  ");
        scanf("%d", &id);
        printf("\nDigite o valor a sacar:  ");
        scanf("%f", &valor);
        retirarSaldo(id, valor);
        linha();
        menu();
    break;
  
    case 2:
      // Depositar valor
      printf("\nDigite o id da conta que deseja depositar:  ");
        scanf("%d", &id);
        printf("\nDigite o valor que deseja depositar:  ");
        scanf("%f", &valor);
        depositarSaldo(id, valor);
      linha();
        menu();
      
      
    break;

    case 3:
      // transferencia de contas
        printf("\nDigite o ID da conta a Tranferir: ");
        scanf("%d", &id);
        printf("\nDigite o ID da conta que deseja Receber: ");
        scanf("%d", &id2);
        printf("\nDigite o valor que deseja transferir: ");
        scanf("%f", &valor);
        retirarSaldo(id, valor);
        depositarSaldo(id2, valor);
      linha();
        menu();
      

    break;

    case 4: 
      // realizar pix
         printf("\nDigite o ID da conta a fazer o pix: ");
        scanf("%d", &id);
        printf("\nDigite o ID da conta que deseja fazer o Receber: ");
        scanf("%d", &id2);
        printf("\nDigite o valor que deseja fazer o Pix: ");
        scanf("%f", &valor);
        retirarSaldo(id, valor);
        depositarSaldo(id2, valor);
        linha();
        menu();
    break;

    case 5: 
    // consultar saldo
    printf("\nDigite o id da conta que deseja consultar o saldo:  ");
        scanf("%d", &id);
    printf("O saldo da conta é:  %0.2f\n", consultarSaldo(id));
    linha();
    menu();
    break;
    
    case 6:
    // consultar todos dados
    printf("Digite O ID da conta que deseja ");
    scanf("%d", &id);
    consultarDados(id);  
      linha();
      menu();

    break;

    case 7:
      // registro cliente

      adicionarCliente(contador);
      linha();
      menu();

    break;
  
    case 8:
      printf("Encerramento do programa\n");
      linha();
      exit(0);

    break;

    default:
  printf("Operação inválida\n");
    linha();
    menu();
    break;
      
       
  }

}


int main(void) {
  menu();
  return 0;
}