#include <stdio.h>
int main(void)
{
    char str[]="I...am....a....very...good....boy";
    char *s=str;
    char *p, *q;
    int count;

    while(*s)
    {
        if (*s == '.'){
            p = s;
            count = 0;
            do {
                count++;
                p++;
            } while(*p == '.');
            printf("Count = %d\n", count);

            p = s;
            q = p + count;
               
            do {
                *p = *q; 
                p++;
                q++;
            } while(*q != '\0'); 

            *p = '\0';
        }
        s++;
    }

    printf("\n");
    printf("s = %s\n", str);
    return 0;
}
