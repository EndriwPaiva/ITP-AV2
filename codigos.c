#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 10
#define NUM_NOTAS 3

// Função 1: Ler e validar os dados dos estudantes (nomes e notas)
void lerDados(int n, char nomes[MAX_ALUNOS][50], float notas[MAX_ALUNOS][NUM_NOTAS]) {
    for (int i = 0; i < n; i++) {
        printf("\nEstudante %d \n", i + 1);
        
        // Validação de nome não vazio e respeitando o limite do vetor
        do {
            printf("Nome: ");
            if (fgets(nomes[i], 50, stdin) != NULL) {
                nomes[i][strcspn(nomes[i], "\n")] = 0; // Remove a quebra de linha
            }
            if (strlen(nomes[i]) == 0) {
                printf("O nome nao pode estar vazio! Tente novamente.\n");
            }
        } while (strlen(nomes[i]) == 0);

        // Leitura e validação das notas (intervalo de 0 a 10)
        for (int j = 0; j < NUM_NOTAS; j++) {
            do {
                printf("  Digite a nota %d (0 a 10): ", j + 1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("  Nota invalida! Valores permitidos entre 0 e 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
        while (getchar() != '\n'); // Limpa o buffer do teclado
    }
}

// Função 2: Calcular as médias aritméticas e preencher o vetor dinâmico via ponteiro
void calcularMedias(int n, float notas[MAX_ALUNOS][NUM_NOTAS], float *medias) {
    for (int i = 0; i < n; i++) {
        float soma = 0;
        for (int j = 0; j < NUM_NOTAS; j++) {
            soma += notas[i][j];
        }
        medias[i] = soma / NUM_NOTAS; // Divisão em ponto flutuante para evitar perda de dados
    }
}

// Função 3: tabela com notas, médias e situação
void exibirResultados(int n, char nomes[MAX_ALUNOS][50], float notas[MAX_ALUNOS][NUM_NOTAS], float *medias) {
    printf("%-15s | %-6s %-6s %-6s | %-6s | %s\n", "Nome", "Nota 1", "Nota 2", "Nota 3", "Media", "Situacao");
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%-15s | %6.1f %6.1f %6.1f | %6.1f | ", nomes[i], notas[i][0], notas[i][1], notas[i][2], medias[i]);
        
        if (medias[i] >= 6.0) {
            printf("atingiu a meta\n");
        } else {
            printf("abaixo da meta\n");
        }
    }
}

// Função 4: Calcular a média geral da turma e empates se tiver 
void exibirEstatisticas(int n, char nomes[MAX_ALUNOS][50], float *medias) {
    float somaGeral = 0;
    float maiorMedia = medias[0];

    for (int i = 0; i < n; i++) {
        somaGeral += medias[i];
        if (medias[i] > maiorMedia) {
            maiorMedia = medias[i];
        }
    }
    float mediaGeral = somaGeral / n;

    printf("\nMedia geral da turma: %.2f\n", mediaGeral);
    printf("Estudante(s) com a maior media (%.2f):\n", maiorMedia);
    for (int i = 0; i < n; i++) {
        if (medias[i] == maiorMedia) {
            printf("- %s\n", nomes[i]);
        }
    }
}

int main() {
    int n;

    // Ve se tem entre 1 a 10 alunos
    do {
        printf("Digite a quantidade de estudantes (1 a 10): ");
        scanf("%d", &n);
        if (n < 1 || n > MAX_ALUNOS) {
            printf("Quantidade invalida! Deve ser entre 1 e 10.\n");
        }
    } while (n < 1 || n > MAX_ALUNOS);

    while (getchar() != '\n'); // Limpar buffer inicial

    char nomes[MAX_ALUNOS][50];
    float notas[MAX_ALUNOS][NUM_NOTAS];

    // Função 1
    lerDados(n, nomes, notas);

    // Alocar o vetor dinâmico de resultados com malloc
    float *medias = (float *)malloc(n * sizeof(float));
    if (medias == NULL) {
        printf("Erro crítico: Falha ao alocar memória!\n");
        return 1;
    }

    // Inicializar os elementos antes de ler eles
    for (int i = 0; i < n; i++) {
        medias[i] = 0.0f;
    }

    // Função 2 
    calcularMedias(n, notas, medias);

    // Função 3
    exibirResultados(n, nomes, notas, medias);

    // Função 4
    exibirEstatisticas(n, nomes, medias);

    // Liberar a área de memória com free
    free(medias);
    medias = NULL; 

    return 0;
}