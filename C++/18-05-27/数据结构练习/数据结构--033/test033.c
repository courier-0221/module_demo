#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
题目：
	数值的整数次方.实现函数double Power(double base, int exponent),求base 的exponent次方,不需要考虑溢出
需要注意的是浮点数和0值的比较
*/

int double_equal(double a, double b)
{
	double diff = a - b;
	if (diff > -0.000001 && diff < 0.000001){		//等于0
		return 1;
	}
	else{
		return 0;
	}
}

double Power(double base, int exp)
{
	//0的0次方没有意义,0的负数次方没有意义
	if (double_equal(base, 0.0) && (exp <= 0)){
		return 0.0;
	}

	int abs_exp = (exp > 0) ? exp : -exp;
	double result = 1.0;

	for (int i = 0; i < abs_exp; i++){
		result *= base;
	}
	return (exp > 0) ? result : (1.0 / result);
}


int main(void)
{
	double base1 = 0;
	double base2 = -10;
	double base3 = 10;
	int exponent1 = 0;
	int exponent2 = 3;
	int exponent3 = -2;
	printf("%f^%d-->%f\n", base1, exponent1, Power(base1, exponent1));
	printf("%f^%d-->%f\n", base1, exponent2, Power(base1, exponent2));
	printf("%f^%d-->%f\n", base1, exponent3, Power(base1, exponent3));
	printf("%f^%d-->%f\n", base2, exponent1, Power(base2, exponent1));
	printf("%f^%d-->%f\n", base2, exponent2, Power(base2, exponent2));
	printf("%f^%d-->%f\n", base2, exponent3, Power(base2, exponent3));
	printf("%f^%d-->%f\n", base3, exponent1, Power(base3, exponent1));
	printf("%f^%d-->%f\n", base3, exponent2, Power(base3, exponent2));
	printf("%f^%d-->%f\n", base3, exponent3, Power(base3, exponent3));

	system("pause");
	return 0;
}