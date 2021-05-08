#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // Vector with 5 integers
    // Default value of integers will be 0.
    vector < int > vecOfInts(5);
    vector < int > v(3);
    vector<int>::iterator p;

    for (int x: vecOfInts)
        cout << x << endl;

    string arr[] = {
        "first",
        "sec",
        "third",
        "fourth"
    };

    cout << sizeof(arr) << endl;
    cout << sizeof(string) << endl;

    // Vector with a string array
    vector < string > vecOfStr(arr, arr + sizeof(arr) / sizeof(string));
    for (string str: vecOfStr)
        cout << str << endl;

    p = vecOfInts.begin();
    int i = 0;
    while (p != vecOfInts.end())
    {
        //cout << *p << endl;       
        *p = i;
        p++;
        i++;
    }

    p = vecOfInts.begin();
    while (p != vecOfInts.end())
    {
        cout << *p << endl;       
         p++;
    }
    
    cout << "Going to print uninitialize array" << endl;
    p = v.begin();
    while (p != v.end())
    {
        cout << *p << endl;       
         p++;
    }

    for (int i= 0; i<v.size(); i++) 
        cout << v[i] << endl;
}