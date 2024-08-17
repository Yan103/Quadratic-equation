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
static void solve_equation(struct equation *equation) {
    if (fabs(equation->a) < EPS) {
        if (fabs(equation->b) < EPS) {
            if (fabs(equation->c) < EPS) {
                equation->solve_cnt = 'A';
            } else {
                equation->solve_cnt = '0';
            }
        } else {
            equation->solve_cnt = '1';
            equation->x1 = (fabs(equation->c) < EPS) ? 0 : - equation->c / equation->b;
        }
    } else {
        if (equation->D < EPS && equation->D > -EPS) {
            equation->solve_cnt = '1';
            equation->x1 = (fabs(equation->b) < EPS) ? 0 : - equation->b / (2 * equation->a);
        } else if (equation->D < -EPS) {
            equation->solve_cnt = '0';
        } else {
            equation->solve_cnt = '2';
            equation->x1 = (- equation->b - sqrt(equation->D)) / (2 * equation->a);
            equation->x2 = (- equation->b + sqrt(equation->D)) / (2 * equation->a);
        }
    }
}

/* Вывод результата */
static void show_result(const struct equation *equation) {
    if (equation->solve_cnt == '0') {
        printf("Уравнение не имеет действительных корней\n");
    } else if (equation->solve_cnt == '1') {
        printf("Уравнение имеет 1 корень: %.3f\n", equation->x1);
    } else if (equation->solve_cnt == '2') {
        printf("Уравнение имеет 2 корня: %.3f и %.3f\n", equation->x1, equation->x2);
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
    struct equation *pp = &quadratic_equation;
    solve_equation(pp);
    show_result(pp);
    return 0;
}