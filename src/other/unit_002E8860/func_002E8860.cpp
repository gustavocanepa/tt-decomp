struct Obj {
    int f0;
    int busy;
    char buf[0x5C - 8];
    int mode;
};

extern "C" char *D_00582D44;
extern "C" void func_002E7B48(void *buf, int mode, char *end);
extern "C" void func_002E88B0(Obj *o, int arg);

extern "C" void func_002E8860(Obj *o, int mode) {
    o->mode = mode;
    if (o->busy == 0) {
        return func_002E7B48(o->buf, mode, D_00582D44 - 8);
    }
    func_002E88B0(o, 0);
}
