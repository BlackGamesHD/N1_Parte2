/* GRUPO
Juliana Mayumi Kamiguchi Watanabe    RA: 21485295
Kathyllin Silva de Souza RA:21509412
Rafael Martins das Chagas RA: 21504756*/

/* Features implementadas*/

/* Features implementadas*/

#include <stdio.h>
#include <stdlib.h>

typedef struct func {
  int id;
  char nome[50];
  long cpf;
  int dia;
  int mes;
  int ano;
} tFuncionario;

void show_menu();
void register_employee();

int main() {
  show_menu();
  return 0;
} // Fim da main()

void show_menu() {
  int keep_runnning = 1;
  int option;

  while (keep_runnning == 1){
    printf("Bem vindo, escolha uma opção\n");
    printf("1 - Cadastrar funcionário\n");
    printf("2 - Listar funcionários\n");
    printf("3 - Sair\n");
    scanf("%i", &option);

    switch (option){
      case 1:
        register_employee();
      break;
      case 3:
        keep_runnning = 0;
      break;
    }
  }
}

void register_employee() {
  tFuncionario dados;
  dados.id = 1;

  // Leitura dos dados
  printf("\nDigite o nome do funcionario: ");
  scanf(" %[^\n]s", dados.nome);
  printf("\nDigite o CPF: ");
  scanf("%li", &dados.cpf);
  printf("\nDigite a data de nascimento: ");
  printf("\n(Utilize espaco para separar dia, mes e ano. Ex: 12 03 2014)\n");
  scanf("%i %i %i", &dados.dia, &dados.mes, &dados.ano);
  
}