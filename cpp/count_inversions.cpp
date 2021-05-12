#include<iostream>
#include<vector>

using namespace std;

int merged_count_inversions(vector<int>& array, int start, int middle, int end)
{
    vector<int> sorted_array;

    int i = start;
    int j = middle;
    int inversions = 0;

    while (i < middle && j < end)
    {
        if (array[i] <= array[j])
            sorted_array.push_back(array[i++]);
        else {
            inversions += middle - i;
            sorted_array.push_back(array[j++]);    
        }    
    }

    //Copy of left over of left array
    while (i < middle)
        sorted_array.push_back(array[i++]);

    //Copy of left over of right array
    while (j < end)
        sorted_array.push_back(array[j++]);

    i = 0;    
    while (i < sorted_array.size())
    {
        int num = sorted_array[i];
        array[start + i] = num;        
        i++;    
    }

    return inversions;
}

int count_subarray_inversions(vector<int>& array, int start, int end)
{
    if (end - start <= 1)
        return 0;
    
    int middle = start + ((end - start) / 2);

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