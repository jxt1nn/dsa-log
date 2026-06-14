/**

    by hint 1 

    we can go to middle node by fast and slow pointer than,

    reverse from mid point to end point 
    then find mid point again then do 

    sum of first node and mid node........

    comapre and continue.............
 */
class Solution {
public:
    ListNode* reverseFromNode(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev; // new head of reversed part
    }   
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevSlow = NULL;

        while(fast != NULL){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverseFromNode(slow);
        prevSlow->next = newHead;

        prevSlow = prevSlow->next;
        int ans = INT_MIN;

        while(prevSlow != NULL){
            int val1 = head->val;
            int val2 = prevSlow->val;

            int sum = val1 + val2;

            ans = max(ans,sum);
            prevSlow = prevSlow->next;
            head = head->next;
        }

        return ans;
    }
};