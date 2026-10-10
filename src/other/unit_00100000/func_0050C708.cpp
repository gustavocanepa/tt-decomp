struct Node { int a; void *b; };
extern char D_005DB750[];

extern "C" void func_0050C708(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = D_005DB750;
    }
}
