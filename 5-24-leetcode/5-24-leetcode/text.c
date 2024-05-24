#define _CRT_SECURE_NO_WANINGS 1
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

// BC166 小乐乐走台阶
//int StepUp(int n)
//{
//    if (n<=2)
//        return n;
//
//    return StepUp(n - 1) + StepUp(n - 2);
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    printf("%d", StepUp(n));
//    return 0;
//}


// BC167 函数实现计算一个数的阶乘

//long long factorial(int n)
//{
//    if (n == 1)
//        return 1;
//
//    return factorial(n - 1) * n;
//}
//
//
//int main() {
//
//    int n;
//    scanf("%d", &n);
//    printf("%lld", factorial(n));
//    return 0;
//}

//BC168 牛牛的西格玛

//int accumulation(int n)
//{
//	if (n == 1)
//		return 1;
//
//	return accumulation(n - 1) + n;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	printf("%d", accumulation(n));
//	return 0;
//}

// BC169 牛牛的Ackmann

//int Ackmann(int m, int n)
//{
//	if (m == 0)
//		return n + 1;
//
//	if (n == 0 && m > 0)
//		return Ackmann(m - 1, 1);
//
//	if (n > 0 && m > 0)
//		return Ackmann(m - 1, Ackmann(m, n - 1));
//
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, & m);
//	printf("%d", Ackmann(m,n));
//	return 0;
//}

// BC170 牛牛的digit

//int digit(int x, int  i)
//{
//	if (i == 1)
//		return x % 10;
//	else
//		return digit(x / 10, i - 1) * 10 + x % 10;
//}
//
//int main()
//{
//	int x = 0;
//	int i = 0;
//	scanf("%d%d", &x, &i);
//	printf("%d", digit(x, i));
//	return 0;
//}

// BC171 牛牛的Hermite多项式

//int Hermite(int n, int x)
//{
//	if (n == 0)
//		return 1;
//	if (n == 1)
//		return 2 * n;
//	
//	return 2 * x * Hermite(n - 1, x) - 2 * (n - 1) * Hermite(n - 2, x);
//}
//
//int main()
//{
//	int n = 0;
//	int x = 0;
//
//	scanf("%d%d",&n,&x);
//	printf("%d", Hermite(n,x));
//
//
//	return 0;
//}

// BC172 牛牛的排列数

//int permutationsNum(int n, int m)
//{
//	if (m == 1)
//		return n;
//
//	return n * permutationsNum(n - 1, m - 1);
//}
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	printf("%d", permutationsNum(n,m));
//
//	return 0;
//}


// BC173 牛牛逆序输出


//void Reverse(int n) {
//    if (n > 0 && n <= 9)
//        printf("%d", n);
//    else {
//        printf("%d", n % 10);
//        Reverse(n / 10);
//    }
//}
//
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    Reverse(n);
//    return 0;
//}

