/* compiler: ee-gcc2.9-991111 */
struct Entry { int a, b, c; struct Entry *next; char *name; unsigned short version, flags; int x18, x1c; };
struct Lib { int a, b; struct Lib *next; struct Entry *clients; };
struct G { struct Lib *libs; int f4; struct Entry anchor; };
extern struct G D_0077A028;
void func_004D55E0(struct Entry *);
int func_004D5978(struct Lib *, struct Entry *);
void func_004FAAA0(int);
int func_005038D8(void);
int func_00503928(void);

/* _sceErxUnLinkLibraryClients */
int func_004D52B8(int *start, unsigned int size)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));
int func_004D52B8(int *start, unsigned int size) {
    int *end = start + (size >> 2);
    struct Lib *lib, *next;
    struct Entry *c, *e, *prev, *t, *n;
    int intr;

    intr = func_005038D8();
    for (lib = D_0077A028.libs; lib != 0; lib = next) {
        next = lib->next;
        for (c = lib->clients; c != 0; c = c->next) {
            if ((int *)c < start || (int *)c >= end)
                continue;
            if (func_004D5978(lib, c) == 0) {
                if (intr) func_00503928();
                func_004FAAA0(2);
                return 0x81050053;
            }
            func_004D55E0(c);
        }
    }
    prev = &D_0077A028.anchor;
    while (prev->next != 0) {
        e = prev->next;
        if ((int *)e >= start && (int *)e < end) {
            e->flags &= ~4;
            func_004D55E0(e);
            t = prev->next;
            n = t->next;
            t->next = 0;
            prev->next = n;
        } else {
            prev = e;
        }
    }
    if (intr) func_00503928();
    func_004FAAA0(2);
    return 0;
}
