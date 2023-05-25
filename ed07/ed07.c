#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Funções

bool isMinuscula(char c){
  if(c >= 'a' && c <='z'){
    return true;
  }
  else{
    return false;
  }
}
bool isDigitBigger3(char c){
  if(c>='3' && c <='9'){
    return true;
  }
  else{
    return false;
  }
}
void menu() {
  int nmenu = 10;
  while (nmenu > 0) {
    printf("Para Exercicio %d, aperte %d \n \n", nmenu, nmenu);
    nmenu--;
  }
  printf("Para os exercícios extras, aperta 11 e 12 \n");
  printf("Digite 0 para sair \n");
}
void write6s(char nomeArquivo[], int n) {
  FILE *arquivo = fopen(nomeArquivo, "wt");
  int i = 0, p = 6;
  for (i = 0; i < n; i++) {
    fprintf(arquivo, "%d \n", p);
    p += 6;
  }
  fclose(arquivo);
}
void mult_5(char nomeArquivo[], int n) {
  FILE *arquivo = fopen(nomeArquivo, "wt");
  int array[100];
  int i = 15;
  for (int k = 0; k < n; k++) {
    array[k] = i;
    i = i + 10;
  }
  for (int k = n - 1; k >= 0; k--) {
    fprintf(arquivo, "%d \n", array[k]);
  }
  fclose(arquivo);
}
void pow6(char nomeArquivo[], int n) {
  FILE *arquivo = fopen(nomeArquivo, "wt");
  for (int i = 0; i < n; i++) {
    fprintf(arquivo, "%d \n", (int)pow(6, i));
  }
  fclose(arquivo);
}
void inv_pow6(char nomeArquivo[], int n) {
  FILE *arquivo = fopen(nomeArquivo, "wt");
  double array[100];
  double i = 1.0;
  for (int k = 0; k < n; k++) {
    array[k] = 1.0 / i;
    i = i * 6.0;
  }
  for (int k = n - 1; k >= 0; k--) {
    fprintf(arquivo, "%lf\n", array[k],(int)pow(6, k));
  }
  fclose(arquivo);
}
void inv_powx(char nomeArquivo[], int n, double x) {
  FILE *arquivo = fopen(nomeArquivo, "wt");
  int aux = 2;
  for (int i = 0; i < n; i++) {
    fprintf(arquivo, "%lf\n", 1.0 / (pow(x, aux)));
    aux = aux + 2;
  }
  fclose(arquivo);
}
void inv_powx_sum(int n, char nomeArquivo[]) {
  double soma = 0.0, c = 0.0;
  FILE *arquivo = fopen(nomeArquivo, "rt");
  FILE *arquivo_resul = fopen("RESULTADOS06.TXT", "wt");
  for (int i = 0; i < n; i++) {
    fscanf(arquivo, "%lf", &c);
    printf("%lf\n", c);
    soma = soma + c;
  }
  fprintf(arquivo_resul, "%lf", soma);
  fclose(arquivo);
  fclose(arquivo_resul);
}
void f7(int n, char nomeArquivo[]) {
  double soma = 0.0, c = 0.0;
  FILE *arquivo = fopen(nomeArquivo, "rt");
  FILE *arquivo_resul = fopen("RESULTADOS07.TXT", "wt");
  for (int i = 0; i < n; i++) {
    fscanf(arquivo, "%lf", &c);
    printf("%lf\n", c);
    soma = soma + c;
  }
  fprintf(arquivo_resul, "%lf", soma);
  fclose(arquivo);
  fclose(arquivo_resul);
}
void fib(int n) {
  FILE *arquivo_resul = fopen("RESULTADOS08.TXT", "wt");
  int i = 0, fib = 0;
  int num0 = 0, num1 = 1;
  while (i < n) {
    fib = num0 + num1;
    num0 = num1;
    num1 = fib;
    if (fib % 2 == 0) {
      fprintf(arquivo_resul, "%d\n", fib);
      i++;
    }
  }
  fclose(arquivo_resul);
}
void cadeiaString() {
  char string[100];
  char aux[100] = "";
  FILE *arquivo_Resul = fopen("RESULTADO09.TXT", "wt");
  FILE *arquivor = fopen("string.txt","rt");
  fgets(string,100,arquivor);
  for(int i = 0, k = 0; i< strlen(string)+1; i++){
    int contador = 0;
    if(string[i] != ' ' && string[i] != '\0'){
      aux[k] = string[i];
      k++;
    }
    else{
      for(int j = 0; j < strlen(aux); j++){
        if(isMinuscula(aux[j])){
          contador ++;
       }
      }
      fprintf(arquivo_Resul,"%s: %d letras min. \n",aux,contador);
      k = 0;
    }
  }
  fclose(arquivor);
  fclose(arquivo_Resul);
}
void cadeiaStringNum() {
  char string[100];
  char aux[100] = "";
  FILE *arquivo_Resul = fopen("RESULTADO010.TXT", "wt");
  FILE *arquivor = fopen("string.txt","rt");
  fgets(string,100,arquivor);
  for(int i = 0, k = 0; i< strlen(string)+1; i++){
    int contador = 0;
    if(string[i] != ' ' && string[i] != '\0'){
      aux[k] = string[i];
      k++;
    }
    else{
      for(int j = 0; j < strlen(aux); j++){
        if(isDigitBigger3(aux[j])){
          contador ++;
       }
      }
      fprintf(arquivo_Resul,"%s: %d digitos maiores que 3\n",aux,contador);
      k = 0;
    }
  }
  fclose(arquivo_Resul);
  fclose(arquivor);
}

