struct Obj {
    char pad0[0x166];
    unsigned char flag;
};

extern "C" void func_0040BE90(Obj *o, long a);
extern "C" void func_0040D3D8(Obj *o, int b);

extern "C" void func_0037B028(Obj *o, long a, int b, int flag) {
    func_0040BE90(o, a);
    func_0040D3D8(o, b);
    o->flag = flag;
}
