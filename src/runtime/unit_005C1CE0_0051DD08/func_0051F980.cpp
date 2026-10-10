typedef int s32;

struct Obj {
    char pad0[4];
};

typedef void (Obj::*PM)(int);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_00195E80(void *arg0, int arg1);
extern "C" void func_00195ED8(void *arg0, int arg1);

static inline Obj *hget(Handle *h) { return h->p; }

extern "C" void func_0051F980(void *arg0, s32 arg1, s32 arg2, s32 arg3, PM pmf) {
    if (arg2 > 0) {
        Handle o;
        Handle *po = &o;
        func_00195ED8(po, arg1);
        (hget(po)->*pmf)(arg3);
        func_00195E80(po, 2);
    }
}
