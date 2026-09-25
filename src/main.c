#include <stdio.h>

float calcularValorBase(float distancia) {
    float valorBase;

    if (distancia <= 5) {
        valorBase = 8.00;
    } else if (distancia <= 15) {
        valorBase = 12.00;
    } else if (distancia <= 30) {
        valorBase = 18.00;
    } else {
        valorBase = 25.00;
    }

    return valorBase;
}

int lerTentativas(void) {
    int tentativas;
    int valido = 0;

    while (!valido) {
        printf("Quantas tentativas adicionais? (0 ou mais): ");
        scanf("%d", &tentativas);

        if (tentativas >= 0) {
            valido = 1;
        } else {
            printf("Valor invalido. Deve ser 0 ou maior.\n");
        }
    }

    return tentativas;
}

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
    int tentativas = lerTentativas();

    float valorBase = calcularValorBase(distancia);

    printf("Valor-base calculado: R$ %.2f\n", valorBase);

    return 0;
}
