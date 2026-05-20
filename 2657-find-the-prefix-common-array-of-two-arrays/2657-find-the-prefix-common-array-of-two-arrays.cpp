/*

    make a freq array 

    sum = 0;

    dono check krke value of that index is sum 

    only add value in sum when 
    freq[i] < 2




*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int i = 0;
        int n = A.size();
        
        int sum = 0;
        vector<int> freq(n+1,0);
        vector<int> ans;
        
        while(i != A.size()){

            freq[A[i]]++;
            freq[B[i]]++;

            if(A[i] == B[i]){
                sum++;
            }
            else{
                if(freq[A[i]] == 2){
                    sum++;
                }
                if(freq[B[i]] == 2){
                    sum++;
                }
            }
            i++;
            ans.push_back(sum);
        }
        return ans;       
    }
};