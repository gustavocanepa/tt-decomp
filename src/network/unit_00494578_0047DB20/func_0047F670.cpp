struct Obj {
    char pad[0x30];
    void *m30;
    int m34;
    int m38;
};
extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);
extern "C" void func_0047A0B8(void *p);
extern "C" char D_0076FC90[];

extern "C" void func_0047F670(Obj *o)
{
    void *p = 0;
    func_004A4930(D_0076FC90);
    if (o->m38) {
        p = o->m30;
        o->m38 = 0;
        o->m30 = 0;
    }
    func_004A4970(D_0076FC90);
    if (p)
        func_0047A0B8(p);
}
