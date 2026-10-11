/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef struct Node {
    int id;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

typedef struct Pool {
    int handle;
} Pool;

int func_005038D8(void);
int func_00503928(void);
int func_004FA750(int id);
void func_004CF340(int handle, Node *node);

void func_004C27D8(Pool *pool, Queue *q) {
    Node *node;
    func_005038D8();
    while ((node = q->head) != 0) {
        func_00503928();
        func_004FA750(node->id);
        func_005038D8();
        if ((q->head = node->next) == 0)
            q->tail = (Node *)q;
        func_004CF340(pool->handle, node);
    }
    func_00503928();
}
