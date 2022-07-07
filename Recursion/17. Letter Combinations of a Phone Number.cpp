// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
class Solution {
public:
    // declaring returning vector 
    vector<string>res;
    //letter combination maker function
    void lettercomb(string digits, vector<vector<char>>& digitmap, string temp,int i){
        if(digits[i]==NULL){
            res.push_back(temp);
            return;
        }
        for(int j=0; j<digitmap[digits[i]-'2'].size();j++){
            lettercomb(digits, digitmap, temp+digitmap[digits[i]-'2'][j],i+1);
        }       
    }
    // main function
    vector<string> letterCombinations(string digits) {
        vector<vector<char>>digitmap;
        string temp;
        // preparing data vector
        digitmap.push_back({'a','b','c'});
        digitmap.push_back({'d','e','f'});
        digitmap.push_back({'g','h','i'});
        digitmap.push_back({'j','k','l'});
        digitmap.push_back({'m','n','o'});
        digitmap.push_back({'p','q','r','s'});
        digitmap.push_back({'t','u','v'});
        digitmap.push_back({'w','x','y','z'});
        if(digits.length()==0){
            return res ;
        }
        int i=0;
        lettercomb(digits, digitmap,temp,i);
        return res;
    }
};
