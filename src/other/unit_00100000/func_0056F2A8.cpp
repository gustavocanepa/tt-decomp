struct D_Node {
    char pad[8];
    D_Node *next;
    D_Node *child;
};

extern "C" void func_004A45D0(void *);

extern "C" void func_0056F2A8(int arg0, D_Node *node) {
    if (node) {
        do {
            func_0056F2A8(arg0, node->child);
            D_Node *next = node->next;
            func_004A45D0(node);
            node = next;
        } while (node);
    }
}
