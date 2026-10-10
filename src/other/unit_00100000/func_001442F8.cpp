typedef int s32;

struct S00430830;

struct Inner {
    char pad0[0x1D0];
    char mD8[4];
};

struct H {
    char pad0[0x10];
    Inner *p10;
};

extern "C" void func_00141F98(void *arg0, int arg1);
extern "C" void *func_00141FF0(void *arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" s32 func_003F80E0(S00430830 *arg0);

static inline H *get(H **p) {
    return *p;
}

extern "C" void func_001442F8(s32 *arg0) {
    H *tmp[4];
    s32 buf0[4];
    s32 *pb;
    s32 v;
    s32 newVal;
    s32 oldVal;
    func_00141FF0(tmp);
    v = func_003F80E0((S00430830 *)get(tmp)->p10->mD8);
    pb = buf0;
    func_0029EA18(pb, v);
    if (arg0 != pb) {
        newVal = *pb;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(pb, 2);
    func_00141F98(tmp, 2);
}
