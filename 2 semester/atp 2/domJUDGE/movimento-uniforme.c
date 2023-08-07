
#include <stdio.h>
#include <math.h>
void opcoes(int n);
double dist_mru(double v, double t);
double vel_mru(double s, double t);
double temp_mru(double s, double v);
double vel_mru(double s, double t);
double dist_mruv(double v, double a, double t);
double vel_final_mruv(double v, double a, double t);
double vel_inicial_mruv(double s, double a, double t);
double tempo_total_mruv(double s, double v, double a);
int main()
{
    long int n;
    int o, i;
    scanf("%ld", &n);
    for (i = 0; i < n; i++)
    {
        opcoes(n);
    }   
}
void opcoes(int n)
{
    int o;
    double v, t, s, a;
    scanf("%d", &o);
    switch (o)
    {
    case 1:
        scanf("%lf %lf", &v, &t);
        printf("%.2lf\n", dist_mru(v, t));
        break;
    case 2:
        scanf("%lf %lf", &s, &t);
        printf("%.2lf\n", vel_mru(s, t));
        break;
    case 3:
        scanf("%lf %lf", &s, &v);
        printf("%.2lf\n", temp_mru(s, v));
        break;
    case 4:
        scanf("%lf %lf %lf", &v, &a, &t);
        printf("%.2lf\n", dist_mruv(v, a, t));
        break;
    case 5:
        scanf("%lf %lf %lf", &v, &a, &t);
        printf("%.2lf\n", vel_final_mruv(v, a, t));
        break;
    case 6:
        scanf("%lf %lf %lf", &s, &a, &t);
        printf("%.2lf\n", vel_inicial_mruv(s, a, t));
        break;
    case 7:
        scanf("%lf %lf %lf", &s, &v, &a);
        printf("%.2lf\n", tempo_total_mruv(s, v, a));
    }
}
double dist_mru(double v, double t)
{
    double s;
    s = v * t;
    return s;
}
double vel_mru(double s, double t)
{
    double v;
    v = s / t;
    return v;
}
double temp_mru(double s, double v)
{
    double t;
    t = s / v;
    return t;
}
double dist_mruv(double v, double a, double t)
{
    double s;
    s = (v * t) + (a * t * t) / 2;
    return s;
}

double vel_final_mruv(double v, double a, double t)
{
    double v_final;
    v_final = v + (a * t);
    return v_final;
}
double vel_inicial_mruv(double s, double a, double t)
{
    double vo;
    vo = (s - (a * t * t) / 2) / t;
    return vo;
}
double tempo_total_mruv(double s, double v, double a)
{
    double vf, t;
    vf = sqrt((v * v) + (2 * a * s));
    t = (vf - v) / a;
    return t;
}