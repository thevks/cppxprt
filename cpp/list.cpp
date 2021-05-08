#include <iostream>
#include <list>
using namespace std;

void print_list_forward(list<int> lst)
{
    //Iterating Forward using itertor
    list<int>:: iterator p;
    
    p = lst.begin();

    while (p != lst.end())
    {
        cout << *p << "->";
        p++;
    }
    cout << endl;
}

void print_list_backward(list<int> lst)
{
    //Iterating Forward using itertor
    list<int>:: iterator p;
    p = lst.end();
    while (p != lst.begin())
    {
        cout << *p << endl;
        p--;
    }
}

int main(void)
{
    list<int> lst1, lst2;
    for (int i=0; i<3; i++)
    {
        lst1.push_back(i);
        lst2.push_back(i+10);
    }
        
    cout << "size of list 1 : " << lst1.size() << endl;
    cout << "size of list 2 : " << lst2.size() << endl;

    print_list_forward(lst1);

    print_list_forward(lst2);

    //Merge two lists
    lst1.merge(lst2);
    
    cout << endl;
    cout << "Merged List: " << endl;
    print_list_forward(lst1);

    print_list_forward(lst2);

    //Reverse the list
    //lst.reverse();

    //for (int i=0; i<2; i++)
    //    lst.push_front(i+2);

    
    //Sort the list
    //lst.sort();

 
}