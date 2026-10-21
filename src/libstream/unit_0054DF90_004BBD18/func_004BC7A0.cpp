/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int data[0x94 / 4]; };
struct Obj { char pad[0x198]; Block current; Block pending; };
extern int D_005A07FC;
extern "C" int func_004FA860(int);
extern "C" void func_004FA840(int);
extern "C" void func_004BC7A0(Obj *o) {
    func_004FA860(D_005A07FC);
    o->current = o->pending;
    o->pending.data[0] = 0;
    func_004FA840(D_005A07FC);
}
