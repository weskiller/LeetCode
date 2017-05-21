//https://leetcode.com/problems/linked-list-random-node
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode * root {NULL};
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        root = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
		int result = root->val;
		ListNode * t = root->next;
		int n = 2;
		random_device r;
		while (t != NULL) {
			int m = r() % n;
			if (m == 0)
				result = t->val;
			t = t->next;
			n++;
		}
		return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
