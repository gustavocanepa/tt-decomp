/* compiler: ee-gcc2.9-991111 */
/* Remove a node from the doubly linked list whose head is D_005A4128; returns the node's former next. */
struct ListNode {
	ListNode *next;
	ListNode *prev;
};

extern "C" ListNode *D_005A4128;

extern "C" ListNode *func_00504750(ListNode *node)
{
	ListNode *next = node->next;
	if (node->prev)
		node->prev->next = next;
	else
		D_005A4128 = next;
	if (next)
		next->prev = node->prev;
	node->prev = 0;
	return next;
}
