#include <stdio.h>

#define MAX(a,b) (((a)>(b)?(a):(b)))
#define Max_DEGREE 101

typedef struct
{
	int degree;
	float coef[Max_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;
	int Apos = 0; int Bpos = 0; int Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b)
		{
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b)
		{
			if (A.coef[Apos] == 0 || B.coef[Bpos] == 0)
			{
				if (A.coef[Apos] > B.coef[Bpos])
				{
					C.coef[Cpos++] = A.coef[Apos++];
					B.coef[Bpos++];
					degree_a--; degree_b--;
				}
				else
				{
					C.coef[Cpos++] = B.coef[Bpos++];
					A.coef[Apos++];
					degree_a--; degree_b--;
				}
			}
			C.coef[Cpos++] = A.coef[Apos++] * B.coef[Bpos++];
		}
		else
		{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

int main(void)
{
	polynomial a_1 = { 3,{4,0,3,2,1} };
	polynomial b_1 = { 2,{3,2,8} };
	polynomial c_1;

	polynomial a_2 = { 6,{7,0,0,5,9,0,1} };
	polynomial b_2 = { 3,{5,2,1,10} };
	polynomial c_2;


	print_poly(a_1);
	print_poly(b_1);
	c_1 = poly_add1(a_1, b_1);
	printf("-----------------------------------------------------\n");
	print_poly(c_1);
	printf("\n");


	print_poly(a_2);
	print_poly(b_2);
	c_2 = poly_add1(a_2, b_2);
	printf("-----------------------------------------------------\n");
	print_poly(c_2);

	return 0;
}