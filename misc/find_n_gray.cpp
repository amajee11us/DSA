#include <cmath>
#include <string>
/*
Problem:
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2^n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

Example:
Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n< 0 || n > 16)
        {
            throw "n cannot be > 16 or < 0";
        }
        
        vector<string> gray_n = computeBinaryGray(n);
        vector<int> gray_n_in_int;
        
        for(int i = 0; i < gray_n.size(); i++)
        {
            int val = convertToInteger(gray_n[i]);
            gray_n_in_int.push_back(val);
        }
        
        return gray_n_in_int;
    }
    
    vector<string> computeBinaryGray(int n)
    {
        if(n > 16)
        {
            throw "n cannot be > 16";
        }
        else if(n <= 0)
        {
            return {"0"};
        }
        else if(n == 1)
        {
            return {"0", "1"};
        }
        else
        {
            vector<string> gray_n;
            vector<string> gray_n_minus_one = computeBinaryGray(n - 1);
            
            for(int i = 0; i < gray_n_minus_one.size(); i++)
            {
                gray_n.push_back("0" + gray_n_minus_one[i]);
            }
            for(int i = gray_n_minus_one.size() - 1; i >= 0; i--)
            {
                gray_n.push_back("1" + gray_n_minus_one[i]);
            }
            
            return gray_n;
        }        
    }
    
    int convertToInteger(string s)
    {
        int power_to_raise = s.length() - 1;
        int sum = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1')
            {
                sum = sum + int(pow(2, power_to_raise)); 
            }
            power_to_raise--;                       
        }
        
        return sum;
    }
};
