/* compiler: ee-gcc2.9-991111 */
typedef struct Node {
    int magic0, magic4;
    struct Node *link, *next;
    char pad10[6]; unsigned short flags; char pad18[8];
    void (*fn)(int, struct Node *);
} Node;
extern int D_005A0BB0;
extern Node *D_0077A028;
extern Node D_0077A030;
int func_004D5518(Node *, Node *);
int func_004D5528(Node *, Node *);
int func_004D5580(Node *, Node *);
int func_004D5840(Node *, Node *);
void func_004FAAA0(int);
int func_005038D8(void);
int func_00503928(void);
int func_004D4748(Node *arg) {
    int intr;
    Node *p, *q, *next, *list, *outer;
    Node **slot;
    if (!D_005A0BB0) return 0x81058001;
    if (!arg || arg->magic0 != 0x4c785265 || arg->magic4 != 0x41004269)
        return 0x81059039;
    intr = func_005038D8();
    list = 0;
    p = D_0077A028;
    while (p) {
        if (p == arg || func_004D5528(arg,p)) {
            if (p == arg || func_004D5518(arg,p) <= 0) {
                if (intr) func_00503928();
                return 0x81059036;
            }
            q = p->next;
            slot = &p->next;
            p->next = 0;
            if (q) {
                outer = p->link;
                do {
                    next = q->next;
                    if (!(q->flags & 1)) {
                        q->next = list;
                        list = q;
                    } else {
                        *slot = q;
                        q->next = 0;
                        slot = &q->next;
                    }
                    q = next;
                } while (next);
            } else outer = p->link;
        } else outer = p->link;
        p = outer;
    }
    q = &D_0077A030;
    while (q->next) {
        if (func_004D5580(arg, q->next)) {
            next = q->next->next;
            q->next->next = list;
            list = q->next;
            q->next = next;
        } else q = q->next;
    }
    arg->next = 0;
    while (list) {
        next = list->next;
        func_004D5840(list, arg);
        list->next = arg->next;
        arg->next = list;
        list = next;
    }
    arg->flags &= 0xfffe;
    arg->link = D_0077A028;
    D_0077A028 = arg;
    func_004FAAA0(2);
    if (intr) func_00503928();
    arg->fn(0,arg);
    return 0;
}
