/*
    we have to need some balance to give change 
        without balance we cannot proceed transaction...........

    start wth index 0
    if (nums[i] > 5) return false 
    bcoz if it greater than 5 we have no balance to give chnage 


    if it not > 5 then proceed further

    if have to maintain number of notes we have and their kind

    five 
    ten
    twenty 

    if someone give us 20 dollor bill 
    we need to give him 15 in return
    so what are our bill ???


    twenety bills are usless we can never give it to customer

    if someone give us 20
    we have 2 choices 
        5 + 5 + 5 = 15
            OR
        10 + 5 = 15

    if someone give us 10
    only choices we have 
        5 
    

    add amount in total

*/
class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int f = 0, t = 0, tw = 0;

        if(nums[0] > 5) return false;

        for(int i =0;i < nums.size();i++){
            if(nums[i] == 5) f++;

            if(nums[i] == 10){
                t++;
                if(f >= 1){
                    f--;
                }
                else{
                    return false;
                }
            }

            if(nums[i] == 20){
                tw++;
                if(f >= 1 && t >= 1){
                    f--;
                    t--;
                }
                else if(f >= 3){
                    f -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};