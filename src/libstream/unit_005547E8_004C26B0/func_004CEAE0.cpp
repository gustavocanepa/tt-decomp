struct Src {
    char pad[0x58];
    int id;
    int handle;
};

struct Obj {
    int m0;
    Obj *self;
    char pad[0x54];
    int sema;
    int ready;
    int id;
};

extern "C" void func_004CE708(void);
extern "C" void func_004C1938(int handle, Src *src, void (*cb)(void));
extern "C" int func_004F4138(int a, int b);

extern "C" void func_004CEAE0(Obj *o, Src *src)
{
    int id = src->id;
    if (o->ready == 0) {
        func_004C1938(src->handle, src, func_004CE708);
        o->m0 = 0;
        o->self = o;
        o->sema = func_004F4138(1, 1);
        o->id = id;
        o->ready = 1;
    }
}
