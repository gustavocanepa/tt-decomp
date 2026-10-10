struct Node { int a; void *b; int c; };
extern char D_005DB868[];
void func_0050D9F8(struct Node *n, int a, int c)
{
    if (n) {
        n->a = a;
        n->b = D_005DB868;
        n->c = c;
    }
}
