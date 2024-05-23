#define _CRT_SECURE_NO_WANINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


// BC65 ������Ʒ���۽�����
//int main() {
//    float price = 0;
//    scanf("%f", &price);
//    if (price < 100)
//    {
//        printf("%.1f", price);
//    }
//    else if (price >= 100 && price < 500)
//    {
//        printf("%.1f", price * 0.9);
//    }
//    else if (price >= 500 && price < 2000)
//    {
//        printf("%.1f", price * 0.8);
//    }
//    else if (price >= 2000 && price < 5000)
//    {
//        printf("%.1f", price * 0.7);
//    }
//    else if (price >= 5000)
//    {
//        printf("%.1f", price * 0.6);
//    }
//
//    return 0;
//}


// BC158 [NOIP1999]������

// �ж�������Ƿ��ǻ�����
bool isPalindrome(unsigned long long x, int base)
{
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    // ��ת�������
    unsigned long long reversed = 0;
    // ��תǰ������
    unsigned long long original = x;

    while (original)
    {
        int digit = original % 10;
        reversed = reversed * 10 + digit;
        original /= 10;
    }

    return reversed == x;
}

// ��Ҫ��ת������
unsigned long long reverseNumber(unsigned long long x, int base)
{
    // ��ת�������
    unsigned long long reversed = 0;
    // ��תǰ������
    unsigned long long original = x;

    while (original)
    {
        int digit = original % 10;
        reversed = reversed * 10 + digit;
        original /= 10;
    }

    return reversed;
}

// ���ַ���ת��Ϊʮ������
unsigned long long stringToNumber(const char* str, int base)
{
    char* endptr;
    long num = strtol(str, &endptr, 10); // 10��ʾʮ����  
    if ((errno == ERANGE && (num == LONG_MAX || num == LONG_MIN))
        || (errno != 0 && num == 0)) {
        perror("strtol");
        return 1;
    }

    // ����Ƿ������ַ�������ת����  
    if (*endptr != '\0') {
        printf("Extra characters after number: %s\n", endptr);
        return 1;
    }

    return num;
}

//
void printNumber(unsigned long long num, int base);

int main() {
    int n = 0; // ������
    char m[101];
    int STEP = 0;
    unsigned long long num = 0; // ��������������

    scanf("%d %s",&n,m);

    num = stringToNumber(m,n);

    if (isPalindrome(num, n))
    {
        printf("0");
        return 0;
    }

    while (STEP < 30)
    {
        unsigned long long reversed = reverseNumber(num,n);
        if (isPalindrome(num, n))
        {
            printf("0");
            return 0;
        }
        STEP++;

    }

    // ���30������δ�õ��������������"Impossible!"  
    printf("Impossible!\n");
    return 0;
}