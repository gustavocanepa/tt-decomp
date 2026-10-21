struct Obj {
    char pad[0x308];
    int handle;
};

extern "C" void *func_0020FF78(Obj *);
extern "C" int func_00210118(Obj *);
extern "C" void func_001CCF20(void *, void *, int, int, int, int);
extern "C" void func_001CE638(void *, void *);
extern "C" void func_0013C5D0(int, void *);
extern "C" void func_001CE650(void *, int);

extern "C" void func_001267A0(Obj *o, int arg) {
    void *m = func_0020FF78(o);
    int h = func_00210118(o);
    int buf[4];
    func_001CCF20(buf, m, arg, 0, 1, h);
    if (buf[0]) {
        void *out[4];
        func_001CE638(out, buf);
        func_0013C5D0(o->handle, out);
    }
    func_001CE650(buf, 2);
}
