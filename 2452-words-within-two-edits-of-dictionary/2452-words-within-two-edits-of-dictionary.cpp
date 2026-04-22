/*
    dont getting other approach 

    try brute force........

    take a wrod from quersiex and check if nay one getting match within 2 mismatches
    if it is add that word in answer array 


    and when ever mismacth exceed 2 break 
    and try anotrher word 

    for each query:
    for each dictionary word:
        count differences
        if <= 2:
            add to answer
            break




*/
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;

        for(int i = 0; i < queries.size(); i++){
            string one = queries[i];

            for(int j = 0; j < dictionary.size(); j++){
                string two = dictionary[j];

                int l = 0;
                int count = 0;

                while(l < two.size()){
                    if(one[l] != two[l]){
                        count++;
                    }

                    if(count > 2){
                        break;
                    }

                    l++;
                }

                if(count <= 2){
                    ans.push_back(one);
                    break; // IMPORTANT
                }
            }
        }

        return ans;
    }
};