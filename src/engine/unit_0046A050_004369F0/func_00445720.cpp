struct Elem { int a, b; };
extern "C" void func_00445628(void *ctx);
extern "C" void func_00445838(Elem *e, void *ctx);
struct Array {
    Elem *data;
    int count;
    Elem *begin() { return data; }
    Elem *end() { return data + count; }
    void visit(void *ctx)
    {
        Elem *last = end();
        for (Elem *e = begin(); e != last; e++)
            func_00445838(e, ctx);
    }
};
struct Obj {
    char pad[0x10];
    Array arr;
};

extern "C" void func_00445720(Obj *o, void *ctx)
{
    func_00445628(ctx);
    o->arr.visit(ctx);
}
