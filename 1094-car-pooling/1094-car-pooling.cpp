/*

capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] 

totalNmber of passenegers in this trips > capacity 
we cannot drop off all the passenegers

how to check???

At any point on the road, does the number of people inside exceed capacity?

Instead of thinking about trips, think about changes in passengers
For each trip [p, from, to]:

At from → +p passengers
At to → -p passengers

example :

capacity = 4
trips = [[2,1,5], [3,3,7]]
At 1 → +2
At 3 → +3
At 5 → -2
At 7 → -3

Now walk from left → right:

Position	Change	Current Passengers
1	        +2	        2
3	        +3	        5 ❌ (exceeds 4)

👉 Answer = false


*/


class Solution {
public:
   bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> changes(1001, 0); // max location = 1000
        
        for (auto &trip : trips) {
            int p = trip[0];
            int from = trip[1];
            int to = trip[2];
            
            changes[from] += p;
            changes[to] -= p;
        }

        int curr = 0;
        for (int i = 0; i <= 1000; i++) {
            curr += changes[i];
            if (curr > capacity) return false;
        }

        return true;
    }
};