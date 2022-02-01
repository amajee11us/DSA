#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    string s = "ANAYAAA"; 
    
   // heap implementation
   unordered_map<char, int> umap;
   
   string reduced = "";
   for(int i = 0; i < s.length(); i++){
       if(umap.find(s[i]) == umap.end()){
           reduced = reduced + s[i];
       }
       umap[s[i]]++;
   }

   cout << reduced << endl;
   
   // vector implementation
    vector<char> stringVect(s.begin(), s.end());

    for(int i = 0; i < stringVect.size(); i++){
        auto it = find(stringVect.begin() + i + 1, 
                            stringVect.end(), 
                            stringVect[i]);;
        while(it != stringVect.end()){
            stringVect.erase(it);
            it=find(stringVect.begin() + i + 1, 
                            stringVect.end(), 
                            stringVect[i]);
        }
    }

    for(int i = 0; i < stringVect.size(); i++){
        cout << stringVect[i];
    }
    cout << endl;
    return 0;
}