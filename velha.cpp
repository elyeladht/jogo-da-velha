/**
 * \file  velha.cpp
 */

#include "velha.hpp"
#include <cmath>

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

int VerificaVelha(int velha[3][3]) {
  // Verificando jogo inválido
  int o = 0, x = 0;
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      if(velha[i][j] == 1) {
        x++;
      }
      else if(velha[i][j] == 2) {
        o++;
      }
    }
  }

  if (abs(x - o) > 1) {
    return -2;
  }

  // Verificador de colunas
  for (int j = 0; j < 3; j++) {
    if (velha[0][j] == velha[1][j] && velha[1][j] == velha[2][j] && velha[0][j] != 0) {
      return velha[0][j];  // Corresponde ao ganhador
    }
  }

  // Verificador de linhas
  for (int i = 0; i < 3; i++) {
    if (velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2] && velha[i][0] != 0) {
      return velha[i][0];  // Corresponde ao ganhador
    }
  }

  // Verificando as diagonais
  if (velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) {
    return velha[0][0];
  }

  if (velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0]) {
    return velha[0][2];
  }

  return 0;  // Nenhum vencedor encontrado ainda
}
