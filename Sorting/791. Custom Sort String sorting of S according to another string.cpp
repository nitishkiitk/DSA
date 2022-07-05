// You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

// Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.

class Solution {
public:
    //comparator
    static bool cmp(pair<char,int>p1, pair<char,int>p2){
        return p1.second<p2.second;
    }
    string customSortString(string order, string s) {
        // assinging rank for each element acc to order string
        int rank[26];
        for(int i=0;i<26;i++){
            rank[i]=INT_MAX;
        }
        for(int j=0;j<order.length();j++){
            rank[order[j]-'a']=j;
        }
        // making vector of  pair of element and rank of the 
        vector<pair<char, int>>vec;
        for(int i=0;i<s.length();i++){
            vec.push_back({s[i],rank[s[i]-'a']});
        }
        //sorting
        sort(vec.begin(), vec.end(),cmp);
        // finding returning string
        string res="";
        for(int i=0;i<s.length();i++){
            res+=vec[i].first;
        }
        return res;
    }
};