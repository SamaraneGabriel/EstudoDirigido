#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções auxiliares
void menu() {
  int nmenu = 10;
  while (nmenu > 0) {
    printf("Para Exercicio %d, aperte %d \n \n", nmenu, nmenu);
    nmenu--;
  }
  printf("Para os exercícios extras, aperta 11 e 12 \n");
  printf("Digite 0 para sair \n");
}
bool checkNegOdd(int n) {
  if (n % 2 != 0 || n < 0) {
    return true;
  }
  return false;
}
bool isOrderedDecre(int array[], int n) {
  bool p = true;
  for (int i = 0; i < n; i++) {
    if (array[i + 1] > array[i]) {
      p = false;
    }
  }
  return p;
}
bool existValue(double valor, int inicial, int n, double *array) {
  bool p = false;
  for (int i = inicial; i < n; i++) {
    if (array[i] == valor) {
      p = true;
    }
  }
  return p;
}

// Funções Principais

void checkArray(int n, int array[]) {
  if (n != 0) {
    for (int i = 0; i < n; i++) {
      if (array[i] < 0 || array[i] % 2 != 0) {
        printf("A posição %d do vetor não atende as necessidades\n", i);
      }
    }
  } else {
    printf("Vetor nulo");
  }
}
void fileCheckArray(char fileName[], int array[]) {
  FILE *arquivo = fopen(fileName, "r");
  FILE *resultado = fopen("resposta.txt", "w");
  int num = 0, contador = 0;
  if (arquivo == NULL) {
    printf("Arquivo inexistente!");
  } else {
    while (fscanf(arquivo, "%d", &num) == 1) {
      if (!checkNegOdd(num)) {
        printf("%d\n", num);
        array[contador] = num;
        contador++;
      }
    }
  }
  fprintf(resultado, "%d\n", contador);
  for (int i = 0; i < contador; i++) {
    fprintf(resultado, "%d\n", array[i]);
  }
  fclose(arquivo);
  fclose(resultado);
}
int randomInt(int inferior, int superior) {
  int num1 = rand();
  int num2 = num1 % superior + inferior;
  return num2;
}
void fileRand(int n, int inferior, int superior) {
  FILE *arquivo = fopen("DADOS.txt", "w");
  fprintf(arquivo, "%d\n", n);
  for (int i = 0; i < n; i++) {
    fprintf(arquivo, "%d\n", randomInt(inferior, superior));
  }
  fclose(arquivo);
}

int *createArray(int n, char nomeArquivo[], int *array) {
  FILE *arquivo = fopen(nomeArquivo, "r");
  int num = 0;
  fscanf(arquivo, "%d", &num);
  for (int i = 0; i < n; i++) {
    array[i] = num;
    fscanf(arquivo, "%d", &num);
  }
  return array;
}

int acharMenorPar(int *array, int n) {
  int menorPar = array[0];
  for (int i = 0; i < n; i++) {
    if (array[i] % 2 == 0 && array[i] < menorPar) {
      menorPar = array[i];
    }
  }
  if (menorPar % 2 == 0) {
    return menorPar;
  } else {
    return -1;
  }
}
int acharMaiorImpar(int *array, int n) {
  int maiorImpar = array[0];
  for (int i = 0; i < n; i++) {
    if (array[i] % 2 != 0 && array[i] > maiorImpar) {
      maiorImpar = array[i];
    }
  }
  if (maiorImpar % 2 != 0) {
    return maiorImpar;
  } else {
    return -1;
  }
}
// Caso especial da funcao createArray, onde o arquivo lido vai ser
// necessariamente o "DADOS.txt"para questoes {6,8,9,10}
double *createArrayDados(int n, double *array) {
  FILE *arquivo = fopen("DADOS.txt", "r");
  int num = 0;
  fscanf(arquivo, "%d", &num);
  for (int i = 0; i < n; i++) {
    array[i] = num;
    fscanf(arquivo, "%d", &num);
  }
  return array;
}
void checkMedia(double array[], int n) {
  FILE *arquivo1 = fopen("maiorMedia.txt", "w");
  FILE *arquivo2 = fopen("menorMedia.txt", "w");
  double media = 0;
  n = (double)n;
  for (int i = 0; i < n; i++) {
    media = media + (array[i] / n);
  }
  for (int i = 0; i < n; i++) {
    if (array[i] > media) {
      fprintf(arquivo1, "%0.1lf\n", array[i]);
    } else if (array[i] < media) {
      fprintf(arquivo2, "%0.1lf\n", array[i]);
    } else {
      fprintf(arquivo1, "%0.1lf\n", array[i]);
      fprintf(arquivo2, "%0.1lf\n", array[i]);
    }
  }
  fclose(arquivo1);
  fclose(arquivo2);
}

