#include <stdio.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


void menu(){
  int nmenu = 10;
  while(nmenu > 0){
    printf("Para Exercicio %d, aperte %d \n \n",nmenu,nmenu);
    nmenu --;
      }
  printf("Digite 0 para sair \n");
  }
void exercicio1(){
  char palavra[1000];
  int i,tamanho;
  i = tamanho = 0;
  printf("Digite um palavra com maisculas e minusculas: \n");
  scanf("%s",palavra);
  tamanho = strlen(palavra);
  printf("%d",tamanho);
  printf("As letras maisculas são: \n");
  for(i = 0;i<=tamanho;i++){
    if(palavra[i]>= 'A' && palavra[i]<= 'Z'){
      printf("%c\n",palavra[i]);
    }
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio2(){
  char palavra[1000];
  int i,tamanho,contador;
  i = tamanho = contador = 0;
  printf("Digite um palavra com maisculas e minusculas: \n");
  scanf("%s",palavra);
  tamanho = strlen(palavra);
  printf("As letras maisculas são: \n");
  for(i = 0;i<=tamanho;i++){
    if(palavra[i]>= 'A' && palavra[i]<= 'Z'){
      printf("%c \n",palavra[i]);
      contador ++;
    }
  }
  printf("São %d letras maiusculas\n",contador);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio3(){
  char palavra[1000];
  int i,tamanho,contador;
  i = tamanho = contador = 0;
  printf("Digite um palavra com maisculas e minusculas: \n");
  scanf("%s",palavra);
  tamanho = strlen(palavra);
  printf("As letras maisculas são: \n");
  for(i = tamanho-1;i>=0;i--){
    if(palavra[i]>= 'A' && palavra[i]<= 'Z'){
      printf("%c \n",palavra[i]);
      contador ++;
    }
  }
  printf("São %d letras maiusculas\n",contador);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio4(){
  char palavra[1000];
  int i,tamanho,contador;
  i = tamanho = contador = 0;
  printf("Digite um palavra com maisculas e minusculas: \n");
  scanf("%s",palavra);
  tamanho = strlen(palavra);
  printf("As letras maisculas são: \n");
  for(i = 0;i<=tamanho;i++){
    if(palavra[i]>= 'A' && palavra[i]<= 'Z'){
      printf("%c \n",palavra[i]);
      contador ++;
    }
    else if(palavra[i]>= 'a' && palavra[i]<= 'z'){
      printf("%c \n",palavra[i]);
      contador++;
    }
  }
  printf("São %d letras \n",contador);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio5(){
  char palavra[1000];
  int i,tamanho,contador;
  i = contador = tamanho = 0;
  printf("Digite um palavra com digitos: \n");
  scanf("%s",palavra);
  tamanho = strlen(palavra);
  printf("Os digitos são: \n");
  for(i=tamanho-1;i>=0;i--){
    if(palavra[i]>= 49 && palavra[i]<=57){
      printf("%c\n",palavra[i]);
      contador ++;
    }
  }
  printf("São %d digitos\n",contador);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio6(){
  char palavra[1000];
  int i,tamanho,contador;
  i = tamanho = contador = 0;
  printf("Digite um palavra com simbolos: \n");
  scanf("%s",palavra);
  tamanho = strlen(palavra);
  printf("Os simbolos são: \n");
  for(i=0;i<=tamanho;i++){
    if(palavra[i]>= 33 && palavra[i]<=47){
      printf("%c\n",palavra[i]);
      contador ++;
    }
    else if(palavra[i]>=58 && palavra[i]<=64){
      printf("%c\n",palavra[i]);
      contador ++;
    }
  printf("São %d simbolos\n",contador);
  printf("Digite ENTER para continuar");
  getchar();
  }
}
void exercicio7(){
  int a,b,n;
  int i = 0, contador = 0, x = 0;
  printf("Digite o limite inferior: \n");
  scanf("%d",&a);
  printf("Digite o limite superior: \n");
  scanf("%d",&b);
  printf("Digite a quantidade de números a serem testados: ");
  scanf("%d",&n);
  int array [n];
  for(i=0;i<n;i++){
    printf("Digite um valor: ");
    scanf("%d",&x);
    if(x >= a && x <=b && x%3 ==0){
      printf("x = %d \n",x);
      array[contador] = x;
      contador ++;
      }
  }
  printf("Os %d números que encaixam nesse padrão são: \n",contador);
  for(i = 0;i<contador;i++){
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio8(){
  int a,b,n;
  int i = 0, contador = 0, x = 0;
  printf("Digite o limite inferior: \n");
  scanf("%d",&a);
  printf("Digite o limite superior: \n");
  scanf("%d",&b);
  printf("Digite a quantidade de números a serem testados: ");
  scanf("%d",&n);
  int array [n];
  for(i=0;i<n;i++){
    printf("Digite um valor: ");
    scanf("%d",&x);
    if(x >= a && x <=b && x%2 ==0 && x%5 != 0){
      array[contador] = x;
      contador ++;
      }
  }
  printf("Os %d números que encaixam nesse padrão são: \n",contador);
  for(i = 0;i<contador;i++){
    printf("%d ",array[i]);
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio9(){
  double a = 0, b = 0;
  int i = 0, contador = 0, n = 0;
  double x = 0;
  printf("Digite o limite inferior: \n");
  scanf("%lf",&a);
  printf("Digite o limite superior: \n");
  scanf("%lf",&b);
  printf("Digite a quantidade de números a serem testados: ");
  scanf("%d",&n);
  int array [n];
  for(i=0;i<n;i++){
    printf("Digite um valor: ");
    scanf("%lf",&x);
    if((int)x % 2 == 0 && x<=b && x>=a){
      printf("%lf",x);
      array[contador] = x;
      contador ++;
      }
  }
  printf("Os %d números que encaixam nesse padrão são: \n",contador);
  for(i = 0;i<contador;i++){
    printf("%d ",array[i]);
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio10(){
  double a,x,b;
  int i = 0, contador = 0, n  = 0;
  x = a = b = 0;
  do{
  printf("Digite o limite inferior (entre 0 e 1): \n");
  scanf("%lf",&a);
  printf("Digite o limite superior (entre 0 e 1): \n");
  scanf("%lf",&b);
  }
  while((a+b)/2 > 1);
  printf("Digite a quantidade de números a serem testados: ");
  scanf("%d",&n);
  int array [n];
  for(i=0;i<n;i++){
    printf("Digite um valor: ");
    scanf("%lf",&x);
    if((int)x>b || (int)x<a){
      array[contador] = x;
      contador ++;
      }
  }
  printf("Os %d números que encaixam nesse padrão são: \n",contador);
  for(i = 0;i<contador;i++){
    printf("%d ",array[i]);
  }
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
