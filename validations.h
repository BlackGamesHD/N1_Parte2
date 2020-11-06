/*Essa função serve para validar o nome, ela recebe o nome do funcionario e faz um loop em cada caracter do nome procurando por algo que seja diferente de um espaço, se ela achar ela verifica se esse caracter faz parte do alfabeto, se ela não preencher nenhum desses dois requesitos a função retorna o valor 0, o que significa que o nome é invalido*/
int is_Name_Valid(char name[50]){
  for (int i = 0; i < strlen(name); i++){
    if (name[i] != ' '){
      if (isalpha(name[i]) == 0){
        return 0;
      }
    }
  }
  return 1;
}

/*Essa função serve para validar o turno do funcionario, ela recebe um char e verifica se esse char corresponde a um dos turnos válidos (m ou v). Caso seja invalido a função retorna 0, o que significa que o turno é invalido. A funcao 'tolower' é utilizada para caso o usuario digite um turno valido, mas com letra maiuscula*/
int is_Workshift_Valid(char workShift){
  if (tolower(workShift) != 'm' && tolower(workShift) != 'v'){
    return 0;
  }
  return 1;
}