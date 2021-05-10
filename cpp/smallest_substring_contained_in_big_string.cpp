#include<iostream>
#include<unordered_map>
using namespace std;

//Count number of hash keys
int hash_map_keys(unordered_map<char, int>& hash_map)
{
    unordered_map<char, int>:: iterator q;
    int count = 0;
    q = hash_map.begin();
    while (q != hash_map.end())
    {
        q++;    
        count++;
    }

    return count;
}

int main(void)
{
    char big_string[20] = "abcd$ef$axb$c$";
    char small_string[10] = "$$abf";
        
    unordered_map<char, int> pattern_hash;
    unordered_map<char, int> matching_hash;
    int max_length = 0;
    int matching_count = 0;
    
    //Create pattern hash table
    char *p = small_string;
    while(*p != '\0')
    {
        pattern_hash[*p]++;
        p++;
    }
    
    int num_pattern_keys = hash_map_keys(pattern_hash);
        
    char c;
    int i = 0;
    int j = 0;
    int current_length = 0;

    //Iterate the big string, until a char is found, which is present in patter hash table
    c = big_string[i];
    while (!pattern_hash[c])
    {
        i++;
        c = big_string[i];
    }

    //Start preparing matching hash table
    matching_hash[c]++;
    matching_count++;
    j = i + 1;

    while (big_string[j] != '\0')
    {
        c = big_string[j];

        if (pattern_hash[c])
        {
            matching_hash[c]++;

            if (matching_hash[c] == pattern_hash[c])
                matching_count++;

            if (matching_count == num_pattern_keys) 
            { 
                current_length = j - i + 1;
                if (max_length == 0)
                    max_length = current_length;
                if (current_length < max_length)
                    max_length = current_length;
                
                c = big_string[i];
                matching_hash[c]--;
            
                //Decrease the macthing count
                matching_count--;
            
                //Skip over all the chars - which are not in pattern hash table
                i++;
                c = big_string[i];
                while (!pattern_hash[c]) {
                    i++;
                    c = big_string[i];
                }

            }

        }

        j++;
    }

    cout << "Smallest Substring length : " << max_length << endl;
}