void existValueLoc(double valor, int inicial, int n, double *array) {
  for (int i = inicial; i < n; i++) {
    if (array[i] == valor) {
      printf("O valor existe na posicao %d \n", i);
    }
  }
}
int existValueQuant(double valor, int inicial, int n, double *array) {
  int cont = 0;
  for (int i = inicial; i < n; i++) {
    if (array[i] == valor) {
      cont = cont + 1;
    }
  }
  return cont;
}
// métodos
void exercicio1() {
  int array[] = {1, 2, 3, 4, 5};
  checkArray(5, array);
}
void exercicio2() {
  char nomeArquivo[80];
  int array[100];
  printf("Digite o nome do arquivo: \n");
  scanf("%s", nomeArquivo);
  fileCheckArray(nomeArquivo, array);
  printf("Digite ENTER para continuar: ");
  getchar();
}
void exercicio3() {
  int n = 0, inferior = 0, superior = 0;
  printf("Digit a quantidade de números aleatorios: ");
  scanf("%d", &n);
  printf("Digit o limite inferior: ");
  scanf("%d", &inferior);
  printf("Digit o limite superior: \n");
  scanf("%d", &superior);
  fileRand(n, inferior, superior);
  printf("Digite ENTER para continuar: ");
  getchar();
}
void exercicio4() {
  char nomeArquivo[80];
  int n = 0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  int array[n];
  printf("Digite o nome do arquvio: ");
  scanf("%s", nomeArquivo);
  int *resul = createArray(n, nomeArquivo, array);
  printf("O menor numero par do vetor é: %d\n", acharMenorPar(resul, n));
  printf("Digite ENTER para continuar: ");
  getchar();
}
void exercicio5() {
  char nomeArquivo[80];
  int n = 0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  int array[n];
  printf("Digite o nome do arquvio: ");
  scanf("%s", nomeArquivo);
  int *resul = createArray(n, nomeArquivo, array);
  printf("O maior numero impar do vetor é: %d\n", acharMaiorImpar(resul, n));
  printf("Digite ENTER para continuar: ");
  getchar();
}
void exercicio6() {
  int n = 0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  double array[n];
  double *resul = createArrayDados(n, array);
  checkMedia(array, n);
  printf("Digite ENTER para continuar: ");
  getchar();
}
void exercicio7() {
  int array[] = {5, 4, 3, 2, 1};
  if (isOrderedDecre(array, 5)) {
    printf("Esta ordenado!");
  } else {
    printf("Não esta ordenado!");
  }
}
void exercicio8() {
  int n = 0, inicial = 0;
  double valor = 0.0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  double array[n];
  printf("Digite a quantidade procurada:");
  scanf("%lf", &valor);
  printf("Digite o valor incial de busca: ");
  scanf("%d", &inicial);
  double *resul = createArrayDados(n, array);
  if (existValue(valor, inicial, n, array)) {
    printf("Existe o valor");
  } else {
    printf("Não existe o valor");
  }
}

void exercicio9() {
  int n = 0, inicial = 0;
  double valor = 0.0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  double array[n];
  printf("Digite a quantidade procurada:");
  scanf("%lf", &valor);
  printf("Digite o valor incial de busca: ");
  scanf("%d", &inicial);
  double *resul = createArrayDados(n, array);
  existValueLoc(valor, inicial, n, resul);
}
void exercicio10() {
  int n = 0, inicial = 0;
  double valor = 0.0;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  double array[n];
  printf("Digite a quantidade procurada:");
  scanf("%lf", &valor);
  printf("Digite o valor incial de busca: ");
  scanf("%d", &inicial);
  double *resul = createArrayDados(n, array);
  printf("O numero %0.1lf se repete %d vezes",valor,existValueQuant(valor, inicial, n, resul));
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