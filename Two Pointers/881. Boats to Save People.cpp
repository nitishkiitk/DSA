// You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

// Return the minimum number of boats to carry every given person.
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0,j=n-1;
        int count=0;
        while(i<=j){
            // if weight is greater than limit then store that in one
            if(people[i]>=limit){
                count++;
                i++;
            }
            else if(people[j]>=limit){
                count++;
                j--;
            }
            // we can take maxm 2 in 1 so if sum is less than equal to limit then also we will store in a boat
            else if(people[i]+people[j]<=limit){
                count++;
                i++;
                j--;
            }
            // if sum will be greater than we will check and the greater one index will be moved accordingly
            else{
                if(people[i]>=people[j]){
                    count++;
                    i++;
                }
                else{
                    count++;
                    j--;
                }
            }
        }
        return count;
    }
};