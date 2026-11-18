/* compiler: ee-gcc2.9-991111 */
struct Node {
    struct Node *next;
    char pad4[0xc8];
    unsigned int flags;
    char padD0[0x18];
    void *free;
};
struct State { int a,b,c; struct Node *head; int d; volatile int updates; };
extern struct State D_0077A008;
extern struct Node *func_004D3170(int, int, int);
extern int func_004D3B50(struct Node *);
void func_004D3CF8(void) {
    struct Node *p = D_0077A008.head;
    struct Node *next = p->next;
    D_0077A008.updates++;
    while (next) {
        p = next;
        next = p->next;
    }
    if ((int)(p->flags >> 1) > 0) {
        struct Node *n = func_004D3170(0, 0x100, 0);
        p->next = n;
        if (n) {
            char *cursor;
            char **link;
            char *following;
            char *end;
            p->free = (char *)n + 4;
            link = (char **)p->free;
            p = n;
            p->next = 0;
            cursor = (char *)p;
            end = cursor + 0xf4;
            following = cursor + 0x10;
            do {
                *link = following;
                *(int *)(cursor + 8) = 0;
                link = (char **)((char *)link + 12);
                *(int *)(cursor + 12) = 0;
                following += 12;
                cursor += 12;
            } while ((unsigned int)link < (unsigned int)end);
            n->free = 0;
        }
    }
    for (p = D_0077A008.head; (next = p->next) != 0; p = next) {
        if (!next->next) break;
    }
    if (next && (p->flags >> 1) == 0) {
        struct Node *old = p;
        p = next;
        old->free = 0;
        old->next = 0;
        func_004D3B50(p);
    }
}
