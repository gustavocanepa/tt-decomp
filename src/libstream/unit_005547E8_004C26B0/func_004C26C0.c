/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef struct Node { int id; struct Node *next; } Node;
typedef struct Queue { Node *head; Node *tail; } Queue;
typedef struct Pool {
    int handle;
    Queue a;
    Queue b;
    int f14;
    int flags;
    int f1C;
    int f20;
    int pad24;
    int f28, f2C, f30, f34;
} Pool;
int func_005038D8(void);
int func_00503928(void);
int func_004FA710(void);
void func_004FA740(void);
void func_004C27D8(Pool *pool, Queue *q);
void func_004CF260(int);
void func_004C26C0(Pool *p) {
    int n = 0;
    Node *node;
    func_005038D8();
    p->flags &= ~1;
    for (node = p->b.head; node != 0; node = node->next) n++;
    for (node = p->a.head; node != 0; node = node->next) n++;
    n--;
    func_00503928();
    func_004C27D8(p, &p->a);
    func_004C27D8(p, &p->b);
    func_005038D8();
    p->f14 = func_004FA710();
    while (n != -1) {
        n--;
        func_00503928();
        func_004FA740();
        func_005038D8();
    }
    func_004CF260(p->handle);
    p->f28 = 0;
    p->f2C = 0;
    p->f30 = p->f20;
    p->f34 = 0;
    func_00503928();
}
