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
  printf("PARA OS EXTRAS DIGITE 11 E 12 \n");
  printf("Digite 0 para sair \n");
  }
void exercicio1(){
  int valor,area;
  printf("Digite um valor inteiro: ");
  scanf("%d",&valor);
  area = valor*valor;
  area = 7*area;
  printf("A area é: %d\n",area);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio2(){
  double valor, area, perimetro;
  printf("Digite um valor inteiro: ");
  scanf("%lf",&valor);
  valor = valor/2;
  area = valor*valor;
  perimetro = 4*valor;
  printf("area: %lf \n",area);
  printf("perimetro: %lf\n",perimetro);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio3(){
  int x,y,area;
  printf("Digite um valor inteiro: ");
  scanf("%d",&x);
  printf("Digite o segundo valor inteiro: ");
  scanf("%d",&y);
  area = x*y;
  printf("A area do retangulo é: %d\n",area);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio4(){
  double x,y,area,perimetro;
  printf("Digite um valor inteiro: ");
  scanf("%lf",&x);
  printf("Digite o segundo valor inteiro: ");
  scanf("%lf",&y);
  x = x/4;
  y = y/4;
  area = x*y;
  perimetro = 2*x + 2*y;
  printf("A area do retangulo é: %lf",area);
  printf("O perimetro é: %lf\n",perimetro);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio5(){
  int base,altura;
  double area;
  printf("Digite um valor inteiro: ");
  scanf("%d",&base);
  printf("Digite o segundo valor: ");
  scanf("%d",&altura);
  altura = 2*altura;
  area = 0.5*(altura*base);
  printf("A area é: %lf\n", area);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio6(){
  double lado,area,altura,perimetro;
  printf("Digite um valor real: ");
  scanf("%lf",&lado);
  lado = lado/6;
  perimetro = lado*3;
  altura = (sqrt(3)/2)*lado;
  area = pow(lado,2)*sqrt(3)/4;
  printf("A area é: %lf \n O perimetro é: %lf \n A altura é: %lf\n",area,perimetro,altura);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio7(){
  double lado,volume;
  printf("Digite um valor real: ");
  scanf("%lf",&lado);
  lado = 4*lado;
  volume = pow(lado,3);
  printf("O volume é: %lf\n",volume);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio8(){
  double altura,largura,comprimento,volume;
  printf("Digite um valor real: ");
  scanf("%lf",&altura);
  printf("Digite um valor real: ");
  scanf("%lf",&comprimento);
  printf("Digite um valor real: ");
  scanf("%lf",&largura);
  altura = altura/5;
  comprimento = comprimento/5;
  largura = largura/5;
  volume = largura*comprimento*altura;
  printf("O volume é: %lf\n",volume);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio9(){
  double raio,area;
  printf("Digite um valor real: ");
  scanf("%lf",&raio);
  raio = raio/2;
  area = M_PI*pow(raio,2);
  printf("A area é: %lf\n",area);
  printf("Digite ENTER para continuar");
  getchar();
}
void exercicio10(){
  double raio,volume;
  printf("Digite um valor real: ");
  scanf("%lf",&raio);
  raio = raio*3/5;
  volume = 4/3*M_PI*pow(raio,3);
  printf("O volume é: %lf\n",volume);
  printf("Digite ENTER para continuar");
  getchar();
}
void extra1(){
  double area,raio;
  printf("Digite o valor da área: ");
  scanf("%lf",&area);
  area = area/4.0;
  raio = sqrt(area/M_PI);
  printf("O raio é: %lf\n",raio);
  printf("Digite ENTER para continuar");
  getchar();
}
void extra2(){
  double area,raio,volume;
  printf("Digite o valor do volume: ");
  scanf("%lf",&volume);
  volume = volume*3.0/8.0;
  raio = pow((3.0/4.0)*(volume/M_PI),1.0/3.0);
  area = 4*M_PI*pow(raio,2);
  printf(" O raio é: %lf \n A area de superficie é: %lf\n",raio,area);
  printf("Digite ENTER para continuar");
  getchar();
}
int main(void){
  int exercicio;
  menu();
  do{
    scanf("%d",&exercicio);
    switch(exercicio){
      default: printf("ERRO: Opção inválida \n");
      case 0: printf("ENCERRADO.");
      break;
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
      }
    }
  while(exercicio != 0);
  return 0;
}