#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_placements(vector<int> placements, int n)
{
    cout << "-----------" << endl;
    for (int i=0; i<n; i++)
        cout << "row " << i << ", col " << placements[i] << endl;
    cout << "-----------" << endl;
}


bool is_non_attacking_placement(int row, int col, vector<int> placements)
{
    for (int pre_row = 0; pre_row < row; pre_row++)
    {
        int col_to_check = placements[pre_row];
        bool same_col = col_to_check == col;
        bool is_diagonal = row - pre_row == abs(col_to_check - col);

        if (same_col || is_diagonal)
            return false;
    }
    return true;
}

bool get_queen_placements(int row, vector<int>& placements, int n)
{
    if (row == n) {
        print_placements(placements, n);
        return true;
    }
    
    bool res = false;

    for (int col=0; col< n; col++)
    {
        if (is_non_attacking_placement(row, col, placements))
        {
            placements[row] = col;
            res = get_queen_placements(row + 1, placements, n) || res;
            placements[row] = 0;
        }

    } 

    return res;   
}


int main(void)
{
    /* Each index of this array represents 
     * row and corresponding value corresponds 
     * to the column - where a queen can be placed
     */
    int n;
    cout << "Enter number of queens: ";
    cin>>n;
    vector<int> placements(n, 0);
    cout << "Number of non attacking queens are: " << endl;

    get_queen_placements(0, placements, n);
  
    return 0;
}
