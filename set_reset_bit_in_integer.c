#include <stdio.h>
int main(void)
{
    int n, pos, flag;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter bit pos from right: ");
    scanf("%d", &pos);
    printf("Set/Reset: ");
    scanf("%d", &flag); //shd be 1/0

    if (flag)
        n = n | (1 << pos);
    else
        n = n & (~(1 << pos));

    printf("n = %d\n", n);

    return 0;
}

