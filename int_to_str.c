#include <stdio.h>

void func(int a)
{
    int b;
    if (a){
        b = a%10;
        a = a/10;
        printf("b = %d, a = %d\n", b, a); 
        func(a);
        printf("b = %d\n", b);
    }
}

int main(void)
{
    int x = 12345;
    func(x);

    return 0;
}
