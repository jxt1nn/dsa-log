/*
    
There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where

ranges[i] (0-indexed) means the i-th tap
can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water
the whole garden, If the garden cannot be watered return -1

lets assume we create a 2D array contaning 
    interval[i] = [start,end]

then sort it by start time 

this question now became something like jump game 2

for example :
n = 5, ranges = [3,4,1,1,0,0]

[-3,3], [-3,5], [1,3], [2,4], [4,4], [5,5]
Goal: cover [0,5]

At 0:
usable intervals → [-3,3], [-3,5]
pick farthest → [-3,5]

👉 Now covered till 5


for i from 0 to n:
    farthest = max(farthest, maxReach[i])

    if i == currEnd:
        taps++
        currEnd = farthest

    if i > farthest:
        return -1


but this is for 1D array we have 2D

can we some how convert this 2D array into 1D??????????

[-3,3], [-3,5], [1,3], [2,4], [4,4], [5,5]
Goal: cover [0,5]

Original intervals can go:
left of 0 (negative)
right of n

But our garden is only:
[0, n]
    👉 So anything outside this range is useless

For each interval [start, end]:

start = max(0, start);
end   = min(n, end);

THIS THING CALLED CLAMPING (convert it into particular range)

    Anything < 0 → treat as 0
    Anything > n → treat as n

[-3,3], [-3,5], [1,3], [2,4], [4,4], [5,5]

after clamping:
[0,3], [0,5], [1,3], [2,4], [4,4], [5,5]

From each clamped interval [l, r]:
👉 “If I start at l, how far can I go?”

[0,3], [0,5], [1,3], [2,4], [4,4], [5,5]
maxReach = [0,0,0,0,0,0]

maxReach[l] = max(maxReach[l], r);

    1. [0,3]
    maxReach[0] = max(0,3) = 3
    → [3,0,0,0,0,0]

    2. [0,5]
    maxReach[0] = max(3,5) = 5
    → [5,0,0,0,0,0]

    3. [1,3]
    maxReach[1] = max(0,3) = 3
    → [5,3,0,0,0,0]

    4. [2,4]
    maxReach[2] = 4
    → [5,3,4,0,0,0]

    5. [4,4]
    maxReach[4] = 4
    → [5,3,4,0,4,0]

    6. [5,5]
    maxReach[5] = 5
    → [5,3,4,0,4,5]

“Why ignore intervals starting at same index except max?”
👉 Greedy only cares about farthest reach

    Example:

    [0,3] vs [0,5]
    Obviously [0,5] is always better
    So we keep only the best.


[5,3,4,0,4,5] now this question became jump game 2 

we can apply code on this array :


for i from 0 to n:
    farthest = max(farthest, maxReach[i])

    if i == currEnd:
        taps++
        currEnd = farthest

    if i > farthest:
        return -1 


now how to code this up????????????

*comvert it ranges into interavls...
*now clmap this interval array 
    at the same time make maxReach array 

*now apply jump game 2 logic on this maxreach array 


here is a thing we can combine this 3 steps 1 in one go :

            *comvert it ranges into interavls...
            *now clmap this interval array 
                at the same time make maxReach array 


all of this in one go..........

for (int i = 0; i <= n; i++) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            maxReach[l] = max(maxReach[l], r);
    }






*/
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<vector<int>> intervals;

        for (int i = 0; i <= n; i++) {
            int start = i - ranges[i];
            int end = i + ranges[i];
            intervals.push_back({start, end});
        }

        vector<int> maxReach(n+1,0);

        for(auto &it : intervals) {
            int l = max(0,it[0]);
            int r = min(n,it[1]);

            maxReach[l] = max(maxReach[l],r);
        }

        // Build maxReach directly    

        // for (int i = 0; i <= n; i++) {
        //     int l = max(0, i - ranges[i]);
        //     int r = min(n, i + ranges[i]);
        //     maxReach[l] = max(maxReach[l], r);
        // }


        int jump = 0;
        int farthest  = 0;
        int currRange = 0;

        for(int i =0;i <= n;i++){
            if(i > farthest ) return -1;

            if (currRange >= n) return jump;
            
            farthest  = max(farthest ,maxReach[i]);

            if(i == currRange){
                jump++;
                currRange = farthest ;
            }

        }
        return jump;
    }
};