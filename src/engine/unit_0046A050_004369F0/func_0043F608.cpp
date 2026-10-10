typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);
extern "C" void func_0043F408(Val *, s32 type);

extern "C" s32 func_0043F608(const Val *self) {
    Val tmp;
    s32 r;
    func_0043D3B8(&tmp, self);
    func_0043F408(&tmp, 10);
    r = tmp.v != 0x7F800000 && tmp.v != (s32)0xFF800000;
    func_0043D510(&tmp);
    return r;
}
