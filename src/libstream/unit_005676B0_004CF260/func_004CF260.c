/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct Node {
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node **tail;
    Node *pendingHead;
    Node **pendingTail;
} Queue;

void func_005038D8(void);
void func_00503928(void);

void func_004CF260(Queue *q)
{
    Node *n;

    func_005038D8();
    while ((n = q->pendingHead) != 0) {
        n->next = 0;
        *q->tail = n;
        q->tail = &n->next;
        if ((q->pendingHead = n->next) == 0)
            q->pendingTail = &q->pendingHead;
    }
    func_00503928();
}
