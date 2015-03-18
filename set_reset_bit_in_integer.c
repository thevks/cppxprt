#include <stdio.h>

int main(void)
{
    int n, pos, flag;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter bit pos from right: ");
    scanf("%d", &pos);
    printf("Flip/Set/Reset: ");
    scanf("%d", &flag); //shd be 2/1/0

    if (flag == 2) //Flipping
        n = n ^ (1 << pos);
    else if (flag == 1) //Setting
        n = n | (1 << pos);
    else if (flag == 0) //Resetting
        n = n & (~(1 << pos));

    printf("n = %d\n", n);

    return 0;
}
