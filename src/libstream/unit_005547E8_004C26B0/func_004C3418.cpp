/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Static initialization of this unit's stream D_0088D948, written like func_005522F0 (same template): two items
   constructed by func_004CAC08, two stream handles opened on them through func_004C9E18
   and linked into the global handle list (D_005DB0F8); destruction closes the handles in reverse
   order (func_004C9E28) and runs the items' virtual destructors. */
struct Base { virtual ~Base(); };
struct Item : Base { char pad[0x8]; virtual ~Item(); };
struct Items { Item array[2]; ~Items() {} };
struct Handle { int a, b; };
struct Handles { Handle array[2]; };
struct Node { Node *next; Handle *value; };
struct Nodes { Node array[2]; };
struct Ids { int array[2]; };
extern Items D_00598F00;
extern Handles D_00779660;
extern Nodes D_00779670;
extern Ids D_00598EF8;
extern Node *D_005DB0F8;
struct Src { char b[0x14]; };
struct Srcs { Src array[2]; };
extern Srcs D_005A0868;
extern char D_00613548[];
extern "C" void func_004CAC08(Item *, Src *, void *) throw();
extern "C" void *func_004C9E18(Handle *, int, Item *);
extern "C" void func_004C9E28(Handle *, int);
static inline void link(Node *p, Handle *value) {
    p->next = D_005DB0F8;
    p->value = value;
    D_005DB0F8 = p;
}
extern "C" void func_004C3418(int init, int prio) {
    if (prio == 0xFFFF && init == 1) {
        func_004CAC08(&D_00598F00.array[0], &D_005A0868.array[0], D_00613548);
        func_004CAC08(&D_00598F00.array[1], &D_005A0868.array[1], D_00613548);
    }
    if (prio == 0xFFFF && init == 1) {
        func_004C9E18(&D_00779660.array[0], D_00598EF8.array[0], &D_00598F00.array[0]);
        func_004C9E18(&D_00779660.array[1], D_00598EF8.array[1], &D_00598F00.array[1]);
    }
    if (prio == 0xFFFF && init == 1) {
        Node *nodes = D_00779670.array;
        Node *n = nodes;
        link(n, &D_00779660.array[0]);
        n++;
        link(n, &D_00779660.array[1]);
    }
    if (prio == 0xFFFF && init == 0) {
        if (D_00779660.array) {
            Handle *q = D_00779660.array + 2;
            while (q != D_00779660.array) {
                --q;
                func_004C9E28(q, 2);
            }
        }
    }
    if (prio == 0xFFFF && init == 0)
        D_00598F00.~Items();
}
