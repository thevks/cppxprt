#include<iostream>
#include<vector>
using namespace std;

vector<int> merge_sorted_array(vector<int> left_array, vector<int> right_array)
{
    vector<int> sorted_array(left_array.size()+right_array.size(), 0);
    
    int i=0, j=0, k= 0;
    while (i<left_array.size() && j<right_array.size())
    {
        if (left_array[i] <= right_array[j])    
            sorted_array[k++] = left_array[i++];
        else
            sorted_array[k++] = right_array[j++];
    }

    while (i<left_array.size())
        sorted_array[k++] = left_array[i++];
    
    while (j<right_array.size())
        sorted_array[k++] = right_array[j++];

    return sorted_array;
}

vector<int> merge_sort(vector<int> array)
{
    if (array.size() <= 1)
        return array;

    int mid_ix = array.size()/2;
    
    vector<int> left_array(array.begin(), array.begin() + mid_ix);
    vector<int> right_array(array.begin() + mid_ix, array.end());

    return merge_sorted_array(merge_sort(left_array), merge_sort(right_array));
}

int main(void)
{
    vector <int> array{2,4,6,1,9,8,7,5};
    
    array = merge_sort(array);

    for (int i: array)
        cout<< i << " ";
    
    return 0;
}
