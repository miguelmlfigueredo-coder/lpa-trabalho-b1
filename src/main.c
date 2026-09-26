#include <stdio.h>

int lerContinuar(void) {
    int continuar;
    int valido = 0;

    while (!valido) {
        printf("Deseja processar outra entrega? (1-Sim, 0-Nao): ");
        scanf("%d", &continuar);

        if (continuar == 0 || continuar == 1) {
            valido = 1;
        } else {
            printf("Valor invalido. Digite 0 ou 1.\n");
        }
    }

    return continuar;
}

float calcularValorFinal(float subtotalInicial, float adicionalPeso, float adicionalModalidade, int protecao, int tentativas) {
    const float VALOR_PROTECAO = 7.50;
    const float VALOR_TENTATIVA = 4.00;
    float valorFinal;
    float valorProtecao;
    float valorTentativas;

    if (protecao == 1) {
        valorProtecao = VALOR_PROTECAO;
    } else {
        valorProtecao = 0.00;
    }

    valorTentativas = tentativas * VALOR_TENTATIVA;

    valorFinal = subtotalInicial + adicionalPeso + adicionalModalidade + valorProtecao + valorTentativas;

    return valorFinal;
}

float calcularAdicionalModalidade(int modalidade, float subtotalInicial) {
    float percentual;

    if (modalidade == 1) {
        percentual = 0.00;
    } else if (modalidade == 2) {
        percentual = 0.15;
    } else {
        percentual = 0.30;
    }

    return subtotalInicial * percentual;
}

float calcularAdicionalPeso(float peso, float subtotalInicial) {
    float percentual;

    if (peso <= 2) {
        percentual = 0.00;
    } else if (peso <= 5) {
        percentual = 0.05;
    } else if (peso <= 10) {
        percentual = 0.10;
    } else {
        percentual = 0.20;
    }

    return subtotalInicial * percentual;
}

float calcularSubtotalInicial(float valorBase, float distancia) {
    const float TARIFA = 1.20;
    float subtotal;

    subtotal = valorBase + (distancia * TARIFA);

    return subtotal;
}

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

    int totalEntregas = 0;
    float valorTotal = 0.00;
    int qtdEconomica = 0;
    int qtdExpressa = 0;
    int qtdPrioritaria = 0;
    float maiorValor = 0.00;
    float menorValor = 0.00;
    int continuar = 1;

    while (continuar == 1) {
        float distancia = lerDistancia();
        float peso = lerPeso();
        int modalidade = lerModalidade();
        int protecao = lerProtecao();
        int tentativas = lerTentativas();

        float valorBase = calcularValorBase(distancia);
        float subtotalInicial = calcularSubtotalInicial(valorBase, distancia);
        float adicionalPeso = calcularAdicionalPeso(peso, subtotalInicial);
        float adicionalModalidade = calcularAdicionalModalidade(modalidade, subtotalInicial);
        float valorFinal = calcularValorFinal(subtotalInicial, adicionalPeso, adicionalModalidade, protecao, tentativas);

        printf("Valor final da entrega: R$ %.2f\n", valorFinal);

        totalEntregas = totalEntregas + 1;
        valorTotal = valorTotal + valorFinal;

        if (modalidade == 1) {
            qtdEconomica = qtdEconomica + 1;
        } else if (modalidade == 2) {
            qtdExpressa = qtdExpressa + 1;
        } else {
            qtdPrioritaria = qtdPrioritaria + 1;
        }

        if (totalEntregas == 1) {
            maiorValor = valorFinal;
            menorValor = valorFinal;
        } else {
            if (valorFinal > maiorValor) {
                maiorValor = valorFinal;
            }
            if (valorFinal < menorValor) {
                menorValor = valorFinal;
            }
        }

        continuar = lerContinuar();
    }

    printf("Fim da sessao. Total de entregas: %d\n", totalEntregas);

    return 0;
}