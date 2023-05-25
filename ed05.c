#include <stdio.h>
#include <math.h>

//Funções:

void menu(){
  int nmenu = 10;
  while(nmenu > 0){
    printf("Para Exercicio %d, aperte %d \n \n",nmenu,nmenu);
    nmenu --;
      }
  printf("Para os exercícios extras, aperta 11 e 12 \n");
  printf("Digite 0 para sair \n");
}
void mult6(int n){
  int i = 0,mult = 6;
  for(i = 0; i < n; i++){
    printf("%d \n",mult);
    mult += 6;
  }
}
void mult12(int n){
  int i = 0,mult = 12;
  for(i = 0; i < n; i++){
    printf("%d \n",mult);
    mult += 12;
  }
}
void imp_9(int n){
  int i = 0, mult = 9;
  int array[n];
  while(i < n){
    if(mult % 2 != 0){
      array[i] = mult;
      mult +=9;
      i ++;
    }
    mult += 9;
  }
  for(i = n-1; i>=0; i--){
  printf(" %d = %d \n",i,array[i]);
  }
}
void inv_6(int n){
  int i = 0;
  double mult = 6.0;
  for(i=0; i<n; i++){
    printf("%lf = 1/%d \n",1.0/mult,(int)mult);
    mult += 6.0;
  }
}
void power(double x, int n){
  int i = 0;
  for(i=0; i<n; i++){
    printf("%lf = 1/x**%d \n",1.0/pow(x,i),i);
  }
}
int sum_par_5(int n){
  int soma = 0, i = 0, mult = 6;
  for(i=0;i<n;i++){
    if(mult % 5 != 0){
      soma = soma + mult;
    }
    mult += 6;
  }
  return soma;
}
double inv_6_not5(int n){
  int i = 0, mult = 0;
  double soma = 0.0;
  for(i=0; i<n; i++){
    if(mult %5 != 0){
      soma = soma + 1.0/(double)mult;
  }
    mult += 6.0;
  }
  return soma;
}
int sum_all(int n){
  int i = 0, soma = 6, aux = 0;
  for(i=0; i<n; i++){
    soma = soma + i;
    aux = aux + soma;
  }
  return aux;
}
int sum_all_sqr(int n){
  int i = 0, soma = 6, aux = 0;
  for(i=0; i<n; i++){
    soma = soma + i;
    aux = aux + pow(soma,2);
  }
  return aux;
}
double sum_all_inv(int n){
  int i = 0, soma = 6;
  double aux = 0.0;
  for(i=0; i<n; i++){
    soma = soma + i;
    aux = aux + 1.0/(double)soma;
  }
  return aux;
}
int fac(int n){
  if(n>0){
    return n*fac(n-1);
  }
  else{
    return 1;
  }
}
int teste(n){
  int y = 2;
  int soma = 0;
  if(y<n){
    soma = soma + teste(y+1);
    printf("%d",soma);
  }
  else{
    soma = 0;
  }
  return soma;
}
double f(n){
  double result = 0.0;
  int y = 2;
  if(n>0){
   result = result*(1+((y+1)/fac(y)));
  }
}
//Métodos

void exercicio1(){
  int n = 0;
  printf("Digite a quantidade de multiplos que deseja ver: \n");
  scanf("%d",&n);
  mult6(n);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio2(){
  int n = 0;
  printf("Digite a quantidade de multiplos que deseja ver: \n");
  scanf("%d",&n);
  mult12(n);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio3(){
  int n = 0;
  printf("Digite a quantidade de multiplos que deseja ver: \n");
  scanf("%d",&n);
  imp_9(n);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio4(){
  int n = 0;
  printf("Digite a quantidade de inversos que deseja ver: \n");
  scanf("%d",&n);
  inv_6(n);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio5(){
  int n = 0;
  double x = 0.0;
  printf("Digite a quantidade de inversos que deseja ver: ");
  scanf("%d",&n);
  printf("Digite o valor da base do denominador: \n ");
  scanf("%lf",&x);
  power(x,n);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio6(){
  int n = 0;
  printf("Digite a quantidade de números a serem somados: ");
  scanf("%d",&n);
  printf("A soma é: %d \n",sum_par_5(n));
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio7(){
  int n = 0;
  printf("Digite a quantidade de inversos a serem somados: ");
  scanf("%d",&n);
  printf("A soma é: %lf \n",inv_6_not5(n));
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio8(){
  int n = 0;
  printf("Digite a quantidade de numeros a serem somados: ");
  scanf("%d",&n);
  printf("A soma é: %d \n",sum_all(n));
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio9(){
  int n = 0;
  printf("Digite a quantidade de numeros a serem somados: ");
  scanf("%d",&n);
  printf("A soma é: %d \n",sum_all_sqr(n));
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio10(){
  int n = 0;
  printf("Digite a quantidade de numeros a serem somados: ");
  scanf("%d",&n);
  printf("A soma é: %lf \n",sum_all_inv(n));
  printf("Digite ENTER para continuar");
  getchar();
}

void extra1(){
  int n = 0;
  printf("Digite o numero para ter seu fatorial calculado: ");
  scanf("%d",&n);
  printf("O fatorial é: %d \n",fac(n));
  printf("Digite ENTER para continuar");
  getchar();
}
void extra2(){

}
//Classe Principal:

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
      case 11: extra1();
      break;
      case 12: extra2();
      break;
      default: printf("Opção inválida");
      }
  }
  while(exercicio!=0);
}