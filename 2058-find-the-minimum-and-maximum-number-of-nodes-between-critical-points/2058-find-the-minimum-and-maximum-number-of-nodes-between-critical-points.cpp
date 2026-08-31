class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int first = -1;
        int last = -1;
        
        int minDistance = INT_MAX;
        
        int index = 1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr->next != nullptr) {
            
            ListNode* next = curr->next;
            
            // Check if curr is a critical point
            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);
            
            if (isCritical) {
                
                
                if (first == -1) {
                    first = index;
                }
                
                
                else {
                    minDistance = min(minDistance, index - last);
                }
                
              
                last = index;
            }
            
            prev = curr;
            curr = next;
            index++;
        }
        
        
        if (first == last) {
            return {-1, -1};
        }
        
        int maxDistance = last - first;
        
        return {minDistance, maxDistance};
    }
};