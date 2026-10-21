/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; };
struct Obj { int a, b; Node *head, *tail, *readyHead, *readyTail; int owner, pad, active; };
extern "C" int func_004FA710(void);
extern "C" int func_005038D8(void);
extern "C" void func_004A4F00(Obj *p) {
    int id = func_004FA710();
    int enabled = func_005038D8();
    if (p->active && id == p->owner) {
        Node *n = p->head;
        if (n) {
            if ((p->head = n->next) == 0) p->tail = 0;
            n->next = 0;
            if (p->readyTail != 0) p->readyTail->next = n;
            else p->readyHead = n;
            p->readyTail = n;
        }
    }
    if (enabled) __asm__ volatile("ei");
}
