#include <stdio.h>
#include <math.h>
#include <windows.h>

const double EPS = 1e-8;

/* Информация об уравнении */
struct equation {
    const double a, b, c; /* Коэффициенты */
    const double D;       /* Дискриминант */
    double x1, x2;  /* Корни х1 < x2 (если корень один - он записан в х1) */
    char solve_cnt; /* Количество решений: '0', '1', '2' - очевидно, 'A' - бесконечно много (any) */
};

/* Инициализация уравнения */
struct equation make_equation(const double *a, const double *b, const double *c) {
    const struct equation q_equation = {*a, *b, *c, *b * *b - 4 * *a * *c, 0, 0, '3'}; /* 0 и '3' по умолчанию, чтобы отлавливать ошибки */
    return q_equation;
}

/* Решение уравнения (получаем информацию о количестве корней и сами корни) */
static void solve_equation(struct equation *q_equation) {
    if (fabs(q_equation->a) < EPS) {
        if (fabs(q_equation->b) < EPS) {
            if (fabs(q_equation->c) < EPS) {
                q_equation->solve_cnt = 'A';
            } else {
                q_equation->solve_cnt = '0';
            }
        } else {
            q_equation->solve_cnt = '1';
            q_equation->x1 = (fabs(q_equation->c) < EPS) ? 0 : - q_equation->c / q_equation->b;
        }
    } else {
        if (q_equation->D < EPS && q_equation->D > -EPS) {
            q_equation->solve_cnt = '1';
            q_equation->x1 = (fabs(q_equation->b) < EPS) ? 0 : - q_equation->b / (2 * q_equation->a);
        } else if (q_equation->D < -EPS) {
            q_equation->solve_cnt = '0';
        } else {
            q_equation->solve_cnt = '2';
            q_equation->x1 = (- q_equation->b - sqrt(q_equation->D)) / (2 * q_equation->a);
            q_equation->x2 = (- q_equation->b + sqrt(q_equation->D)) / (2 * q_equation->a);
        }
    }
}

/* Вывод результата */
static void show_result(const struct equation *q_equation) {
    if (q_equation->solve_cnt == '0') {
        printf("Уравнение не имеет действительных корней\n");
    } else if (q_equation->solve_cnt == '1') {
        printf("Уравнение имеет 1 корень: %.3f\n", q_equation->x1);
    } else if (q_equation->solve_cnt == '2') {
        printf("Уравнение имеет 2 корня: %.3f и %.3f\n", q_equation->x1, q_equation->x2);
    } else {
        printf("Уравнение имеет бесконечное количество решений\n");
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); /* Без этого Clion не выводит кириллицу:(*/
    double a = 0, b = 0, c = 0;
    printf("Введите через пробел коэффициенты при a, b и c:");
    scanf("%lf %lf %lf", &a, &b, &c);
    struct equation quadratic_equation = make_equation(&a, &b, &c);
    solve_equation(&quadratic_equation);
    show_result(&quadratic_equation);
    return 0;
}