# Jogo da Velha

Projeto desenvolvido em linguagem C que implementa o clássico jogo da velha, com dois modos de jogo:
- Singleplayer (Jogador vs Maquina)
- Multiplayer (Jogador vs Jogador)

---

# Integrantes do  Grupo 01

- Arthur Alves Acioli
- Arthur Torres Gurgel
- Augusto Melo Moulin Breda
- Brenda Pizano Purificati
- Camila de Moraes Passalini

---

# Descrição do Projeto

Este projeto consiste na implementação de um jogo da velha clássico pelo terminal, utilizando a linguagem de programação C.
O projeto utiliza uma abordagem modular baseada em funções, o que facilita a organização, leitura e manutenção do código.
O jogo permite que o usuário escolha o modo de jogo entre jogar contra outro jogador humano ou contra o computador e quem irá começar jogando.
O tabuleiro do jogo é representado por uma matriz 3x3 de caracteres, onde cada posição da matriz pode assumir os valor "X", "O" ou " " (espaço vazio).

# Principais Funções 

- "inicializarTabuleiro()" é a função responsável por preparar o incio da partida, preenchendo todas as posições da matriz com espaços vazios.
- "mostrarTabuleiro()" é a função responsável por exibir o estado atual do tabuleiro no terminal, possibilitando que os jogadores visualizem suas jogadas ao decorrer da partida.
- "verificarVitoria()" como o próprio nome já diz, é a função responsável por analisar o tabuleiro após cada jogada, verificando todas as possibilidades de vencer o jogo. Caso algum jogador tenha vencido a partida a função retorna o simbolo correspondente do vencedor.
- "verificarEmpate()" a função percorre todas as posições do tabuleiro identifcando se ainda resta pelo menos uma com espaço vazio. Caso não exista nenhuma posição disponível e não haja um vencedor, o jogo é considerado empatado.
- "jogadaJogador()" é a função responsável pela leitura da jogada do jogador humano solicitando a linha e a coluna que o jogador pretende fazer sua jogada. Essa função também valida a jogada, garantindo que a posição informada respeite os limites do tabuleiro e que a posição escolhida esteja livre.
