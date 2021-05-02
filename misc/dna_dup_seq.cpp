#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
Question 1
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.

*/
string substring(string s, int start_pos, int end_pos){
    // crop off a substring from s between start and end pos
    string sub = "";
    for(int i = start_pos; i < end_pos; i++){
        sub = sub + s[i];
    }
    assert (sub.length() == (end_pos - start_pos));

    return sub;
}

vector<string> find_duplicate(string s){
    int len = s.length();
    
    vector<string> output;
    int dup_count = 0;

    for(int i = 0; i < len; i++){
        if((i + 10) > len){
            break;
        }
        
        string sub = substring(s, i, i + 10);

        for(int j = i + 1; j < len; j++){
            if((j + 10) > len){
                break;
            }
            string comp_sub =  substring(s, j, j + 10);
            if (comp_sub == sub){
                // search for a duplicate and do not add if already present
                auto search_result = find(output.begin(), output.end(), comp_sub);
                if(search_result == output.end()){
                    output.push_back(sub);
                    dup_count++;
                }
            }
        }
    }
    return output;
}

int main(){
    vector<string> duplicates;
    //string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string s = "AAAAAAAAAAAAA";
    duplicates= find_duplicate(s);

    int num_duplicates = duplicates.size();

    for(int i = 0; i < num_duplicates; i++){
        cout << duplicates[i] << endl;
    }
    return 0;
}