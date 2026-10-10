struct Node {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    Node *next;
};

extern int D_005A319C;
extern Node *D_00793388;

extern "C" int func_004FA860(int sema);
extern "C" void func_004FA840(int sema);

extern "C" void func_0050B860(int v, Node *n) {
    int *sema = &D_005A319C;
    n->m8 = v;
    n->m4 = 0;
    n->m0 = 0;
    n->mC = v;
    n->m10 = 0;
    func_004FA860(*sema);
    n->next = D_00793388;
    D_00793388 = n;
    func_004FA840(*sema);
}
