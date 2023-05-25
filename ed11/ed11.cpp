#include "myarray.hpp"
#include <iostream>
void menu() {
  int nmenu = 10;
  while (nmenu > 0) {
    printf("Para Exercicio %d, aperte %d \n \n", nmenu, nmenu);
    nmenu--;
  }
  printf("Para os exercícios extras, aperta 11 e 12 \n");
  printf("Digite 0 para sair \n");
}

void exercicio1() {
  int inferior = 0, superior = 0, size = 0;
  char fileName[80];
  cout << "Digite o nome do arquivo a salvar os dados: ";
  cin >> fileName;
  cout << "Digite o valor inferior: ";
  cin >> inferior;
  cout << "Digite o valor superior: ";
  cin >> superior;
  cout << "Digite o tamanho do vetor: ";
  cin >> size;
  Array<int> intArray(size, 0);
  intArray.randomInt(inferior, superior);
  intArray.printArrayFile(fileName);
}
void exercicio2() {
  char fileName[80];
  int size = 0, maior = 0;
  cout << "Digite o nome do arquivo a ler os dados: ";
  cin >> fileName;
  cout << "Digite o tamanho do vetor: ";
  cin >> size;
  Array<int> intArray(size, 0);
  intArray.readArrayFile(fileName);
  intArray.print();
  maior = intArray.maiorImpar();
  cout << "O maior impar da sequencia é:" << maior << endl;
}
void exercicio3() {
  char fileName[80];
  int size = 0, menor = 0;
  cout << "Digite o nome do arquivo a ler os dados: ";
  cin >> fileName;
  cout << "Digite o tamanho do vetor: ";
  cin >> size;
  Array<int> intArray(size, 0);
  intArray.readArrayFile(fileName);
  menor = intArray.menorPar();
  cout << "O menor par da sequencia é:" << menor << endl;
}
void exercicio4() {
  char fileName[80];
  int size = 0, soma = 0;
  cout << "Digite o nome do arquivo a ler os dados: ";
  cin >> fileName;
  cout << "Digite o tamanho do vetor: ";
  cin >> size;
  Array<int> intArray(size, 0);
  intArray.readArrayFile(fileName);
  soma = intArray.somaArray();
  cout << "A soma da sequência é: " << soma << endl;
}
void exercicio5() {
  char fileName[80];
  int size = 0, inferior = 0, superior = 0;
  double media = 0.0;
  cout << "Digite o nome do arquivo a ler os dados: ";
  cin >> fileName;
  cout << "Digite o tamanho do vetor: ";
  cin >> size;
  cout << "Digite o limite inferior: ";
  cin >> inferior;
  cout << "Digite o limite superior: ";
  cin >> superior;
  Array<int> intArray(size, 0);
  intArray.readArrayFile(fileName);
  intArray.print();
  media = intArray.mediaIntervalo(inferior, superior);
  cout << "A media da sequência é: " << media << endl;
}
void exercicio6() {
  char fileName[80];
  int size = 0;
  cout << "Digite o nome do arquivo a ler os dados: ";
  cin >> fileName;
  cout << "Digite o tamanho do vetor: ";
  cin >> size;
  Array<int> intArray(size, 0);
  intArray.readArrayFile(fileName);
  if(intArray.arrayPositive()){
    cout << "O arranjo é totalmente positivo";
  }
  else{
    cout << "O arranjo não é totalmente positivo";
  }
}
void exercicio7() {}
void exercicio8() {}
void exercicio9() {}
void exercicio10() {}
int main() {
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