#include <stdio.h>

typedef struct {
    double x, y;
} Ponto;

Ponto calculaCentro(Ponto p1, Ponto p2, Ponto p3, Ponto p4) {
    double A1 = 2 * (p2.x - p1.x);
    double B1 = 2 * (p2.y - p1.y);
    double C1 = p1.x * p1.x - p2.x * p2.x + p1.y * p1.y - p2.y * p2.y;

    double A2 = 2 * (p4.x - p3.x);
    double B2 = 2 * (p4.y - p3.y);
    double C2 = p3.x * p3.x - p4.x * p4.x + p3.y * p3.y - p4.y * p4.y;

    double determinante = A1 * B2 - A2 * B1;

    Ponto centro;
    centro.x = (C1 * B2 - C2 * B1) / determinante;
    centro.y = (A1 * C2 - A2 * C1) / determinante;

    return centro;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        Ponto antiga1, antiga2, nova1, nova2;
        scanf("%lf %lf", &antiga1.x, &antiga1.y);
        scanf("%lf %lf", &antiga2.x, &antiga2.y);
        scanf("%lf %lf", &nova1.x, &nova1.y);
        scanf("%lf %lf", &nova2.x, &nova2.y);

        Ponto centro = calculaCentro(antiga1, nova1, antiga2, nova2);
        printf("Caso #%d: %.2f %.2f\n", i, (centro.x)*-1, (centro.y)*-1);
    }

    return 0;
}
