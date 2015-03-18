#include <stdio.h>

int main(int argc, char **argv)
{
    int n;
    int count = 0;

    printf("Enter the number: ");
    scanf("%d", &n);

    while(n) {
        count++;
        n = n & (n-1);
    }
    printf("No. of bits are %d\n", count);

    return 0;
}
