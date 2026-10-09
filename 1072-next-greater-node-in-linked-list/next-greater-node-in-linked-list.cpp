/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        ListNode* temp=head;
        while(head !=NULL){
            temp=head;
            while(temp && temp->val <=head->val) 
            temp=temp->next;
            if(temp==NULL) v.push_back(0);
            else
            v.push_back(temp->val);
            head=head->next;
        }
        return v;
    }
};