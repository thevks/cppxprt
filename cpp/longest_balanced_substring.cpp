#include <iostream>
using namespace std;

int str_length(char *str)
{
    int count = 0;
    char *p = str;
    while (*p != '\0')
    {
        count++;
        p++;
    }

    return count;
}

int left_to_right_length(char *str)
{
    int left_parentheses_count = 0;
    int right_parentheses_count = 0;
    int current_length = 0;
    int max_length = 0;

    char *p = str;
    while (*p != '\0')
    {
        if (*p == '(') 
            left_parentheses_count++;
        if (*p == ')') 
            right_parentheses_count++;

        if (left_parentheses_count == right_parentheses_count)
            current_length = 2 * left_parentheses_count;
            
        if (current_length > max_length) 
            max_length = current_length;

        if (right_parentheses_count > left_parentheses_count) {
            left_parentheses_count = 0;
            right_parentheses_count = 0;
            current_length = 0;
        }
        p++;        
    }

    return max_length;
}

int right_to_left_length(char *str)
{
    int left_parentheses_count = 0;
    int right_parentheses_count = 0;
    int current_length = 0;
    int max_length = 0;
    
    char *p = str;
    int length = str_length(str);
    
    p = p + (length -1);
    while (length > 0)
    {
        if (*p == '(') 
            left_parentheses_count++;
        if (*p == ')') 
            right_parentheses_count++;

        if (left_parentheses_count == right_parentheses_count)
            current_length = 2 * left_parentheses_count;

        if (current_length > max_length) 
            max_length = current_length;

        if (left_parentheses_count > right_parentheses_count) {
            left_parentheses_count = 0;
            right_parentheses_count = 0;
            current_length = 0;
        }

        length--;
        p--;        
    }
    return max_length;
}

int main(int argc, char *argv[])
{
    char str1[10] = "(()))((";
    char str2[10] = "(()))((";
    char str3[10] = "(()))(()";
    int max_length_1;
    int max_length_2;
    
    cout << "Proce0ssing str1 :" << endl;
    max_length_1 = left_to_right_length(str1);
    max_length_2 = left_to_right_length(str1);     
    cout << "Max length 1 : " << max_length_1 << endl;
    cout << "Max length 2 : " << max_length_2 << endl;
    cout << "Final length : " << max(max_length_1, max_length_2);

    cout << endl << "Processing str2 :" << endl;
    max_length_1 = left_to_right_length(str2);
    max_length_2 = left_to_right_length(str2);     
    cout << "Max length 1 : " << max_length_1 << endl;
    cout << "Max length 2 : " << max_length_2 << endl;
    cout << "Final length : " << max(max_length_1, max_length_2);

    cout << endl << "Processing str3 :" << endl;
    cout << "Max length for string 3 : " << max(left_to_right_length(str3), right_to_left_length(str3)) << endl;
}