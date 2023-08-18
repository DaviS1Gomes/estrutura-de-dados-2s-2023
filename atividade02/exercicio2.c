#include<stdio.h>


int maior_menor_array(int variables[], int size){
  int i ,maior = variables[0],menor = variables[0];
  
  for(i = 1; i < size; i++){
    if(variables[i] < menor){
      menor = variables[i];
    }

    if(variables[i] > maior){
      maior = variables[i];
    }

  }
  printf("%d, %d", maior, menor);
  }

int main(){

  int array[] = {4,5,6,7};
  int tamanho = sizeof(array) / sizeof(array[0]);
 
  
  maior_menor_array(array,tamanho);
  return 0;
}