#include <stdio.h>

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

    printf("Distancia valida recebida: %.2f km\n", distancia);
    printf("Peso valido recebido: %.2f kg\n", peso);

    return 0;
}