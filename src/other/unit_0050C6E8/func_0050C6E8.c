struct Node { int a; void *b; int c; };
extern char D_005DB720[];
void func_0050C6E8(struct Node *n, int a, int c)
{
    if (n) {
        n->a = a;
        n->b = D_005DB720;
        n->c = c;
    }
}
