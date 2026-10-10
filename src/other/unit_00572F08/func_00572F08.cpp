typedef int s32;

struct Obj { void *f0; char pad4[0x3C]; char *f40; char pad44[0x3C]; char buf[1]; };
extern "C" void func_004F4348(void *);
extern "C" void func_004F45D8(struct Obj *, s32, s32, s32, s32);

extern "C" void func_00572F08(struct Obj *o) {
    func_004F4348(o->f0);
    o->f40 = o->buf;
    func_004F45D8(o, 0, 0, 0, 0);
}
