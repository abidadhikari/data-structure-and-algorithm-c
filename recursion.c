#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int fact(int x)
{
    if (x == 0)
        return 1;
    else
        return (fact(x - 1) * x);
}
int fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibo(n - 1) + fibo(n - 2));
}
void TOH(char S, char D, char A, int num)
{
    if (num == 1)
        printf("\nMove disc %d from rod %c to rod %c", num, S, D);
    else
    {
        TOH(S, A, D, num - 1);
        printf("\nMove disc %d from rod %c to rod %c", num, S, D);
        TOH(A, D, S, num - 1);
    }
}

void menu()
{
    printf("\n--------------------------\n");
    printf("1. Greatest Common Divisor\n");
    printf("2. Factorial\n");
    printf("3. Fibonacci Sequence\n");
    printf("4. Tower of Hanoi\n");
    printf("5. Exit\n");
    printf("\n--------------------------\n");
}

int main()
{
    int exit = 1, a, b, arr[20];
    while (exit != 5)
    {
        menu();
        printf("Enter menu option : ");
        scanf("%d", &exit);
        switch (exit)
        {
        case 1:
            printf("Enter two numbers : ");
            scanf("%d%d", &a, &b);
            printf("The gcd of two number is %d", gcd(a, b));
            break;
        case 2:
            printf("Enter a number : ");
            scanf("%d", &a);
            printf("The factorial of number is %d ", fact(a));
            break;
        case 3:
            printf("Enter the nth number : ");
            scanf("%d", &a);
            for (int i = 0; i < a; i++)
            {
                arr[i] = fibo(i);
            }
            printf("The fibonacci sequence is : ");
            for (int i = 0; i < a; i++)
            {
                printf("%d\t", arr[i]);
            }
            break;
        case 4:
            printf("Enter number of discs: ");
            scanf("%d", &a);
            TOH('S', 'D', 'A', a);
            break;
        case 5:
        default:
            printf("\n--------MENU EXIT--------\n");
            exit = 5;
            break;
        }
    }
    return 0;
}