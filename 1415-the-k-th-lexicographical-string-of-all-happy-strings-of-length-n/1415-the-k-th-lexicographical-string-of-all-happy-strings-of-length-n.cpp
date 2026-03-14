/*
    we have to foam the string of size "n"

        but adjacnet element should not be same
    FOR this we have to keep store the previous element 
        so we cannot usu it again..............


    we have to try all possiblities........

        ------RECUSRION--------


    like in this example we find all happy string of length n :

    ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"].

    and sort them, return the 9th

    how can we find all happy string of length n ???????????

    we know recursion but how?????????

    we have 3 choices on each step.........
        but we can choice 2 only 
            don't take the same char again........

    by doing dry run we get to 
    know that only take pervious seriously 

    if  prev = a  (b , c)
    if prev = b (a ,c)
    if prev = c (a , b)

    we can run 3 recursion 

    for a
    for b 
    for c  


    lets write recusion......

    possibilities 

    if(prev == a){
        for b :solve(prev(b) , s+=b,n-1)
        for c :  solve(c, s , n-1)
    }   
    else if(prev == b){

    }
    else if(prev == c){
        
    }

    when we enter a recusrion..........

    we have to join the prev element in string.........

     str += prev

    then check base case :

    what is base case ???

    if(n ==0 ){
        push into array...
        return;
    }

    this would be a void function..

**/
class Solution {
public:
    void solve(int n, string str, char prev, vector<string>& ans){
        str += prev;

        if(n == 0){
            ans.push_back(str);
            return;
        }

        if(prev == 'a'){
            solve(n-1,str,'b',ans);
            solve(n-1,str,'c',ans);
        }
        else if(prev == 'b'){
            solve(n-1,str,'a',ans);
            solve(n-1,str,'c',ans);
        }
        else{
            solve(n-1,str,'a',ans);
            solve(n-1,str,'b',ans);
        }
    }

    string getHappyString(int n, int k) {

        vector<string> ans;

        solve(n-1,"",'a',ans);
        solve(n-1,"",'b',ans);
        solve(n-1,"",'c',ans);

        if(k > ans.size()) return "";

        return ans[k-1];
    }
};