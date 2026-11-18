/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Base { virtual ~Base(); };
struct Item : Base { char pad[0xA4]; virtual ~Item(); };
struct Items { Item array[2]; ~Items() {} };
struct Handle { int a, b; };
struct Handles { Handle array[2]; };
struct Node { Node *next; Handle *value; };
struct Nodes { Node array[2]; };
struct Ids { int array[2]; };
extern Items D_00598688;
extern Handles D_007772E0;
extern Nodes D_007772F0;
extern Ids D_00598680;
extern Node *D_005DB0F8;
extern "C" void func_004BFC18(Item *, int) throw();
extern "C" void *func_004C9E18(Handle *, int, Item *);
extern "C" void func_004C9E28(Handle *, int);
static inline void link(Node *p, Handle *value) {
    p->next = D_005DB0F8;
    p->value = value;
    D_005DB0F8 = p;
}
extern "C" void func_004C0130(int init, int prio) {
    if (prio == 0xFFFF && init == 1) {
        func_004BFC18(&D_00598688.array[0], 0);
        func_004BFC18(&D_00598688.array[1], 1);
    }
    if (prio == 0xFFFF && init == 1) {
        func_004C9E18(&D_007772E0.array[0], D_00598680.array[0], &D_00598688.array[0]);
        func_004C9E18(&D_007772E0.array[1], D_00598680.array[1], &D_00598688.array[1]);
    }
    if (prio == 0xFFFF && init == 1) {
        Node *nodes = D_007772F0.array;
        Node *n = nodes;
        link(n, &D_007772E0.array[0]);
        n++;
        link(n, &D_007772E0.array[1]);
    }
    if (prio == 0xFFFF && init == 0) {
        if (D_007772E0.array) {
            Handle *q = D_007772E0.array + 2;
            while (q != D_007772E0.array) {
                --q;
                func_004C9E28(q, 2);
            }
        }
    }
    if (prio == 0xFFFF && init == 0)
        D_00598688.~Items();
}
