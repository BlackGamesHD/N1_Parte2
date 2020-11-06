/* GRUPO
Juliana Mayumi Kamiguchi Watanabe RA: 21485295
Kathyllin Silva de Souza RA:21509412
Rafael Martins das Chagas RA: 21504756*/

/* Features livres implementadas
- Inserção do campo e validação do turno de trabalho do funcionario
- Criação de um arquivo .h contendo duas funções de validação
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validation.h"

typedef struct func {
  int id;
  char nome[50];
  char cpf[12];
  char dia[3];
  char mes[3];
  char ano[5];
  char turno;
} tFuncionario;


void show_menu();
void register_employee();
void list_employees();


tFuncionario employees_list[5];
int employees_quantity = 1;


int main() {
  show_menu();
  return 0;
}

/* Esse menu faz parte da implementação obrigatória, o menu vai continuar
sendo exibido enquanto a opção 3 não for selecionada, pois essa opção 
altera o valor da variavel que controla o loop. Caso o usuário selecione
a opção 1 a função register_employee será chamada para realizar o cadastro dos funcionários, já a opção 2 chama a função list_employees que lista os funcionários cadastrados no sistema. O primeiro nome da lista de funcionarios é inicializado como 0 para fazer a verificação da existencia ou nao de um funcionario
*/
void show_menu() {
  int keep_runnning = 1;
  int option;

  employees_list[0].nome[0] = '0';

  while (keep_runnning == 1){
    printf("\nBem vindo, escolha uma opção\n");
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

/* Essa parte faz parte das features obrigatorias, ele faz parte do menu e é responsável por registrar os funcionarios.
Primeiramente o id é setado de acordo com a quantidade de funcionarios já registrados (Na primeira execucação esse valor será 1)
*/
void register_employee() {
  tFuncionario dados;
  dados.id = employees_quantity;

  for (int i = 0; i < 5; i++){

    char tempName[50];
    char tempWorkShift;

    do{
      printf("\nDigite o nome do funcionario: ");
      scanf(" %[^\n]s", tempName);
      strncpy(employees_list[i].nome, tempName, 49);
    } while (is_Name_Valid(tempName) == 0);
    
    
    printf("\nDigite o CPF: ");
    scanf("%s", employees_list[i].cpf);
    printf("\nDigite a data de nascimento: ");
    printf("\n(Ex: 12 03 2014)\n");
    scanf("%s %s %s", employees_list[i].dia, employees_list[i].mes, employees_list[i].ano);

    do{
      printf("\nDigite o turno do funcionario(m-Matutino, v-Vespertino):\n");
      scanf(" %[^\n]s", &tempWorkShift);
      employees_list[i].turno = tempWorkShift;
    } while (is_Workshift_Valid(tempWorkShift) == 0);
    

    employees_quantity++;

    if(i < 4){
      char add_more = 's';
      printf("Deseja inserir mais algum funcionario? (s/n)\n");
      scanf(" %c", &add_more);
      if (tolower(add_more) != 's'){
        break;
      }
    }
  } 
}

void list_employees(){
  if (employees_list[0].nome[0] == '0'){
      printf("\n\n Não há nenhum funcionario cadastrado\n\n");
      return;
  }

  printf("Nome\t\t\tCPF\t\t\tData de nascimento\t\tTurno\n");

  for (int i = 0; i < employees_quantity; i++){
    printf("\n%s\t\t%8s\t%8s/%s/%s\t\t\t\t%c", employees_list[i].nome, employees_list[i].cpf, employees_list[i].dia, employees_list[i].mes, employees_list[i].ano,employees_list[i].turno);
  }

}
