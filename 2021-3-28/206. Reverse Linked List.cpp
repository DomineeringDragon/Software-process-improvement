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
    ListNode* reverseList(ListNode* head) {
        ListNode* point =nullptr;
        ListNode* temp;
        while(head!=nullptr){
            temp=head->next;
            head->next=point;
            point=head;
            head=temp;
        }
        return point;
    }
};
