#include "romanos.hpp"
#include <string>
#include <iostream>
using namespace std;

int converte_digito(char d){
    if (d == 'I')
        return 1;
    if (d == 'V')
        return 5;
    if (d == 'X')
        return 10;
    if (d == 'L')
        return 50;
    if (d == 'C')
        return 100;
    if (d == 'D')
        return 500;
    if (d == 'M')
        return 1000;
    else{
      return false;
    }
}

bool verify_pair(string pair){
   const char *valid_subtractions[6] = {"IV", "IX","XL", "XC", "CD", "CM"};
    bool valid = false;
    for ( int j = 0; j < 6 ; j++ ){
      if (pair == valid_subtractions[j]){
        valid = true;
      }
    }
    return valid;
}

bool valida_romano(string num_romano){
  int size = num_romano.length();
  char char_repetido;
  int contador_repetido = 0;
  const char *invalid_equals[3] = {"VV", "LL","DD"};
  for( int i = 0; i < size ; i++){
    if( !converte_digito(num_romano[i] )) {
      return false;
    }else{
    }
    if(num_romano[i] == char_repetido){
      contador_repetido += 1;
    }
    if(num_romano[i] != char_repetido){
      contador_repetido =0;
    }
    char_repetido = num_romano[i];
    if(contador_repetido >= 3){
      return false;
    }
    if ( i + 1 < size) {
      if ( converte_digito(num_romano[i]) < converte_digito(num_romano[i + 1]) ){
        string pair;
        pair += num_romano[i];
        pair += num_romano[i + 1];
        if( verify_pair(pair) == false){
          return false;
        }
      }
    }
    if ( converte_digito(num_romano[i]) == converte_digito(num_romano[i + 1])){
      string equal_pair;
      equal_pair += num_romano[i];
      equal_pair += num_romano[i + 1];
      for( int j = 0 ; j < 3 ; j++){
        if (equal_pair == invalid_equals[j] ){
          return false;
        }
      }
    }
  if ( i + 2 < size ) {
    if ( converte_digito(num_romano[i]) < converte_digito(num_romano[i + 2]) ){
      return false;
    }
  }
  }
  return true;
}


int romanos_para_decimal(string num_romano)
{  
  if(valida_romano(num_romano) == false){
    return -1;
  }
  int resultado = 0;
  int size = num_romano.length();
  for( int i = 0; i < size ; i++){
    if( i + 1 < size){
      if ( converte_digito(num_romano[i]) >= converte_digito(num_romano[i + 1]) ) {
        resultado += converte_digito(num_romano[i]);
      }else{
        resultado -= converte_digito(num_romano[i]);
      }
    }else{
      resultado += converte_digito(num_romano[i]);
    }
  }
  return resultado;
}