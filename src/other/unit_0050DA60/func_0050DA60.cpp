struct Node { int a; void *b; };
extern char D_005DB808[];

extern "C" void func_0050DA60(struct Node *n, int a)
{
    if (n) {
        n->a = a;
        n->b = D_005DB808;
    }
}
