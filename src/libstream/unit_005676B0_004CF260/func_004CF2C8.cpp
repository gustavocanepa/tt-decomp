/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node {
    Node *next;
};

struct Queue {
    Node *head;
    Node **tail;
    Node *pendingHead;
    Node **pendingTail;
};

extern "C" void func_005038D8(void);
extern "C" int func_00503928(void);

extern "C" void *func_004CF2C8(Queue *queue) {
    func_005038D8();
    Node *node = queue->head;
    if (node == 0) {
        func_00503928();
        return 0;
    }

    node->next = 0;
    *queue->pendingTail = node;
    queue->pendingTail = &node->next;
    if ((queue->head = node->next) == 0) {
        queue->tail = &queue->head;
    }
    func_00503928();
    return (char *)node + 4;
}
