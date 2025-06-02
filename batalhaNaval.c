#include <stdio.h>

#define TABULEIRO_TAMANHO 10
#define NAVIO_TAMANHO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO]) {
    for (int i = 0; i < TABULEIRO_TAMANHO; i++) {
        for (int j = 0; j < TABULEIRO_TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO]) {
    printf("  "); // Espaço para alinhar com os índices das colunas
    for (int j = 0; j < TABULEIRO_TAMANHO; j++) {
        printf("%d ", j); // Imprime os índices das colunas
    }
    printf("\n");

    for (int i = 0; i < TABULEIRO_TAMANHO; i++) {
        printf("%d ", i); // Imprime o índice da linha
        for (int j = 0; j < TABULEIRO_TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio no tabuleiro
// Retorna 1 se o navio foi posicionado com sucesso, 0 caso contrário
int posicionarNavio(int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO],
                   int linhaInicial, int colunaInicial, char orientacao) {

    // Valida se as coordenadas iniciais estão dentro dos limites do tabuleiro
    if (linhaInicial < 0 || linhaInicial >= TABULEIRO_TAMANHO ||
        colunaInicial < 0 || colunaInicial >= TABULEIRO_TAMANHO) {
        printf("Erro: Coordenadas iniciais fora dos limites do tabuleiro.\n");
        return 0;
    }

    // Verifica e posiciona o navio com base na orientação
    if (orientacao == 'H' || orientacao == 'h') { // Navio horizontal
        // Valida se o navio cabe no tabuleiro horizontalmente
        if (colunaInicial + NAVIO_TAMANHO > TABULEIRO_TAMANHO) {
            printf("Erro: Navio horizontal excede os limites do tabuleiro.\n");
            return 0;
        }
        // Valida sobreposição
        for (int j = 0; j < NAVIO_TAMANHO; j++) {
            if (tabuleiro[linhaInicial][colunaInicial + j] == NAVIO) {
                printf("Erro: Navio horizontal se sobrepõe a outro navio.\n");
                return 0;
            }
        }
        // Posiciona o navio
        for (int j = 0; j < NAVIO_TAMANHO; j++) {
            tabuleiro[linhaInicial][colunaInicial + j] = NAVIO;
        }
    } else if (orientacao == 'V' || orientacao == 'v') { // Navio vertical
        // Valida se o navio cabe no tabuleiro verticalmente
        if (linhaInicial + NAVIO_TAMANHO > TABULEIRO_TAMANHO) {
            printf("Erro: Navio vertical excede os limites do tabuleiro.\n");
            return 0;
        }
        // Valida sobreposição
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            if (tabuleiro[linhaInicial + i][colunaInicial] == NAVIO) {
                printf("Erro: Navio vertical se sobrepõe a outro navio.\n");
                return 0;
            }
        }
        // Posiciona o navio
        for (int i = 0; i < NAVIO_TAMANHO; i++) {
            tabuleiro[linhaInicial + i][colunaInicial] = NAVIO;
        }
    } else {
        printf("Erro: Orientacao invalida. Use 'H' para horizontal ou 'V' para vertical.\n");
        return 0;
    }

    return 1; // Navio posicionado com sucesso
}

int main() {
    int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO];

    // 1. Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // 2. Posiciona o primeiro navio (horizontal)
    // Coordenadas iniciais do navio 1
    int linhaNavio1 = 2;
    int colunaNavio1 = 3;
    char orientacaoNavio1 = 'H';

    printf("Tentando posicionar Navio 1 (horizontal) em (%d, %d)...\n", linhaNavio1, colunaNavio1);
    if (!posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, orientacaoNavio1)) {
        printf("Nao foi possivel posicionar o Navio 1. Verifique as coordenadas.\n");
    }

    // 2. Posiciona o segundo navio (vertical)
    // Coordenadas iniciais do navio 2
    int linhaNavio2 = 4;
    int colunaNavio2 = 5;
    char orientacaoNavio2 = 'V';

    printf("\nTentando posicionar Navio 2 (vertical) em (%d, %d)...\n", linhaNavio2, colunaNavio2);
    if (!posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, orientacaoNavio2)) {
        printf("Nao foi possivel posicionar o Navio 2. Verifique as coordenadas ou sobreposicao.\n");
    }

    // Exemplo de teste de sobreposição ou fora do limite (descomente para testar)
    // printf("\nTentando posicionar Navio 3 (horizontal) em (2, 4) - Deverá sobrepor o Navio 1...\n");
    // if (!posicionarNavio(tabuleiro, 2, 4, 'H')) {
    //     printf("Teste de sobreposicao funcionou como esperado.\n");
    // }

    // printf("\nTentando posicionar Navio 4 (vertical) em (8, 9) - Deverá exceder o limite...\n");
    // if (!posicionarNavio(tabuleiro, 8, 9, 'V')) {
    //     printf("Teste de limite excedido funcionou como esperado.\n");
    // }

    // 3. Exibe o tabuleiro com os navios posicionados
    printf("\n--- Tabuleiro de Batalha Naval ---\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}