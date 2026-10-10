typedef struct Node {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    struct Node *next;
} Node;

extern "C" int D_005A319C;
extern "C" Node *D_00793388;
extern "C" int func_004FA860(int sema);
extern "C" int func_004FA840(int sema);

extern "C" void func_0050B7C8(int value, Node *n)
{
    n->m8 = value;
    n->m4 = 0;
    n->m0 = 0;
    n->mC = 0;
    n->m10 = 0;
    func_004FA860(D_005A319C);
    n->next = D_00793388;
    D_00793388 = n;
    func_004FA840(D_005A319C);
}
