struct Node {
    int type;
    int value;
};

extern "C" void func_0043D8E8(Node *n, int value);
extern "C" void func_0043DCB8(Node *n, int value);
extern "C" int strobe__Any__toString(Node *n);
extern "C" void func_0043D6E8(Node *n, int value);

extern "C" void func_0043D438(Node *n) {
    if (n->type == 13)
        return func_0043D8E8(n, n->value);
    if (n->type == 7)
        return func_0043DCB8(n, n->value);
    if (n->type == 3)
        func_0043D6E8(n, strobe__Any__toString(n));
}
