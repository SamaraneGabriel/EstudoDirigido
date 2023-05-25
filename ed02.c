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
  int n = 0;
  printf("Digite um valor inteiro: ");
  scanf("%d",&n);
  if(n%2 == 0){
    printf("O numero %d é par!",n);
  }
  else{
    printf("O numero %d é ímpar!",n);
  }
  printf("Digite ENTER para continuar");
  getchar();

}
void exercicio2(){
  int n = 0;
  printf("Digite um valor inteiro: ");
  scanf("%d",&n);
  if(n%2 == 0 && n <25){
    printf("O numero é par e menor que 25 \n");
  }
  else if (n%2 != 0 && n>25){
    printf("O numero é ímpar e maior que 25 \n");
  }
  else{
    printf("O numero nao encaixa em nenhum dos padrões perguntados \n");
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio3(){
  int n = 0;
  printf("Digite um valor inteiro:\n");
  scanf("%d",&n);
  if(n>= 20 && n<=45){
    printf("Pertence ao intervalo\n");
  }
  else{
    printf("Não pertence ao intervalo\n");
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio4(){
  int n = 0;
  printf("Digite um valor inteiro:\n");
  scanf("%d",&n);
  if(n > 15 && n < 50){
    printf("Pertence ao intervalo fechado!\n");
  }
  else{
    printf("Não pertence ao intervalo fechado!\n");
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio5(){
  int n = 0;
  printf("Digite um valor inteiro:\n");
  scanf("%d",&n);
  if(n>10 && n<15){
    printf("Pertence ao primeiro intervalo fechado! [10:15]\n");
  }
  else if(n>15 && n<25){
    printf("Pertence aos intervalos fechados! [15:25] \n");
  }
  else if(n>25 && n<60){
    printf("Pertence ao segundo intervalo fechado! [25:60] \n");
  }
  else{
    printf("Não pertence aos intervalos fechado!\n");
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio6(){
  int n = 0;
  printf("Digite um valor inteiro:\n");
  scanf("%d",&n);
  int m = 0;
  printf("Digite outro valor inteiro:\n");
  scanf("%d",&m);
  if(n%2 !=0 && m%2 ==0){
    printf("O primeiro é ímpar e o segundo é par! Encaixam no requisito\n");
  }
  else{
    printf("Os numeros não encaixam no requisito\n");
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio7(){
  int n = 0;
  printf("Digite um valor inteiro:\n");
  scanf("%d",&n);
  int m = 0;
  printf("Digite outro valor inteiro:\n");
  scanf("%d",&m);
  if(n<0 && n%2 == 0 && m>0 && m%2 != 0){
    printf("O numeros encaixam nos requisitos\n");
  }
  else{
    printf("Os numeros não encaixam nos requisitos\n\n");
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio8(){
  double n = 0;
  printf("Digite um valor real:\n");
  scanf("%lf",&n);
  double m = 0;
  printf("Digite outro valor real:\n");
  scanf("%lf",&m);
  if (m>n){
    printf("O segundo numero é maior\n");
  }
  else if(m == n){
    printf("Os numeros são iguais\n");
  }
  else{
    printf("O segudo é menor que o primeiro\n\n");
  }
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio9(){
  double n,m,x;
  n = m = x = 0;
  printf("Digite um valor real:\n");
  scanf("%lf",&n);
  printf("Digite outro valor real:\n");
  scanf("%lf",&m);
  printf("Digite um terceiro valor real: \n");
  scanf("%lf",&x);
  if(x>m && n>m && n<x){
    printf("O valor %lf esta entre %lf e %lf \n",n,m,x);
  }
  else if(m>x && n>x && n<m){
    printf("O valor %lf esta entre %lf e %lf\n",n,x,m);
  }
  else{
    printf("O numero %lf nao esta entre %lf e %lf\n",n,m,x);
  }
  printf("Digite ENTER para continuar\n\n");
  getchar();
}
void exercicio10(){
  double n,m,x = 0;
  printf("Digite um valor real:\n");
  scanf("%lf",&n);
  printf("Digite outro valor real:\n");
  scanf("%lf",&m);
  printf("Digite um terceiro valor real: \n");
  scanf("%lf",&x);
  if(n>x && n>m){
    printf("O número %lf não está entre %lf e %lf",n,m,x);
  }
  else if(n<x && n<m){
    printf("O número %lf não está entre %lf e %lf",n,m,x);
  }
  else{
    printf("O número %lf está entre %lf e %lf",m,n,x);
  }
}
int main(void) {
  int exercicio;
  menu();
  do{
    scanf("%d",&exercicio);
    switch(exercicio){
      default: printf("ERRO: Opção inválida \n");
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
      }
    }
  while(exercicio != 0);
  
  return 0;
}
