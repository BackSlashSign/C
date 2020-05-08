#define MAX_DEGREE 101
#include <stdio.h>

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}Polynomial;

void print_poly(Polynomial p, char str[]) {
	int i;
	printf("\t%s", str);

	for (i = 0; i < p.degree; i++) {
		printf("%5.1f x^%d + ", p.coef[i], p.degree - i);
	}
	printf( "%4.1f\n", p.coef[p.degree] );
}

Polynomial read_only() {
	int i;
	Polynomial p;

	printf("다항식의 최고 차수를 입력 하시오 : ");
	scanf_s("%d", &p.degree);
	printf("각 항의 계수를 입력하시오 (총 %d개) : ", p.degree + 1);
	for (i = 0; i <= p.degree; i++) {
		scanf_s("%f", p.coef + i);
	}
	return p;
}

Polynomial add_poly(Polynomial a, Polynomial b) {
	int i;
	Polynomial p;

	if (a.degree > b.degree) {
		p = a;
		for (i = 0; i <= b.degree; i++) {
			p.coef[i + (p.degree - b.degree)] += b.coef[i];
		}
/*
		for (i = 0; i <= b.degree; i++) {
			p.coef[i] += b.coef[i];
		}*/
	}
	else {
		p = b;
		for (i = 0; i <= a.degree; i++) {
			p.coef[i + (p.degree - a.degree)] += a.coef[i];
		}/*
		for (i = 0; i <= b.degree; i++) {
			p.coef[i] += a.coef[i];
		}*/
	}
	return p;
}
int main() {
	Polynomial a, b;
	Polynomial c;
	a = read_only();
	b = read_only();
	c = add_poly(a, b);
	print_poly(a, " A = ");
	print_poly(b, " B = ");
	print_poly(c, " A + B = ");
	return 0;
}