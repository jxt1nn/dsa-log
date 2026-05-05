/**
just take the head of the link list and attach to the tail 

where to cut the linklist??????????
IMO

find the size of linklist 

then cut linklist size-k

and store cut point of second linklist 

then join the end of the second list to the head 


    break the list → take second part → attach it before head

this is correct for 217/232

but too risky so what we do 

instead of :

    break → then reconnect

Think:

    connect first → then break

        means join the tail to head -> make it circular 
     then cut the linklist.........

 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: find length
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: make circular
        tail->next = head;

        // Step 3: adjust k
        k = k % n;

        // Step 4: find new tail
        int steps = n - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 5: break
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        // tail->next = head; wrong

        return newHead;
    }
};