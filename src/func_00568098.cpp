typedef int s32;
typedef unsigned int u32;

struct Node {
    char pad0[0xE8];
    struct Node *next;
    struct Node *other;
};

struct Obj {
    char pad0[0x1E04];
    struct Node *head;
    s32 count;
};

struct Q {
    char pad0[0x4];
    struct Node *head;
};

extern "C" void func_00568140(void *, void *);

extern "C" struct Q *func_00568098(struct Q *arg0, struct Obj *arg1, struct Q *arg2, struct Q *arg3) {
    struct Node *s0;
    struct Node *s2;
    struct Node *a1;

    s0 = arg2->head;
    if (s0 != arg1->head) {
        s2 = arg3->head;
        s0->other->next = s2;
        s2->other = s0->other;
        if (s0 != s2) {
            do {
                a1 = s0;
                s0 = s0->next;
                func_00568140(arg1, a1);
                arg1->count = arg1->count - 1;
            } while (s0 != s2);
        }
    }
    *arg0 = *arg3;
    return arg0;
}
