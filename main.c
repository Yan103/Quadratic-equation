#include <stdio.h>
#include <math.h>
#include <windows.h>

const double EPS = 1e-8;
#define IS_ZERO(x) (fabs(x) < EPS)
#define LESS_ZERO(x) (x < -EPS)

/* Roots status */
enum roots_status {
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
    NOTHING
};

/* Information about equation */
struct equation {
    double a, b, c;     /* Coefficients */
    double D;           /* Discriminant */
    double x1, x2;      /* Roots x1 < x2 (if there is one root, it is in x1) */
    int solve_info;     /* Information about roots */
};

/* Input equation parameters */
static void input_equation(struct equation *e_ptr) {
    double a = 0, b = 0, c = 0;
    printf("Введите через пробел коэффициенты при a, b и c:");
    scanf("%lf %lf %lf", &a, &b, &c);
    e_ptr->a = a;
    e_ptr->b = b;
    e_ptr->c = c;
    e_ptr->D = b * b - 4 * a * c;
    e_ptr->x1 = e_ptr->x2 = e_ptr->solve_info = NOTHING;
}

/* Any number is a solution of equation */
static void has_inf_roots(struct equation *q_equation) {
    q_equation->solve_info = INF_ROOTS;
}

/* Equation has no real roots */
static void doesnt_have_real_roots(struct equation *q_equation) {
    q_equation->solve_info = NO_ROOTS;
}

/* Equation becomes linear */
static void solve_linear_equation(struct equation *q_equation) {
    q_equation->solve_info = ONE_ROOT;
    q_equation->x1 = (IS_ZERO(q_equation->c)) ? 0 : -q_equation->c / q_equation->b;
}

/* Solving quadratic equation */
static void solve_quadratic_equation(struct equation *q_equation) {
    switch (IS_ZERO(q_equation->D)) {
        case 1:
            q_equation->solve_info = ONE_ROOT;
            q_equation->x1 = (IS_ZERO(q_equation->b)) ? 0 : -q_equation->b / (2 * q_equation->a);
            break;
        case 0:
            q_equation->solve_info = TWO_ROOTS;
            const double sqrt_D = sqrt(q_equation->D);
            q_equation->x1 = (-q_equation->b - sqrt_D) / (2 * q_equation->a);
            q_equation->x2 = (-q_equation->b + sqrt_D) / (2 * q_equation->a);
            break;
        default:
            printf("Что-то пошло не так...\n");
            break;
    }
}

/* Solving the equation (get information about the number of roots and the roots themselves) */
static void solve_equation(struct equation *q_equation) {
    if (IS_ZERO(q_equation->a)) {
        if (IS_ZERO(q_equation->b)) {
            if (IS_ZERO(q_equation->c)) {
                has_inf_roots(q_equation);
            } else {
                doesnt_have_real_roots(q_equation);
            }
        } else {
            solve_linear_equation(q_equation);
        }
    } else {
        if (LESS_ZERO(q_equation->D)) {
            doesnt_have_real_roots(q_equation);
        } else {
            solve_quadratic_equation(q_equation);
        }
    }
}

/* Result output */
static void show_result(const struct equation *q_equation) {
    switch (q_equation->solve_info) {
        case NO_ROOTS:
            printf("Уравнение не имеет действительных корней\n");
            break;
        case ONE_ROOT:
            printf("Уравнение имеет 1 корень: %g\n", q_equation->x1);
            break;
        case TWO_ROOTS:
            printf("Уравнение имеет 2 корня: %g и %g\n", q_equation->x1, q_equation->x2);
            break;
        case INF_ROOTS:
            printf("Уравнение имеет бесконечное количество решений\n");
            break;
        default:
            printf("Что-то пошло не так...\n");
            break;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); /* Без этого Clion не выводит кириллицу:(*/
    struct equation quadratic_equation = {0, 0, 0, 0, 0, 0, '0'};
    input_equation(&quadratic_equation);
    solve_equation(&quadratic_equation);
    show_result(&quadratic_equation);

    return 0;
}