// Métodos:
void exercicio1() {
  int n = 0;
  char nomeArquivo[80];
  printf("Digite a quantidade de multiplos: ");
  scanf("%d", &n);
  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  write6s(nomeArquivo, n);
}
void exercicio2() {
  int n = 0;
  char nomeArquivo[80];
  printf("Digite a quantidade de multiplos: ");
  scanf("%d", &n);
  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  mult_5(nomeArquivo, n);
}
void exercicio3() {
  int n = 0;
  char nomeArquivo[80];
  printf("Digite a quantidade de multiplos: ");
  scanf("%d", &n);
  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  pow6(nomeArquivo, n);
}
void exercicio4() {
  int n = 0;
  char nomeArquivo[80];
  printf("Digite a quantidade de multiplos: ");
  scanf("%d", &n);
  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  inv_pow6(nomeArquivo, n);
}
void exercicio5() {
  int n = 0;
  double x = 0;
  char nomeArquivo[80];
  printf("Digite a quantidade de multiplos: ");
  scanf("%d", &n);
  printf("Digite o valor de x: ");
  scanf("%lf", &x);
  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  inv_powx(nomeArquivo, n, x);
}
void exercicio6() {
  int n = 0;
  char nomeArquivo[80];
  printf("Digite o numero de elementos a serem somados: ");
  scanf("%d", &n);
  printf("Digite o nome do arquivo a ser lido: ");
  scanf("%s", nomeArquivo);
  inv_powx_sum(n, nomeArquivo);
}
void exercicio7() {
  int n = 0;
  char nomeArquivo[80];
  printf("Digite o numero de elementos a serem somados: ");
  scanf("%d", &n);
  printf("Digite o nome do arquivo a ser lido: ");
  scanf("%s", nomeArquivo);
  f7(n, nomeArquivo);
}
void exercicio8() {
  int n = 0;
  printf("Digite o numero de elementos a serem somados: ");
  scanf("%d", &n);
  fib(n);
}
void exercicio9() {
printf("Chece arquivo RESULTADO09.TXT para resposta");
  cadeiaString();
}
void exercicio10(){
  printf("Chece arquivo RESULTADO10.TXT para resposta");
  cadeiaStringNum();
}
int main(void) {
  int exercicio;
  menu();
  do {
    scanf("%d", &exercicio);
    switch (exercicio) {
    case 0:
      printf("Até logo");
      break;
    case 1:
      exercicio1();
      break;
    case 2:
      exercicio2();
      break;
    case 3:
      exercicio3();
      break;
    case 4:
      exercicio4();
      break;
    case 5:
      exercicio5();
      break;
    case 6:
      exercicio6();
      break;
    case 7:
      exercicio7();
      break;
    case 8:
      exercicio8();
      break;
    case 9:
      exercicio9();
      break;
    case 10:  exercicio10();
      break;
    case 11: // extra1();
      break;
    case 12: // extra2();
      break;
    default:
      printf("Opção inválida");
    }
  } while (exercicio != 0);
}