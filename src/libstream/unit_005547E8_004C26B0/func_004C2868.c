/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef struct Node { int id; struct Node *next; } Node;
typedef struct Queue { Node *head; Node *tail; } Queue;
typedef struct Pool { int handle; char pad[0x10]; int owner; int flags; } Pool;
Node *func_004CF2C8(int);
int func_004FA710(void);
void func_004FA740(void);
void func_004FA750(int);
int func_005038D8(void);
int func_00503928(void);
int func_004C2868(Pool *pool, Queue *q) {
    int f;
    Node *n = func_004CF2C8(pool->handle);
    n->id = func_004FA710();
    n->next = 0;
    *(Node **)q->tail = n;
    q->tail = (Node *)&n->next;
    f = pool->flags;
    if (!(f & 1)) return f;
    func_00503928();
    func_004FA740();
    func_005038D8();
    if (!(pool->flags & 1)) {
        func_00503928();
        func_004FA750(pool->owner);
        func_005038D8();
    }
    f = pool->flags;
    return f;
}
