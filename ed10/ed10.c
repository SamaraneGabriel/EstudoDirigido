//@author: Gabriel Samarane Ribeiro
//Definição de arrays e matrixes a partir de structs em C.


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
  int nmenu = 10;
  while (nmenu > 0) {
    printf("Para Exercicio %d, aperte %d \n \n", nmenu, nmenu);
    nmenu--;
  }
  printf("Para os exercícios extras, aperta 11 e 12 \n");
  printf("Digite 0 para sair \n");
}
// estruturas
struct intArray {
  int length;
  int *data;
};
typedef struct intArray intArray;

struct intMatrix {
  int row;
  int col;
  int **data;
};

typedef struct intMatrix intMatrix;

// funcoes gerais
int *allocMemoryArray(int n) {
  int *reference;
  reference = malloc(sizeof(int) * n);
  return reference;
}

void randomInt(int inferior, int superior, intArray array) {
  srand(time(NULL));
  for (int i = 0; i < array.length; i++) {
    int num1 = rand();
    int num2 = num1 % superior + inferior;
    *(array.data) = num2;
    array.data++;
  }
}
void printArray(intArray array) {
  for (int i = 0; i < array.length; i++) {
    printf("%d\n", *(array.data));
    array.data++;
  }
}
void printfFileArray(char *nomeArquivo, intArray array) {
  FILE *arquivo = fopen(nomeArquivo, "wt");
  fprintf(arquivo, "%d\n", array.length);
  for (int i = 0; i < array.length; i++) {
    fprintf(arquivo, "%d\n", *(array.data));
    array.data++;
  }
  fclose(arquivo);
}
void fileFillArray(char *nomeArquivo, intArray array) {
  FILE *arquivo = fopen(nomeArquivo, "rt");
  for (int i = 0; i < array.length; i++) {
    fscanf(arquivo, "%d\n", array.data);
    array.data++;
  }
  fclose(arquivo);
}
bool procuraValorArray(int valor, intArray array) {
  bool p = false;
  for (int i = 0; i < array.length; i++) {
    if (array.data[i] == valor) {
      p = true;
    }
  }
  return p;
}
bool arrayCmpr(intArray array1, intArray array2) {
  bool p = false;
  int contador = 0;
  if (array1.length != array2.length) {
    printf("ERRO: TAMANHOS DISTINTOS \n");
  } else {
    for (int i = 0; i < array1.length; i++) {
      if (array1.data[i] == array2.data[i]) {
        contador += 1;
      }
    }
  }
  if (contador == array1.length) {
    p = true;
  }
  return p;
}
intArray arraySum(intArray array1, intArray array2, int k, intArray reference) {
  if (array1.length == array2.length) {
    for (int i = 0; i < array1.length; i++) {
      reference.data[i] = array1.data[i] + (k * array2.data[i]);
    }
  } else {
    printf("Tamanho incompativel\n");
  }
  return reference;
}
bool decrescente(intArray array) {
  bool p = true;
  for (int i = 0; i < array.length - 1; i++) {
    if (array.data[i] < array.data[i + 1]) {
      p = false;
      break;
    }
  }
  return p;
}
intMatrix *createMatrix(int row, int col) {
  intMatrix *matrix = (intMatrix *)malloc(sizeof(intMatrix));
  matrix->col = col;
  matrix->row = row;
  if (row > 0 && col > 0) {
    matrix->data = malloc(row * sizeof(int *));
    if (matrix->data) {
      for (int i = 0; i < matrix->row; i++) {
        matrix->data[i] = malloc(matrix->col * sizeof(int));
      }
      for (int x = 0; x < matrix->row; x++) {
        for (int y = 0; y < matrix->col; y++) {
          matrix->data[x][y] = 0;
        }
      }
    }
  }
  return matrix;
}
void fileFillMatrix(intMatrix *matrix, char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "rt");
  for (int i = 0; i < matrix->row; i++) {
    for (int j = 0; j < matrix->col; j++) {
      fscanf(arquivo, "%d", &matrix->data[i][j]);
    }
  }
  fclose(arquivo);
}
void printMatrix(intMatrix *matrix) {
  for (int i = 0; i < matrix->row; i++) {
    printf("\n");
    for (int j = 0; j < matrix->col; j++) {
      printf("%d ", matrix->data[i][j]);
    }
  }
}
intMatrix *transpMatrix(intMatrix *matrix) {
  intMatrix *aux;
  aux = createMatrix(matrix->col, matrix->row);
  for (int i = 0; i < matrix->row; i++) {
    for (int j = 0; j < matrix->col; j++) {
      aux->data[j][i] = matrix->data[i][j];
    }
  }
  return aux;
}
bool matrixNull(intMatrix *matrix) {
  bool p = true;
  for (int i = 0; i < matrix->row; i++) {
    for (int j = 0; j < matrix->col; j++) {
      if (matrix->data[i][j] != 0) {
        p = false;
        break;
      }
    }
  }
  return p;
}
bool equalMatrix(intMatrix *matrix, intMatrix *matrix1) {
  bool p = false;
  if ((matrix->col == matrix1->col) && (matrix->row == matrix1->row)) {
    for (int i = 0; i < matrix->row; i++) {
      for (int j = 0; j < matrix->col; j++) {
        if (matrix->data[i][j] == matrix1->data[i][j]) {
          p = true;
        }
      }
    }
  } 
  return p;
}
intMatrix* sumMatrix(intMatrix* matrix,intMatrix* matrix1, int escalar){
  intMatrix* sum;
  if((matrix->col == matrix1->col)&&(matrix->row==matrix1->row)){
    sum = createMatrix(matrix->row,matrix->col);
    for(int i = 0; i< sum->row;i++){
      for(int j = 0; j < sum->col;j++){
        sum->data[i][j] = (matrix->data[i][j]) + ((escalar)*(matrix1->data[i][j]));
      }
    }
  }
  return sum;
}

