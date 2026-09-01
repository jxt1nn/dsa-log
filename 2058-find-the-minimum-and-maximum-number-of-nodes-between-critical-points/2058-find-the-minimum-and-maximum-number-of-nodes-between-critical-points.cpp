/**

    brute

        store every index 

    then traverse 

    space comp  ???????????????

    for max =  1st and last

    for mini = every pair







//  */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int cnt = 1;              // position of current node
        int first = -1;
        int last = -1;

        int mini = INT_MAX;

        ListNode* prev = head;
        head = head->next;

        while (head->next != NULL) {

            // Check if current node is a critical point
            bool critical = false;

            // Local maximum
            if (prev->val < head->val && head->val > head->next->val) {
                critical = true;
            }

            // Local minimum
            else if (prev->val > head->val && head->val < head->next->val) {
                critical = true;
            }

            if (critical) {

                if (first == -1) {
                    // First critical point
                    first = cnt;
                } 
                else {
                    // Distance from previous critical point
                    mini = min(mini, cnt - last);
                }

                // Update last critical point
                last = cnt;
            }

            prev = head;
            head = head->next;
            cnt++;
        }

        // Fewer than 2 critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }

        int maxi = last - first;

        return {mini, maxi};
    }
};
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> idx;
//         int cnt = 0;
//         ListNode* prev = NULL;
        
//         while(head->next){
//             if(prev != NULL){
//                 //maxi
//                 if((prev->val < head->val) && (head->next->val < head->val)){
//                     idx.push_back(cnt);
//                 }
//                 //mini
//                 else if((prev->val > head->val) && (head->next->val > head->val)){
//                     idx.push_back(cnt);
//                 }
//             }
//             prev = head;
//             head = head->next;
//             cnt++;
//         }
//         if(idx.size() < 2) return {-1,-1};
//         vector<int> ans(2,-1);
//         int mini = INT_MAX;
//         int dist = idx[idx.size()-1] - idx[0]; 
//         ans[1] = dist;

//         for(int i =1;i < idx.size();i++){
//             int dist = idx[i] - idx[i-1];
//             mini = min(mini,dist); 
//          }

//          ans[0] = mini;

//          return ans;
//     }
// };