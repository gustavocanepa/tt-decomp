/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj;
struct Handle { Obj *p; s32 pad[3]; };
struct Store { char pad0[0x8]; Obj **data; char pad18[8]; s32 count; };
struct State { char pad0[0x2C]; Store *store; };
extern char D_0057C5F8[];
extern "C" void func_002A7A30(void *);
extern "C" void func_002A8CF8(void *, void *, const void *, s32, const void *);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" void func_002A75A8(void *, s32) throw();
extern "C" void func_002A8B48(void *self, State **arg1, s32 arg2, const void *arg3) {
    Handle h;
    func_002A7A30(&h);
    func_002A8CF8(self, &h, D_0057C5F8, arg2, arg3);
    Store *s = (*arg1)->store;
    Obj **dst = s->data + s->count;
    if (dst != (Obj **)&h) {
        Obj *p = h.p;
        if (p) func_002C0FE8(p);
        if (*dst) func_002C1050(*dst);
        *dst = p;
    }
    s->count++;
    func_002A75A8(&h, 2);
}
