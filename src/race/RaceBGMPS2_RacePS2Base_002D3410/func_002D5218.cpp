/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Node { char pad[0x4]; Node *next; char pad8[0x10]; char *car; };
struct List { char pad[0x10]; Node *head; };
struct R6C { char pad[0x60]; List *list; };

extern "C" void func_00421BE0(s32);
extern "C" void CourseEnvPtr__setReflectionFlareParameter(void *, s32);
extern "C" void func_00390E30(char *);
extern "C" void func_00391260(char *);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);

typedef char *(*GetFn)(char *, s32);
typedef s32 (*TestFn)(char *, char *, Node *);
typedef s32 (*Test2Fn)(char *, Node *);
typedef void (*F1)(char *, float);
typedef void (*F2)(char *, char *, float);

extern "C" void func_002D5218(char *arg0) {
    char *s3 = arg0 + 0xE60;
    func_00421BE0(1);
    VEntry *e1 = (VEntry *)(*(char **)(arg0 + 0x64) + 0xD0);
    char *s4 = ((GetFn)e1->fn)(arg0 + e1->delta, 0);
    R6C *r = *(R6C **)(arg0 + 0x6C);
    List *l = r->list;
    CourseEnvPtr__setReflectionFlareParameter(*(void **)(*(char **)(*(char **)((char *)r + 0x80) + 4) + 0x80), (s32)s3);
    func_00390E30(s3);
    Node *n = l->head;
    if (n != 0) {
        do {
            VEntry *e2 = (VEntry *)(*(char **)s4 + 0x1B8);
            char *c = n->car;
            if (((TestFn)e2->fn)(s4 + e2->delta, *(char **)(arg0 + 0x6C), n) != 0 && *(unsigned char *)(c + 0x565) == 0) {
                VEntry *e3 = (VEntry *)(*(char **)(arg0 + 0x64) + 0x4D8);
                if (((Test2Fn)e3->fn)(arg0 + e3->delta, n) != 0) {
                    func_00473050();
                    char *a1 = *(char **)((char *)n + 0x4840);
                    VEntry *e4 = (VEntry *)(*(char **)(a1 + 8) + 0x158);
                    ((F1)e4->fn)(a1 + e4->delta, 0.0f);
                    char *a2 = *(char **)((char *)n + 0x4840);
                    VEntry *e5 = (VEntry *)(*(char **)(a2 + 8) + 0x168);
                    ((F2)e5->fn)(a2 + e5->delta, s3, 0.0f);
                    func_004730A8();
                }
            }
            n = n->next;
        } while (n != 0);
    }
    func_00391260(s3);
}
