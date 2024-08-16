#include <stdio.h>
#include <math.h>
#include <windows.h>

#define EPS 0.00000001

/* Алгоритм решения*/
void solution(double *a, double *b, double *c) {
    if (fabs(*a) < EPS) {
        if (fabs(*b) < EPS) {
            if (fabs(*c) < EPS) { printf("Бесконечно много решений\n"); }
            else { printf("Решений нет\n"); }
        }
        else { printf("1 решение: %.3f\n", (fabs(*c) < EPS) ? 0 : - *c / *b);}
    }
    else {
        double D = *b * *b - 4 * *a * *c;

        if (D < EPS && D > -EPS) {
            printf("1 решение: %.3f\n", (fabs(*b) < EPS) ? 0 : - *b / (2 * *a));
        }
        else if (D < -EPS) { printf("Нет действительных корней\n"); } /* Нужно ли искать комплексные корни? */
        else {
            printf("2 решения: %.3f и %.3f\n", (- *b - sqrt(D)) / (2 * *a), (- *b + sqrt(D)) / (2 * *a));
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); /* Без этого Clion не выводит кириллицу :( */
    double a, b, c;
    printf("Введите коэффицент при a:"), scanf("%lf", &a);
    printf("Введите коэффицент при b:"), scanf("%lf", &b);
    printf("Введите коэффицент при c:"), scanf("%lf", &c);
    solution(&a, &b, &c);
    return 0;
}