// metodos
void exercicio1() {
  int quantidade = 0, inferior = 0, superior = 0;
  intArray lana;
  char nomeArquivo[80];
  printf("Digite o nome do arquivo a gravar: ");
  scanf("%s", nomeArquivo);
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &quantidade);
  printf("Digite o valor inferior: ");
  scanf("%d", &inferior);
  printf("Digite o valor superior: ");
  scanf("%d", &superior);
  lana.data = allocMemoryArray(quantidade);
  lana.length = quantidade;
  randomInt(inferior, superior, lana);
  printfFileArray(nomeArquivo, lana);
}
void exercicio2() {
  intArray array;
  int valor = 0;
  char nomeArquivo[80];
  printf("Digite o nome do arquivo a ler: ");
  scanf("%s", nomeArquivo);
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &array.length);
  printf("Digite o valor procurado: ");
  scanf("%d", &valor);
  array.data = allocMemoryArray(array.length);
  fileFillArray(nomeArquivo, array);
  if (procuraValorArray(valor, array)) {
    printf("O valor foi encotrado no arranjo");
  } else {
    printf("O valor nao foi encontrado no arranjo");
  }
}
void exercicio3() {
  intArray array1;
  intArray array2;
  char nomeArquivo[80];
  char nomeArquivo1[80];
  printf("Digite o nome do arquivo a ler para o primeiro arranjo: ");
  scanf("%s", nomeArquivo);
  printf("Digite o nome do arquivo a ler para o segundo arranjo: ");
  scanf("%s", nomeArquivo1);
  printf("Digite o tamanho do primeiro arranjo: ");
  scanf("%d", &array1.length);
  printf("Digite o tamanho do segundo arranjo: ");
  scanf("%d", &array2.length);
  array1.data = allocMemoryArray(array1.length);
  array2.data = allocMemoryArray(array2.length);
  fileFillArray(nomeArquivo, array1);
  fileFillArray(nomeArquivo1, array2);
  if (arrayCmpr(array1, array2)) {
    printf("Os os arranjos são identicos!");
  } else {
    printf("Os arranjos são diferentes");
  }
}
void exercicio4() {
  intArray array1, array2, reference;
  int k;
  char nomeArquivo[80];
  char nomeArquivo1[80];
  printf("Digite o nome do arquivo a ler para o primeiro arranjo: ");
  scanf("%s", nomeArquivo);
  printf("Digite o nome do arquivo a ler para o segundo arranjo: ");
  scanf("%s", nomeArquivo1);
  printf("Digite o tamanho do primeiro arranjo: ");
  scanf("%d", &array1.length);
  printf("Digite o tamanho do segundo arranjo: ");
  scanf("%d", &array2.length);
  printf("Digite o escalar a ser multiplicado: ");
  scanf("%d", &k);
  array1.data = allocMemoryArray(array1.length);
  array2.data = allocMemoryArray(array2.length);
  reference.data = allocMemoryArray(array1.length);
  reference.length = array1.length;
  fileFillArray(nomeArquivo, array1);
  fileFillArray(nomeArquivo1, array2);
  printf("VETOR RESULTANTE DA SOMA: \n");
  printArray(arraySum(array1, array2, k, reference));
}
void exercicio5() {
  intArray array;
  char nomeArquivo[80];
  printf("Digite o nome do arquivo a ler para o primeiro arranjo: ");
  scanf("%s", nomeArquivo);
  printf("Digite o tamanho do arranjo: ");
  scanf("%d", &array.length);
  array.data = allocMemoryArray(array.length);
  fileFillArray(nomeArquivo, array);
  if (decrescente(array)) {
    printf("O vetor está em ordem decrescente");
  } else {
    printf("O vetor não esta em ordem decrescente");
  }
}
void exercicio6() {
  intMatrix *matrix;
  intMatrix *transposta;
  char nomeArquivo[80];
  int row = 0;
  int col = 0;
  printf("Digite o nome do arquivo a ler para a matriz: ");
  scanf("%s", nomeArquivo);
  printf("Digite o numero de linhas: ");
  scanf("%d", &row);
  printf("Digite o numero de colunas: ");
  scanf("%d", &col);
  matrix = createMatrix(row, col);
  fileFillMatrix(matrix, nomeArquivo);
  printMatrix(matrix);
  printf("\n");
  transposta = transpMatrix(matrix);
  printMatrix(transposta);
}
void exercicio7() {
  intMatrix *matrix;
  char nomeArquivo[80];
  int row = 0;
  int col = 0;
  printf("Digite o nome do arquivo a ler para a primeira matriz : ");
  scanf("%s", nomeArquivo);
  printf("Digite o numero de linhas: ");
  scanf("%d", &row);
  printf("Digite o numero de colunas: ");
  scanf("%d", &col);
  matrix = createMatrix(row, col);
  fileFillMatrix(matrix, nomeArquivo);
  printMatrix(matrix);
  if (matrixNull(matrix)) {
    printf("A matriz é nula");
  } else {
    printf("A matriz não é nula");
  }
}
void exercicio8() {
  intMatrix *matrix;
  intMatrix *matrix1;
  char nomeArquivo[80];
  char nomeArquivo1[80];
  int row = 0, row1 = 0;
  int col = 0, col1 = 0;
  printf("Digite o nome do arquivo a ler para a primeira matriz : ");
  scanf("%s", nomeArquivo);
  printf("Digite o nome do arquivo a ler para a segunda matriz : ");
  scanf("%s", nomeArquivo1);
  printf("Digite o numero de linhas: ");
  scanf("%d", &row);
  printf("Digite o numero de colunas: ");
  scanf("%d", &col);
  printf("Digite o numero de linhas da segunda matriz: ");
  scanf("%d", &row1);
  printf("Digite o numero de colunas da segunda matriz: ");
  scanf("%d", &col1);
  matrix = createMatrix(row, col);
  matrix1 = createMatrix(row1,col1);
  fileFillMatrix(matrix, nomeArquivo);
  fileFillMatrix(matrix1, nomeArquivo1);
  if (equalMatrix(matrix,matrix1)) {
    printf("As matrizes são identicas");
  } else {
    printf("As matrizes são diferentes");
  }
}

