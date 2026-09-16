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

// Protótipo da Função auxiliar
int GanhadorVelha(int velha[3][3]);

// Função principal de verificação
int VerificaVelha(int velha[3][3]) {
  // Verificando jogo inválido (1) (diferença de peças)
  int o = 0, x = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (velha[i][j] == 1) {
        x++;
      } else if (velha[i][j] == 2) {
        o++;
      }
    }
  }

  if (std::abs(x - o) > 1) {
    return -2;
  }

  // Passando a matriz para a função auxiliar
  // Chama para determinar o vencedor ou se teve jogo inválido
  return GanhadorVelha(velha);
}

int GanhadorVelha(int velha[3][3]) {
  // Conta a
  int xGanhou = 0, oGanhou = 0;

  // Verificador de colunas
  for (int j = 0; j < 3; j++) {
    if (velha[0][j] == velha[1][j] && velha[1][j] == velha[2][j] && velha[0][j] != 0) {
      if (velha[0][j] == 1) {
        xGanhou++;
      } else if (velha[0][j] == 2) {
        oGanhou++;
      }
    }
  }

  // Verificador de linhas
  for (int i = 0; i < 3; i++) {
    if (velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2] && velha[i][0] != 0) {
      if (velha[i][0] == 1) {
        xGanhou++;
      } else if (velha[i][0] == 2) {
        oGanhou++;
      }
    }
  }

  // Diagonal principal (garantindo que não seja vazia)
  if (velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2] && velha[1][1] != 0) {
    if (velha[0][0] == 1) {
      xGanhou++;
    } else if (velha[0][0] == 2) {
      oGanhou++;
    }
  }

  // Diagonal secundaria (garantindo que não seja vazia)
  if (velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0] && velha[1][1] != 0) {
    if (velha[0][2] == 1) {
      xGanhou++;
    } else if (velha[0][2] == 2) {
      oGanhou++;
    }
  }

  // Se ambos ganharam ao mesmo tempo, é jogo inválido
  if (xGanhou > 0 && oGanhou > 0) {
    return -2;
  }

  if (xGanhou > oGanhou) {
    return 1;
  } else if (oGanhou > xGanhou) {
    return 2;
  } else {
    return 0; // Nenhum vencedor
  }
}