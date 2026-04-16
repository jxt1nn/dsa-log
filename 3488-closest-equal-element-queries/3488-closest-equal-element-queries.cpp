/*

    lets not thinnk now about circular thing............

    just how to find the if nums[queries [i]] element present
        on other indexes or not??

    can we make a adjVector
        that show the index of every elemnt 

    nums = [1,3,1,4,1,3,2]
    index= [0,1,2,3,4,5,6]
    
    1 on : 0 2 4 
    2 on : 6
    3 on : 1 5 
    4 on : 3

    now we can itrate in queries 
    and perform operations  


    The minimum distance between the element at index queries[i]
    and any other index j in the circular array, 
    where nums[j] == nums[queries[i]]. 
    If no such index exists, the answer for that query should be -1
    
    
    .
    For each value, you already have:
    positions = [i1, i2, i3, ...]

    The closest same value for any index will be:

    either previous occurrence
    or next occurrence

    NOT all elements!

    IDEA:
    1. Get list of indices of that value
    2. Find its position using binary search
    
    3. Check only:
        left neighbor
        right neighbor

    4. Compute circular distance

    what is circular distnace??????????????


    In a normal array:

    distance = |i - j|

    But in a circular array, you have 2 paths:

    Example:
    nums = [1,2,3,4,5,6,7]
    index:  0 1 2 3 4 5 6

    Find distance between:

    i = 0, j = 6

    Path 1: Direct (right side)
    0 → 6 = 6 steps

    Path 2: Circular (wrap around)
    0 → 6 via left = 1 step

    👉 So minimum distance = 1

    🔥 That’s why formula is:
        min(
            abs(i - j),          // direct distance
            n - abs(i - j)       // circular wrap distance
        )
  
    IMPORTANT PART.........


    Find its position using binary search
    
    Check only:
        left neighbor
        right neighbor


    how to do this???

    vec = all indices where nums[q] appears (sorted)

    For index q, the closest same value will be:

    next occurrence
    previous occurrence
    OR circular wrap (first/last)

    1. Find position of q in vec :

    find the lower bound of queies[i] :
    
    auto it = lower_bound(vec.begin(), vec.end(), queries[i]);
    it points to index q inside vec

    vec = [0,2,4]
    q = 2
    it → points to 2

    Check RIGHT side (next occurrence)
    Check Left  side (previous occurance)

    Circular wrap case (VERY IMPORTANT)

    int first = vec[0];
    int last = vec.back();

    why needed?

    Because array is circular:

    vec = [0,2,4]
    q = 0

    previous doesn't exist ❌
    but circularly → last = 4 ✅

    int d1 = min(abs(q - first), n - abs(q - first));
    int d2 = min(abs(q - last), n - abs(q - last));

    👉 Check only:

    next index in vec
    previous index in vec
    first element (circular wrap)
    last element (circular wrap)

    👉 Take minimum distance


    how to make adjVector 
    how to code it ?????????

    create : vector<vector> adj;
    
    just loop in nums
    then :
        adj[nums[i]].push_back(i);

    we done for adjVector 

    AFTER that.........

    traverse in queries....

    for each queries[i]
    in adjlist of nums[queries[i]]

    loop and check the minimum distance 

*/
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // build mapping
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int q : queries){
            auto &vec = mp[nums[q]];

            if(vec.size() == 1){
                ans.push_back(-1);
                continue;
            }

            auto it = lower_bound(vec.begin(), vec.end(), q);

            int res = INT_MAX;

            // next element (circular handled later)
            if(it + 1 != vec.end()){
                int j = *(it + 1);
                res = min(res, min(abs(q - j), n - abs(q - j)));
            }

            // previous element
            if(it != vec.begin()){
                int j = *(it - 1);
                res = min(res, min(abs(q - j), n - abs(q - j)));
            }

            // circular wrap
            int first = vec[0];
            int last = vec.back();

            if(first != q){
                int d1 = min(abs(q - first), n - abs(q - first));
                res = min(res, d1);
            }

            if(last != q){
                int d2 = min(abs(q - last), n - abs(q - last));
                res = min(res, d2);
            }
            ans.push_back(res);
        }

        return ans;
    }
};