#include<iostream>
#include<vector>

using namespace std;

int merged_count_inversions(vector<int>& array, int start, int middle, int end)
{
    vector<int> sorted_array;

    int i = start;
    int j = middle;
    int inversions = 0;

    //Collect the itmes in two array in sorted order
    while (i < middle && j < end)
    {
        if (array[i] <= array[j])
            sorted_array.push_back(array[i++]);
        else {
            inversions += (middle - i);
            sorted_array.push_back(array[j++]);    
        }    
    }

    //Copy of remaining items of left array
    while (i < middle)
        sorted_array.push_back(array[i++]);

    //Copy of remaining items of right array
    while (j < end)
        sorted_array.push_back(array[j++]);

    //Adjust the original array
    for (int i = 0; i < sorted_array.size(); i++)
    {
        int num = sorted_array[i];
        array[start + i] = num;        
    }

    return inversions;
}

int count_subarray_inversions(vector<int>& array, int start, int end)
{
    if (end - start <= 1)
        return 0;
    
    int middle = (start + end) / 2;

    int left_inversions = count_subarray_inversions(array, start, middle);
    int right_inversions = count_subarray_inversions(array, middle, end);
    
    int merged_inversions = merged_count_inversions(array, start, middle, end);
    
    return left_inversions + right_inversions + merged_inversions;
}

int main(void)
{
    vector<int> array{2,3,3,1,9,5,6};
    cout << count_subarray_inversions(array, 0, array.size()) << endl;
}