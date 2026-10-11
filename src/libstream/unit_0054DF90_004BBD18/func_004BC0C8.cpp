struct Obj {
    char pad0[0x3E8];
    int stream;
    char pad3EC[0x10];
    int thread;
    int sema;
};

extern "C" int func_004FA860(int sema);
extern "C" int func_004FA840(int sema);
extern "C" int func_004FA750(int thread);
extern "C" unsigned int func_004BDC58(int stream);
extern "C" unsigned int func_004BDC48(void);

extern "C" void func_004BC0C8(Obj *o) {
    func_004FA860(o->sema);
    if (o->thread != -1) {
        unsigned int used = func_004BDC58(o->stream);
        int pct = used * 10 / func_004BDC48();
        if (pct >= 9) {
            func_004FA750(o->thread);
            o->thread = -1;
        }
    }
    func_004FA840(o->sema);
}
