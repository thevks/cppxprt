#include <iostream>

int isSubStr(char *s1, const char *s2)
{
    int len = strlen(s2);
    int l, count;
    int flag = false;
    char *se = s1 + strlen(s1);

    printf("s1 = %s, %c\n", s1, *se);

    while ((s1 + len) <= se) 
    {  
        l = len;
        count = 0;
        while (l--)
        {
            if (*(s2+l) == *(s1+l)) 
                count++;
            else 
                break;
        }
        if (count == len) {
            flag = true;
            break;
        }
        s1++;
    }
    printf("Count = %d\n", count);

    return flag;
}

int main(void)
{
    char str[] = "ThisIsVivekSharma";
    char patt1[] = "Vivek";
    char patt2[] = "Hello";
    char patt3[] = "Sharma";
    char patt4[] = "IsVivek";

    //printf("Return value: %d\n", isSubStr(str, patt2));
    //printf("Return value: %d\n", isSubStr(str, patt1));
    printf("Return value: %d\n", isSubStr(str, patt3));
    //printf("Return value: %d\n", isSubStr(str, patt4));

    return 0;
}
