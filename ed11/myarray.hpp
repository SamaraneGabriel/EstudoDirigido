#define _MYARRAY_HPP_
// dependencias
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream ; // para ler arquivo
template < typename T >
class Array
{
private: 
T optional;
int length;
T *data;
public: 
Array ( int n, T initial )
{
optional = initial;
length = 0;
data = nullptr;

if ( n > 0 )
{
length = n;
data = new T [ length ];
}
}
void free ( )
{
if ( data != nullptr )
{
delete ( data );
data = nullptr;
} 
} 
void set ( int position, T value )
{
if ( 0 <= position && position < length )
{
data [ position ] = value;
} 
} 
T get ( int position )
{
T value = optional;
if ( 0 <= position && position < length )
{
value = data [ position ];
} 
return ( value );
} 
void print ( )
{
cout << endl;
for ( int x = 0; x < length; x=x+1 )
{
cout << setw( 3 ) << x << " : "
<< setw( 9 ) << data[ x ]
<< endl;
} 
cout << endl;
}
void randomInt(int inferior, int superior){
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    int num1 = rand();
    int num2 = num1 % superior + inferior;
    data[i] = num2;
    }
  }
void printArrayFile(char* fileName){
  ofstream myfile;
  myfile.open (fileName);
  myfile << length;
  myfile << "\n";
  for(int i = 0; i < length; i++){
    myfile << data[i];
    myfile << "\n";
  }
  myfile.close();
}
int maiorImpar(){
  int maior = 0;
  for(int i = 0; i < length; i++){
    if((data[i] > maior) && (data[i] % 2 != 0)){
      maior = data[i];
    }
  }
  return maior;
}
int menorPar(){
  int contador = 0;
  int *arrayPar = new int[100];
  cout << arrayPar[0];
  for(int i = 0; i < length; i++){
    if(data[i] %2 == 0){
      arrayPar[i] = data[i];
      cout << arrayPar[i];
      contador++;
    }
  }
  int menor = arrayPar[0];
  for(int i = 0; i < contador; i++){
    if(arrayPar[i] < menor){
      menor = arrayPar[i];
    }
  }
  return menor;
}
void readArrayFile(char* fileName){
  ifstream myfile;
  myfile.open(fileName);
  for(int i = 0; i <length; i++){
    myfile >> data[i];
  }
  myfile.close();
}
T somaArray(){
  T soma;
  for(int i = 0; i < length; i++){
      soma = soma + data[i];
  }
  return soma;
}
double mediaIntervalo(int inferior, int superior){
  double soma = 0.0;
  double size = superior - inferior;
  for(int i = inferior; i <= superior; i++){
    soma = soma + data[i];
  }
  return soma/(size+1);
}
bool arrayPositive(){
  bool p = true;
  for(int i = 0; i < length; i++){
    if(data[i] < 0) {
      p = false;
    }
  }
  return p;
}
};