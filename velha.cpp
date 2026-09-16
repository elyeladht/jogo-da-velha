/**
 * \file  velha.cpp
 */

#include "velha.hpp"
#include <cmath>

// Protótipo da Função auxiliar
int GanhadorVelha(int velha[3][3]);

// Função principal de verificação
int VerificaVelha(int velha[3][3]) {
  int o = 0, x = 0, espaco = 0;

  // 1. Contagem de elementos no tabuleiro
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (velha[i][j] == 1) {
        x++;
      } else if (velha[i][j] == 2) {
        o++;
      } else {
        espaco++;
      }
    }
  }

  // 2. Validação por quantidade de peças (Jogo Inválido)
  if (std::abs(x - o) > 1) {
    return -2;
  }

  // 3. Determina o status do tabuleiro (1, 2, -2 ou 0)
  int resultadoGanhador = GanhadorVelha(velha);

  // Se houve um vencedor (1 ou 2) ou se deu jogo inválido por duplo vencedor (-2)
  if (resultadoGanhador != 0) {
    return resultadoGanhador;
  }

  // 4. Se ninguém ganhou (resultadoGanhador == 0)
  if (espaco > 0) {
    return -1; // Jogo em andamento
  }

  return 0; // Empate (velha) - tabuleiro cheio e sem vencedor
}

int GanhadorVelha(int velha[3][3]) {
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

  // Diagonal principal
  if (velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2] && velha[1][1] != 0) {
    if (velha[0][0] == 1) {
      xGanhou++;
    } else if (velha[0][0] == 2) {
      oGanhou++;
    }
  }

  // Diagonal secundaria
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
    return 0; // Nenhum vencedor ainda
  }
}