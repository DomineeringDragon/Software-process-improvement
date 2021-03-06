/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //����ָ�뷨��slowһ����һ����fastһ����2��������һ������ʱ��fast������㣬֮��һ��һ����һ�����´��������ǻ�����㡣ע��߽��������ж�

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