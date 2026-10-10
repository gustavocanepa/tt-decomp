struct Node;
extern "C" Node *func_00206DF8(Node *n);
extern "C" void func_0027B848(void *self, void *pos, Node *first, Node *last, int count);

extern "C" void func_0027B928(void *self, void *pos, Node *first, Node *last) {
    int count = 0;
    for (Node *p = first; p != last; p = func_00206DF8(p))
        count++;
    return func_0027B848(self, pos, first, last, count);
}
