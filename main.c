/* GRUPO
Juliana Mayumi Kamiguchi Watanabe RA: 21485295
Kathyllin Silva de Souza RA:21509412
Rafael Martins das Chagas RA: 21504756*/

/* Features implementadas*/

/* Observações*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct func {
  int id;
  char nome[50];
  long cpf;
  int dia;
  int mes;
  int ano;
} tFuncionario;

// Declaração das funções
void show_menu();
void register_employee();
void list_employees();

// Variáveis Globais
tFuncionario employees_list[5];
int employees_quantity = 1;

/* Para deixar a função main mais legível foi colocado apenas a chamada da função do menu*/
int main() {
  show_menu();
  return 0;
} // Fim da main()

/* Esse menu faz parte da implementação obrigatória, o menu vai continuar
sendo exibido enquanto a opção 3 não for selecionada, pois essa opção 
altera o valor da variavel que controla o loop. Caso o usuário selecione
a opção 1 a função register_employee será chamada para realizar o cadastro dos funcionários, já a opção 2 chama a função list_employees que lista os funcionários cadastrados no sistema */
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
      case 2:
        list_employees();
      break;
      case 3:
        keep_runnning = 0;
      break;
    }
  }
}

void register_employee() {
  tFuncionario dados;
  dados.id = employees_quantity;

  for (int i = 0; i < 5; i++){
    char add_more = 's';

    // Leitura dos dados
    printf("\nDigite o nome do funcionario: ");
    scanf(" %[^\n]s", employees_list[i].nome);
    printf("\nDigite o CPF: ");
    scanf("%li", &employees_list[i].cpf);
    printf("\nDigite a data de nascimento: ");
    printf("\n(Ex: 12 03 2014)\n");
    scanf("%i %i %i", &employees_list[i].dia, &employees_list[i].mes, &employees_list[i].ano);

    dados.id++;
    employees_quantity++;

    if(i < 4){
      printf("Deseja inserir mais algum funcionario? (s/n)\n");
      scanf(" %c", &add_more);
    }


    if (tolower(add_more) != 's'){
      break;
    }
  }
  
}

void list_employees(){
  for (int i = 0; i < employees_quantity; i++){
    printf("\n%s", employees_list[i].nome);
  }
}
