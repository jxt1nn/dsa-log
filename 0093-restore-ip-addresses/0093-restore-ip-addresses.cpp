/*

we have to place dots only in existing string 

make sure we use only 3 dots to cover the string 
and 
integer exceed the limit of 255


return all possible valid IP addresses 

BACKTRACKING................

means we have to make our answer gradualy 
and we reach size n 

this is valid string and we need to store it in answer array 

void solve(state) {

    if(base_case) {
        store answer;
        return;
    }

    for(all choices) {

        if(valid choice) {

            choose

            solve(next state)

            undo choice
        }
    }
}

what are the states ?????

solve(index,dotUSed,currentPath)

index → where we are
dotsUsed → how many parts created
currentPath → current IP being built


what are the choices we have????????????

    At some index:

s = "25525511135"
      ^
    index

How many digits can ONE part of IP take?

IP block examples:

0
25
255

can i take 4 digits???????NOOOOOOOOOOO

So each segment length can only be:

1 digit
2 digits
3 digits

THIS is your choice

So your recursion choices are:
From current index:

Take 1 digit
Take 2 digits
Take 3 digits

Then check validity.

for(len = 1 to 3)
        
        "25525511135"



                 ""
         /        |        \
       "2"      "25"     "255"

how to write recursion..............


what is the base CASE???

if(index == s.size() && dotUsed == 4){
    store 
    return
}


loop : 

for(int i =0; i < 3;i++){

    choose

    explore 

    undo
}


what do inside the loop???

newAddition = s.substr(index, i);

explore:
if(valid){
    solve(index+i,curr + newAddition + ".",usedDot+1)
}

no need to pop back something bcoz 
when we are not adding anything in a string we just join in function'




*/
class Solution {
public:
    vector<string> ans;

    bool isValid(string part){

        if (part.size() > 1 && part[0] == '0') {
            return false;
        }

        int num = stoi(part);

        return num >= 0 && num <= 255;

    }
    void solve(int index,int parts,string curr,string& s){

        if(index == s.size() && parts == 4){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        if(index >= s.size() || parts > 4){
            return;
        }

        for(int len = 1; len <= 3;len++){

             // out of bounds
            if (index + len > s.size()) {
                break;
            }
            
            string part = s.substr(index, len);

            if(isValid(part)){
                
                solve(index + len,
                        parts + 1,
                        curr + part + ".",
                        s);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {

        solve(0,0,"",s);
        return ans;
    }
};