/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //快慢指针法：slow一次走一个，fast一次走2个，当第一次相遇时，fast返回起点，之后一起一次走一个，下次相遇就是环的起点。注意边界条件的判断

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return nullptr;
		ListNode* fast = head->next->next;
		ListNode* slow = head->next;
		while (fast != slow) {
			if (fast->next == nullptr || fast == nullptr || fast->next->next == nullptr) return nullptr;
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = head;
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};