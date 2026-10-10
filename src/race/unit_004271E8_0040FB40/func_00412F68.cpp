struct Pool {
    int size;
    int count;
    int stride;
    void *mem;
};

extern "C" void *func_004A45F8(int bytes);
extern "C" void func_00413010(Pool *p);

extern "C" void func_00412F68(Pool *p, int size, int count) {
    if (p->mem == 0) {
        int stride = size / 8 * 8 + 0x18;
        p->stride = stride;
        p->mem = func_004A45F8(stride * count);
        p->size = size;
        p->count = count;
    }
    func_00413010(p);
}
