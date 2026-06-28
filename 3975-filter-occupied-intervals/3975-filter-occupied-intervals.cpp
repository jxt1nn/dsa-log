/*

    first step is the merge the intervals

    what factors are important:

    1. if overlap
    2. if touch 

    Two intervals touch if the second interval starts immediately after the first one ends.
    For example, [1, 1] and [2, 2] touch and should be merged into [1, 2].



    how to merge intervals??????

    sort them..........

    then process one by one
    
    NON OVERLAPPING :

    if(array is empty) -> first element
    if(prev_end < new_start) -> no need to merge 
        in both the cases directly push........

    
    OVERLAPPING OR TOUCHED :

        if(prev_end > new_start) OR if(prev_end + 1 == new_start)
                update previous entry 

        prev_end = max(prev_end,new_end);

    DONE............................

    we have 2 integres 
        freeStart 
        freeEnd
    
    remove all integer points in the free interval from the merged occupied intervals

    how to remove it

        [[2,8],[10,10],[14,16]]
        freeStart = 7
        freeEnd = 11 

    how many cases will be their??????????

    1. NO overlap 
        [s------e]          [freeStart----freeEnd]
        
        OR

        [freeStart----freeEnd]         [s------e]

    ans.push_back({s, e});

    2.Completely inside free interval
              [s-----e]
    [freeStart-----------freeEnd]

    Remove it completely.
    continue;

    3. Left part survives
        [s--------------e]
            [freeStart-----freeEnd]
    
    Keep
        [s-----freeStart-1]

    4. Right part survives
                [s--------------e]
    [freeStart-----freeEnd]

    keep 
        [freeEnd+1-----------e]

*/
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& nums, int fs, int fe) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> merge;

        for(auto &it : nums){
            if(merge.empty() || merge.back()[1] + 1 < it[0]){
                merge.push_back(it);
            }
            else{
                merge.back()[1] = max(merge.back()[1],it[1]);
            }
        }

        vector<vector<int>> result;

        for(const auto& it : merge){
            int s = it[0];
            int e = it[1];

            if(e < fs || s > fe){
                result.push_back({s,e});
            }
            else if(s >= fs && e <= fe){
                continue;
            }
            else{
                if(s < fs){
                    result.push_back({s,fs-1});
                }
                if(e > fe){
                    result.push_back({fe + 1,e});
                }
            }
        }
        return result;
    }
};