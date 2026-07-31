/*
    their can be only 26 different char

    obersvation 
    higher freq should take less time 

    so,
    calculate freq of each char 
    then, push it into maxHeap

    then,pop element one by one 
    and after every 8 char 
    count became + 1








*/
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);

        for(int i=0;i < word.size();i++){
            freq[word[i] - 'a']++;
        }   

        priority_queue<int> pq;
        for(int i =0;i < freq.size();i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }

        int count = 1;
        int sum = 0;    
        int i = 0;
        while(!pq.empty()){
            int t = pq.top();
            i++;
            pq.pop();

            if(i <= 8){
                sum += (t * 1);
            }
            else if(i > 8 && i <= 16){
                sum += (t*2);
            }
            else if(i > 16 && i <= 24){
                sum += (t*3);
            }
            else{
                sum += (t*4);
            }
        }
        return sum;      
    }
};