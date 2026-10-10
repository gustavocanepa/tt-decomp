struct Node {
    Node *next;
};

extern "C" Node *func_0055BD30(Node **arg0) {
    Node *head = *arg0;
    if (head == 0) {
        return 0;
    }
    *arg0 = head->next;
    return head;
}
