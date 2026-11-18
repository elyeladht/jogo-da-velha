# Jogo da Velha — TDD

Verificador de estado do jogo da velha em C++, desenvolvido com **Desenvolvimento Orientado a Testes (TDD)**.
Trabalho 1 da disciplina **Técnicas de Programação 2 (CIC0198)** — Universidade de Brasília (UnB), Departamento de Ciência da Computação.

## Sobre o projeto

O tabuleiro é representado por uma matriz `3x3` de inteiros:

| Valor | Significado         |
| ----- | ------------------- |
| `0`   | posição vazia       |
| `1`   | posição com **X**   |
| `2`   | posição com **O**   |

Exemplo:

```
[ 2, 0, 1 ]
[ 0, 2, 0 ]
[ 1, 0, 1 ]
```

A função principal analisa o tabuleiro e retorna:

| Retorno | Significado                                                    |
| ------- | -------------------------------------------------------------- |
| `1`     | X venceu                                                       |
| `2`     | O venceu                                                       |
| `0`     | jogo empatado                                                  |
| `-1`    | jogo indefinido (ainda em andamento, ex.: apenas um X)         |
| `-2`    | jogo impossível pelas regras (ex.: todas as posições são X)    |

## Interface (`velha.hpp`)

```cpp
int VerificaVelha(const int velha[3][3]);
int GanhadorVelha(const int velha[3][3]);
```

## Estrutura do repositório

```
.
├── velha.hpp          # declaração das funções
├── velha.cpp          # implementação
├── testa_velha.cpp    # testes (framework Catch)
├── catch.hpp          # framework de testes Catch
├── Makefile           # compilação, testes e ferramentas de qualidade
├── cpplint.py         # verificador de estilo
├── CPPLINT.cfg        # configuração do cpplint
└── leia_me.txt        # instruções de compilação
```

## Requisitos

- Linux (Ubuntu)
- `g++` com suporte a C++11
- `make`
- `cpplint`, `cppcheck`, `gcov`, `valgrind` e `gdb` (para as verificações de qualidade)

```bash
sudo apt install build-essential cppcheck valgrind gdb
pip install cpplint
```

## Como compilar e executar

```bash
git clone https://github.com/elyeladht/jogo-da-velha.git
cd jogo-da-velha
make all
```

O `make all` compila o projeto e já executa os testes.

## Comandos do Makefile

| Comando         | O que faz                                                                  |
| --------------- | -------------------------------------------------------------------------- |
| `make all`      | compila e executa os testes                                                |
| `make compile`  | apenas compila, gerando o executável `testa_velha`                         |
| `make test`     | executa os testes                                                          |
| `make cpplint`  | verifica o estilo do código (Google C++ Style Guide), ignorando `catch.hpp` |
| `make cppcheck` | análise estática (`cppcheck --enable=warning .`)                           |
| `make gcov`     | compila com cobertura, executa os testes e gera os arquivos `.gcov`        |
| `make valgrind` | verificação dinâmica de memória (relatório em `valgrind.rpt`)              |
| `make debug`    | compila com `-g` e abre o `gdb`                                            |
| `make clean`    | remove arquivos gerados (`.o`, `.gc*`, executável)                         |

## Metodologia

O desenvolvimento seguiu o ciclo do TDD, com histórico registrado no Git:

1. **Red** — escrever um teste que falha;
2. **Green** — escrever o mínimo de código para o teste passar;
3. **Refactor** — melhorar o código mantendo os testes passando.

Foi feito um commit para cada teste criado, cada teste que passou e cada refatoração. Consulte o histórico com:

```bash
git log --oneline
```

## Qualidade do código

- **Estilo:** `cpplint` (Google C++ Style Guide)
- **Testes:** framework [Catch](https://github.com/catchorg/Catch2)
- **Cobertura:** `gcov`, com meta de pelo menos 80% por módulo
- **Análise estática:** `cppcheck`
- **Análise dinâmica:** `valgrind`
- **Depuração:** `gdb`

## Autor

**Elyel Adohoueto** — Engenharia de Computação, UnB
GitHub: [@elyeladht](https://github.com/elyeladht)
