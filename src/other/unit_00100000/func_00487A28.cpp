typedef unsigned short u16;

struct Node {
    u16 flag : 1;
};

extern "C" void func_00487640(void *, Node *, int);
extern "C" void func_00487968(void *, Node *);

extern "C" void func_00487A28(void *ctx, Node *n) {
    if (n->flag)
        func_00487640(ctx, n, 0);
    func_00487968(ctx, n);
}
