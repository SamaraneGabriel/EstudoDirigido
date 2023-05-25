#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Funcoes Gerais
void menu() {
  int nmenu = 10;
  while (nmenu > 0) {
    printf("Para Exercicio %d, aperte %d \n \n", nmenu, nmenu);
    nmenu--;
  }
  printf("Para os exercícios extras, aperta 11 e 12 \n");
  printf("Digite 0 para sair \n");
}
void createRealMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      printf("Digite um elemento: \n");
      scanf("%lf",&matrix[x][y]);
    }
  }
}
void printRealMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      printf("%0.1lf ",matrix[x][y]);
    }
    printf("\n");
  }
}
void fileRealMatrix(char nomeArquivo[], int j, int i, double matrix[][j]){
  int x = 0, y = 0;
  FILE *arquivo = fopen(nomeArquivo,"w");
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      fprintf(arquivo,"%lf\n",matrix[x][y]);
    }
  }
  fclose(arquivo);
}
void getFileRealMatrix(char nomeArquivo[], int j, int i, double matrix[][j]){
  int x = 0, y = 0;
  double c = 0.0;
  FILE *arquivo = fopen(nomeArquivo,"rt");
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      fscanf(arquivo,"%lf",&c);
      printf("%0.1lf ",c);
    }
    printf("\n");
  }
  fclose(arquivo);
}

void createNegMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      printf("Digite um elemento NEGATIVO: \n");
      scanf("%lf",&matrix[x][y]);
      if(matrix[x][y] > 0){
        matrix[x][y] = -matrix[x][y];
      }
    }
  }
}
void printDiagonalMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      if(x == y){
       printf("%0.0lf ",matrix[x][y]); 
      }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}
void printSecondaryDiagonalMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      if(x+y == (i-1)){
       printf("%0.0lf ",matrix[x][y]); 
      }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}
void printUnderDiagonalMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      if(x>y){
       printf("%0.0lf ",matrix[x][y]); 
      }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}
void printAboveDiagonalMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      if(x<y){
       printf("%0.0lf ",matrix[x][y]); 
      }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}
void printUSDiagonalMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      if((x+y == (i-1)) || ((x+y)>=i-1)){
       printf("%0.0lf ",matrix[x][y]); 
      }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}
void printASDiagonalMatrix(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      if((x+y == (i-1)) || ((x+y)<=i-1)){
       printf("%0.0lf ",matrix[x][y]); 
      }
      else{
        printf("0 ");
      }
    }
    printf("\n");
  }
}
bool notNullTriInferior(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  bool p = false;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      if((matrix[x][y] != 0) && (x>y)){
        p = true;
      }
    }
  }
  return p;
}
bool NullTriSuperior(int i, int j, double matrix[][j]){
  int x = 0, y = 0;
  bool p = true;
  for(x = 0; x < i; x++){
    for(y = 0; y < j; y++){
      if((matrix[x][y] != 0) && (x<y)){
        p = false;
      }
    }
  }
  return p;
}

//Metodos
void exercicio1(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVOS\n");
  printf("Digite o número de linhas: ");
  scanf("%d",&i);
  printf("Digite o número de colunas: ");
  scanf("%d",&j);
  }
  while(i < 0 || j < 0);
  double negativeMatrix[i][j];
  createNegMatrix(i,j,negativeMatrix);
  printRealMatrix(i,j,negativeMatrix);
}
void exercicio2(){
  char nomeArquivo[80];
  printf("Digite o nome do arquivo: ");
  scanf("%s",nomeArquivo);
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVOS\n");
  printf("Digite o número de linhas: ");
  scanf("%d",&i);
  printf("Digite o número de colunas: ");
  scanf("%d",&j);
  }
  while(i < 0 || j < 0);
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  fileRealMatrix(nomeArquivo,j,i,matrix);
  getFileRealMatrix(nomeArquivo,j,i,matrix);
}

void exercicio3(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVO\n");
  printf("Digite o número de linhas e colunas (matriz quadrada): ");
  scanf("%d",&i);
  j = i;
  }
  while(i < 0 || j < 0);
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  printf("DIAGONAL: \n");
  printDiagonalMatrix(i,j,matrix);
}

void exercicio4(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVO\n");
  printf("Digite o número de linhas e colunas (matriz quadrada): ");
  scanf("%d",&i);
  }
  while(i < 0);
  j = i;
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  printf("DIAGONAL SECNDÁRIA: \n");
  printSecondaryDiagonalMatrix(i,j,matrix);
}

void exercicio5(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVO\n");
  printf("Digite o número de linhas e colunas (matriz quadrada): ");
  scanf("%d",&i);
  }
  while(i < 0);
  j = i;
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  printf("TRIÃNGULO INFERIOR: \n");
  printUnderDiagonalMatrix(i,j,matrix);
}

void exercicio6(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVO\n");
  printf("Digite o número de linhas e colunas (matriz quadrada): ");
  scanf("%d",&i);
  }
  while(i < 0);
  j = i;
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  printf("TRIÃNGULO SUPERIOR: \n");
  printAboveDiagonalMatrix(i,j,matrix);
}

void exercicio7(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVO\n");
  printf("Digite o número de linhas e colunas (matriz quadrada): ");
  scanf("%d",&i);
  }
  while(i < 0);
  j = i;
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  printf("DIAGONAL SEC. E TRI. INFERIOR: \n");
  printUSDiagonalMatrix(i,j,matrix);
}

void exercicio8(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVO\n");
  printf("Digite o número de linhas e colunas (matriz quadrada): ");
  scanf("%d",&i);
  }
  while(i < 0);
  j = i;
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  printf("DIAGONAL SEC. E TRI. SUPERIOR: \n");
  printASDiagonalMatrix(i,j,matrix);
}

void exercicio9(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVO\n");
  printf("Digite o número de linhas e colunas (matriz quadrada): ");
  scanf("%d",&i);
  }
  while(i < 0);
  j = i;
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  if(notNullTriInferior(i,j,matrix)){
    printf("NEM TODOS OS ELEMENTOS ABAIXO DA DIG PRINCIPAL SÃO NULOS");
  }
  else{
    printf("São todos nulos");
  }
}

void exercicio10(){
  int i = 0, j = 0;
  do{
  printf("DIGITE SOMENTE VALORES POSITIVO\n");
  printf("Digite o número de linhas e colunas (matriz quadrada): ");
  scanf("%d",&i);
  }
  while(i < 0);
  j = i;
  double matrix[i][j];
  createRealMatrix(i,j,matrix);
  if(NullTriSuperior(i,j,matrix)){
    printf("Todos os elementos acima da diagonal principal são nulos");
  }
  else{
    printf("Nem todos elementos são nulos");
  }
}


// main
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
    case 10:
      exercicio10();
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