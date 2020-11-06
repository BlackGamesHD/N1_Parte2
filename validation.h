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

int is_Workshift_Valid(char workShift){
  if (tolower(workShift) != 'm' && tolower(workShift) != 'v'){
    return 0;
  }
  return 1;
}