#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//Funções e Procedimentos:
bool maiuscula(char n){
  if(n>='A' && n<='Z'){
    return true;
  }
  else{
    return false;
  }
}
bool digit(char n){
  if(n>='0' && n<='9'){
    return true;
  }
  else{
    return false;
  }
}
bool letra(char n){
  if((n>='A' && n<='Z')||(n>='a' && n<='z')){
    return true;
  }
  else{
    return false;
  }
}
void menu(){
  int nmenu = 10;
  while(nmenu > 0){
    printf("Para Exercicio %d, aperte %d \n \n",nmenu,nmenu);
    nmenu --;
      }
  printf("Digite 0 para sair \n");
}
char* smaller_k_show(char vec[]){
  int i = 0, contador = 0;
  char *aux = calloc ( 80, sizeof(char) );
  for(i = 0;i<strlen(vec);i++){
    if(vec[i]<'K' && vec[i]>='A'){
      aux[contador] = vec[i];
      contador ++;
    }
  }
  return aux;
}
char* smaller_ks_show(char vec[]){
  int i = 0, contador = 0;
  char *aux = calloc ( 80, sizeof(char) );
  for(i = 0;i<strlen(vec);i++){
    if((vec[i]<'K' && vec[i]>='A')||(vec[i]<'k' && vec[i]>='a')){
      aux[contador] = vec[i];
      contador ++;
    }
  }
  return aux;
}
int odd_in_string(char vec[]){
  int i = 0, contador = 0;
  for(i = 0;i<strlen(vec);i++){
    if(vec[i]%2 != 0){
      contador ++;
    }
  }
  return contador;
}
char* non_alphanum(char vec[]){
  int i = 0, contador = 0;
  char *aux = calloc ( 80, sizeof(char) );
  for(i = 0;i<strlen(vec);i++){
    if(!digit(vec[i]) && !letra(vec[i])){
      aux[contador] = vec[i];
      contador ++;      
    }
  }
  return aux;
}
char* alphanum(char vec[]){
  int i = 0, contador = 0;
  char *aux = calloc ( 80, sizeof(char) );
  for(i = 0;i<strlen(vec);i++){
    if(digit(vec[i])||letra(vec[i])){
      aux[contador] = vec[i];
      contador ++;      
    }
  }
  return aux;
}
 
//Exercícios:
void exercicio1(){
  double a = 0, b = 0, x = 0;
  int n = 0, i = 0, contador = 0, contador1 = 0;
  printf("Digite um valor real: ");
  scanf("%lf",&a);
  printf("Digite um valor real: ");
  scanf("%lf",&b);
  printf("Digite a quantidade de numeros a serem testados: ");
  scanf("%d",&n);
  double vetor[n];
  for(i = 0;i<n;i = i + 1){
    printf("Digite um valor real: ");
    scanf("%lf",&x);
    if(x>=a && x<=b){
      vetor[contador] = x;
      contador ++;
    }
    else{
      contador1 ++;
    }
  }
  for(i = 0; i < contador; i++){
    printf("%lf \n",vetor[i]);
  }
  printf("A quantidade de numeros dentro do intervalo é: %d \n",contador);
  printf("A quantidade de numeros fora do intervalo é: %d\n",contador1);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio2(){
  char palavra[1000];
  int i = 0, contador = 0, tamanho = 0;
  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  tamanho = strlen(palavra);
  printf("As letras que encaixam nesse padrão são: \n");
  for(i=0;i<tamanho;i++){
    if(maiuscula(palavra[i])&& palavra[i]<'K'){
      printf("%c \n",palavra[i]);
      contador ++;
    }
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio3(){
  char palavra[1000];
  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  int soma = strlen(smaller_k_show(palavra));
  printf("A quantidade de letras é: %d\n\n",soma);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio4(){
  char palavra[1000];
  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  printf("As letras são: %s",smaller_k_show(palavra));
  printf("\n Digite ENTER para continuar");
  getchar();
}
void exercicio5(){
  char palavra[1000];
  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  int soma = strlen(smaller_ks_show(palavra));
  printf("A quantidade de letras é: %d\n\n",soma);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio6(){
  char palavra[1000];
  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  printf("As letras são: %s",smaller_ks_show(palavra));
  printf("\n Digite ENTER para continuar");
  getchar();
}
void exercicio7(){
  char palavra[1000];
  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  printf("São: %d números ímpares \n\n",odd_in_string(palavra));
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio8(){
  char palavra[1000];
  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  printf("São: %s os caracteres diferentes \n\n",non_alphanum(palavra));
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio9(){
  char palavra[1000];
  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  printf("São: %s os caracteres alfanum \n\n",alphanum(palavra));
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio10(){
  char palavra[1000];
  int i = 0, n = 0, soma = 0;
  printf("Quantas palavras serão inseridas?\n");
  scanf("%d",&n);
  for(i = 0;i < n; i++){
    printf("Digite uma palavra: ");
    scanf("%s",palavra);
    soma = soma + strlen(alphanum(palavra));
  }
  printf("A quantidade de caracteres alfanum é: %d\n",soma);
  printf("Esses caracteres são: %s",alphanum(palavra));
  printf("Digite ENTER para continuar");
  getchar();
}
int main(void) {
  int exercicio;
  menu();
  do{
    scanf("%d",&exercicio);
    switch(exercicio){
      case 0: printf("Até logo");
      break;
      case 1: exercicio1();
      break;
      case 2: exercicio2();
      break;
      case 3: exercicio3();
      break;
      case 4: exercicio4();
      break;
      case 5: exercicio5();
      break;
      case 6: exercicio6();
      break;
      case 7: exercicio7();
      break;
      case 8: exercicio8();
      break;
      case 9: exercicio9();
      break;
      case 10: exercicio10();
      break;
      default: printf("Opção inválida");
      }
  }
  while(exercicio!=0);
  return 0;
}