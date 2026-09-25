#include <stdio.h>

int lerProtecao(void) {
    int protecao;
    int valido = 0;

    while (!valido) {
        printf("Deseja contratar protecao? (1-Sim, 0-Nao): ");
        scanf("%d", &protecao);

        if (protecao == 0 || protecao == 1) {
            valido = 1;
        } else {
            printf("Valor invalido. Digite 0 ou 1.\n");
        }
    }

    return protecao;
}

int lerModalidade(void) {
    int modalidade;
    int valido = 0;

    while (!valido) {
        printf("Escolha a modalidade (1-Economica, 2-Expressa, 3-Prioritaria): ");
        scanf("%d", &modalidade);

        if (modalidade == 1 || modalidade == 2 || modalidade == 3) {
            valido = 1;
        } else {
            printf("Modalidade invalida. Digite 1, 2 ou 3.\n");
        }
    }

    return modalidade;
}

float lerPeso(void) {
    float peso;
    int valido = 0;

    while (!valido) {
        printf("Informe o peso da entrega (em kg): ");
        scanf("%f", &peso);

        if (peso > 0) {
            valido = 1;
        } else {
            printf("Peso invalido. Deve ser maior que zero.\n");
        }
    }

    return peso;
}

float lerDistancia(void) {
    float distancia;
    int valida = 0;

    while (!valida) {
        printf("Informe a distancia da entrega (em km): ");
        scanf("%f", &distancia);

        if (distancia > 0) {
            valida = 1;
        } else {
            printf("Distancia invalida. Deve ser maior que zero.\n");
        }
    }

    return distancia;
}


int main(void) {
    printf("Simulador de Entregas\n");

    float distancia = lerDistancia();
    float peso = lerPeso();
    int modalidade = lerModalidade();
    int protecao = lerProtecao();

    printf("Distancia valida recebida: %.2f km\n", distancia);
    printf("Peso valido recebido: %.2f kg\n", peso);
    printf("Modalidade valida recebida: %d\n", modalidade);
    printf("Protecao valida recebida: %d\n", protecao);

    return 0;
}