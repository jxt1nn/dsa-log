/*

(i, j, k) of 3 distinct indices 
good if : 
    nums[i] == nums[j] == nums[k].

distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i),

    Return an integer denoting the minimum possible distance of a good tuple
    else return -1

CONSTRAINTS ARE SMOLLLLLLLLLL

brute force :
for i
  for j
    for k
      if nums[i] == nums[j] == nums[k]
         compute distance

Complexity = O(n³) → too slow

intuition:

    for a good tuple element count should be >= 3

if its >= 3 i can be our potential tuple 

|i - j| + |j - k| + |k - i|

assume they are in sorted order :

        i < j < k

Now remove absolute:

|i - j| = j - i
|j - k| = k - j
|k - i| = k - i  

Add them:

(j - i) + (k - j) + (k - i) = 2 * (k - i)

big insight

👉 distance depends ONLY on:

first index (i) and last index (k)
Middle index j doesn't matter!!!!!!!!!!!!!!!!

Now the problem becomes:

For every value, pick 3 indices, and minimize:
2 * (max_index - min_index)


what do we actually need????????

For each number:
colllect all indices where it appear 

example:
    nums = [1, 2, 1, 1, 2]
    1 → [0, 2, 3]
    2 → [1, 4]

if a number appears < 3 times → ignore

How to minimize distance?
(k - i) → minimum

SOOOOOOOOOO pick k and i as close as possible  

For each value:

Take its index list
Check every consecutive group of 3 indices

[0, 2, 3, 10]
    check:
        (0,2,3)
        (2,3,10)

Compute:
    distance = 2 * (k - i)


what we need for code:

1. array for each element index
    like we get 2 
    we push index of array which is made for element 2 

then check 
2 → only 2 elements ❌ skip
1 → 4 elements ✅ process

[0, 2, 3, 5]

Triplet 1:
    (0, 2, 3)
Distance:

|0-2| + |2-3| + |3-0|
= 2 + 1 + 3 = 6

Triplet 2:
    (2, 3, 5)

Distance:

|2-3| + |3-5| + |5-2|
= 1 + 2 + 3 = 6

Answer :
    min = 6

we never check :
    (0,2,5), (0,3,5)

Because:
They are farther apart → distance increases

*/
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // store indices
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        //process each value
        for (auto &it : mp) {
            vector<int> &idx = it.second;

            // need at least 3 indices
            if (idx.size() < 3) continue;

            // check consecutive triplets
            for (int i = 0; i + 2 < idx.size(); i++) {
                int a = idx[i];
                int b = idx[i + 1];
                int c = idx[i + 2];

                int dist = 2 * (c - a);  // optimized
                // int dist = abs(a - b) + abs(b - c) + abs(c - a);

                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};