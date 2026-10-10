typedef int s32;

struct Obj {
    char pad[0xC];
    void *vtbl;
};

extern char D_005D99E8[];
extern "C" s32 func_00418A18(Obj *arg0);

extern "C" s32 func_004189C0(Obj *arg0) {
    arg0->vtbl = D_005D99E8;
    return func_00418A18(arg0);
}
