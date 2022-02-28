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
   const char *valid_subtractions[6] = { "IV", "IX",
                             "XL", "XC",
                             "CD", "CM"};
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
  for( int i = 0; i < size ; i++){
    //cout << num_romano[i] << endl;
    cout << converte_digito(num_romano[i]) << endl;
    if( !converte_digito(num_romano[i] )) {
     // cout << "numero invalido" << endl;
      return false;
    }else{
      cout << "diferente de falso" << endl;
    }
    if(num_romano[i] == char_repetido){
      contador_repetido += 1;
    }
    if(num_romano[i] != char_repetido){
      contador_repetido =0;
    }
    char_repetido = num_romano[i];
    if(contador_repetido >= 3){
      //cout << "repetiu demais" << endl;
      return false;
    }
    if ( i + 1 < size) {
      if ( converte_digito(num_romano[i]) < converte_digito(num_romano[i + 1]) ){
        string pair;
        pair += num_romano[i];
        pair += num_romano[i + 1];
        if( verify_pair(pair) == false){
          return false;}
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