struct Mgr {
    char pad0[0x10];
    int sema;
};

struct Node {
    Node *next;
};

struct Obj {
    int pad0[2];
    Node *first;
};

extern Mgr *D_0061B704;
extern int D_00582AAC;
extern int D_00582AB0;

extern "C" void ModelSet2__begin(int sema, int a);
extern "C" void ModelSet2__end(int sema);
extern "C" void func_002E0580(Node *n);

extern "C" void func_002E0E90(Obj *o) {
    if (D_0061B704) {
        D_00582AAC = -1;
        D_00582AB0 = -1;
        ModelSet2__begin(D_0061B704->sema, 0);
        for (Node *n = o->first; n; n = n->next)
            func_002E0580(n);
        ModelSet2__end(D_0061B704->sema);
    }
}
