/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int pad[4]; Node *next; };
struct List { int count; int pad[4]; Node *head; };
extern "C" int func_003A7FE8(Node *) throw();

extern "C" Node *func_003A8010(List *l, Node *cur)
{
    int n = l->count;
    Node *p = cur;
    for (int i = 0; i < n; i++) {
        p = p->next;
        if (!p) p = l->head;
        if (p && func_003A7FE8(p)) return p;
    }
    return cur;
}
