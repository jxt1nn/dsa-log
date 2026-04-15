/*

"hello","i","am","leetcode","hello","hello","i","am","leetcode","hello"]


"a","b","leetcode"]"a","b","leetcode"]

what am thinking......

make a array of size 2n

words + words 

then one pointer on original index and other one on 
rightIndex = (startIndex + words.size()) % words.size()
rightIndex + word.size();


then left goes right side 
and right go left side and 
which ever find target first we return its count.............


or we can find target index 
then find left and right index from it
and calculate distance and return minimum one 

how????
right = (i - startIndex + n) % 4
left = (startIndex - i + n) % 4 
*/
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int right = (i - startIndex + n) % n;
                int left = (startIndex - i + n) % n;
                ans = min(ans, min(right, left));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};  
