/*

    "simultaneously"    
        means every element gets same amount of seconds


    we have to find minimum number of seconds.....

    by reading time
        very first thought is binary search on anssers(time)

    for now assume we use binary search on time 

    and get TIME

    for this time how many height each worker can reduce 
    
    if total height works can reduce in this time

                    >= 

                mountainHeight 

    its possible to do this is that time 
        we have to find the smaller time 
    SOOOOOOO

    ans = mid 
    high  = mid-1

    and if its not possible
        total < mountainHeight 
            return false

    and low = mid + 1

    so how can we find this possible of not????????

    example: 
        t = 2 (nums[i])
        T = 20 (by binary search)

    Steps:

    height = 1 → time = 2
    height = 2 → time = 2 + 4 = 6
    height = 3 → time = 6 + 6 = 12
    height = 4 → time = 12 + 8 = 20
    height = 5 → time = 20 + 10 = 30 (stop)

        Worker removes 4 height

    how can we turn this into code????????


    timeUsed = 0
    step = 1
    while(true){
        timeused += step * nums[i];

        if(timeUsed > T){
            break;
        }
        step++; (BCOZ, workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x)
        total++; (height reduce is 1 on every itration)

        if(total >= mountainHeight) return true;
    }
    
    what value we can take of 
    low and high 
    intially???????????

    if we go some complex thing 

    high = min_worker_time * h * (h + 1) / 2

    h is mountainHeight  

    this take us unnecessary time 

    we just go for safer 1e18
*/
class Solution {
public:
    bool possible(long long T, vector<int>& workerTimes, int mountainHeight) {
        long long total = 0;

        for(int t : workerTimes){

            long long timeUsed = 0;
            long long step = 1;

            while(true){

                timeUsed += step * t;

                if(timeUsed > T)
                    break;

                total++;
                step++;

                if(total >= mountainHeight)
                    return true;
            }
        }
        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    
        long long low = 1;
        long long high = 1e18;
        long long ans = high;

        while(low <= high){

            long long mid = low + (high - low)/2;

            if(possible(mid, workerTimes, mountainHeight)){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};