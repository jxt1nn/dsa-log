/*

For example, the string "ababcc" can be partitioned into ["abab", "cc"],
but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

by obseerving the example we can say thaat 
start and end point of a char should be in  one parition.........

means we are going for last occcurance of a char 

👉 Whenever you see a letter, you must go till its LAST occurrence

👉 If you include a character in a part,
you must include ALL its occurrences in that same part.

this question follow same condition of merge interval question

        “Expand boundary until safe to cut”

While iterating:

    Keep a range (window) [start → end]
    Expand end based on some condition
    When you reach end, you cut

👉 “Don’t cut until all dependencies are finished.”


Dependency = last occurrence of characters

So:
Every character says → “I end at index X”
You must go till max of all X


pattern template :


start = 0
end = 0

for(i = 0 → n-1):
    update end based on condition
    
    if(i == end):
        // safe to cut
        answer.push_back(size)
        start = i + 1


s = "ababcc"
last positions:
a → 2
b → 3
c → 5


s = "ababcc"

i = 0 → 'a' → last = 2 → end = 2
i = 1 → 'b' → last = 3 → end = 3 (expand!)
i = 2 → 'a' → last = 2 → no change
i = 3 → 'b' → last = 3 → no change

Now i == end → cut partition → size = 4

Next:
i = 4 → 'c' → last = 5 → end = 5
i = 5 → 'c' → last = 5

i == end → cut → size = 2

✅ Final Answer:
[4, 2]


*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26);

        // store last occurrence
        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> result;
        int start = 0, end = 0;

        for(int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);

            if(i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};