void exercicio9() {
  intMatrix *matrix;
  intMatrix *matrix1;
  intMatrix *sum;
  char nomeArquivo[80];
  char nomeArquivo1[80];
  int row = 0, row1 = 0;
  int col = 0, col1 = 0;
  int escalar = 0;
  printf("Digite o nome do arquivo a ler para a primeira matriz : ");
  scanf("%s", nomeArquivo);
  printf("Digite o nome do arquivo a ler para a segunda matriz : ");
  scanf("%s", nomeArquivo1);
  printf("Digite o numero de linhas: ");
  scanf("%d", &row);
  printf("Digite o numero de colunas: ");
  scanf("%d", &col);
  printf("Digite o numero de linhas da segunda matriz: ");
  scanf("%d", &row1);
  printf("Digite o numero de colunas da segunda matriz: ");
  scanf("%d", &col1);
  printf("Digite o escalar a ser multiplicado: ");
  scanf("%d", &escalar);
  matrix = createMatrix(row, col);
  matrix1 = createMatrix(row1,col1);
  fileFillMatrix(matrix, nomeArquivo);
  fileFillMatrix(matrix1, nomeArquivo1);
  sum = sumMatrix(matrix,matrix1,escalar);
  printf("A soma das matrizes é: \n");
  printMatrix(sum);
}
void exercicio10() {
  intMatrix *matrix;
  intMatrix *matrix1;
  intMatrix *mult;
  char nomeArquivo[80];
  char nomeArquivo1[80];
  int row = 0, row1 = 0;
  int col = 0, col1 = 0;
  int escalar = 0;
  printf("Digite o nome do arquivo a ler para a primeira matriz : ");
  scanf("%s", nomeArquivo);
  printf("Digite o nome do arquivo a ler para a segunda matriz : ");
  scanf("%s", nomeArquivo1);
  printf("Digite o numero de linhas: ");
  scanf("%d", &row);
  printf("Digite o numero de colunas: ");
  scanf("%d", &col);
  printf("Digite o numero de linhas da segunda matriz: ");
  scanf("%d", &row1);
  printf("Digite o numero de colunas da segunda matriz: ");
  scanf("%d", &col1);
  printf("Digite o escalar a ser multiplicado: ");
  scanf("%d", &escalar);
  matrix = createMatrix(row, col);
  matrix1 = createMatrix(row1,col1);
  fileFillMatrix(matrix, nomeArquivo);
  fileFillMatrix(matrix1, nomeArquivo1);
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