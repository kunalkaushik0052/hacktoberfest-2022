#include <stdio.h>
int isArmstrong(int num);
void printArmstrong(int n1, int n2);

int main()
{
    int n1, n2;
    printf("Enter lower limit: ");
    scanf("%d", &n1);
    printf("Enter upper limit: ");
    scanf("%d", &n2);

    printf("All armstrong numbers between %d to %d are: \n", n1, n2);
    printArmstrong(n1, n2);

    return 0;
}
int isArmstrong(int num)
{
    int temp, lastDigit, sum;

    temp = num;
    sum = 0;
    while(temp != 0)
    {
        lastDigit = temp % 10;
        sum += lastDigit * lastDigit * lastDigit;
        temp /= 10;
    }
    if(num == sum)
        return 1;
    else
        return 0;
}
void printArmstrong(int n1, int n2)
{
    while(n1 <= n2)
    {
        if(isArmstrong(n1))
        {
            printf("%d, ", n1);
        }
        n1++;
    }
}
