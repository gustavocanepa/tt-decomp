/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot { int state; char pad[0x418]; };
struct Obj { char pad0[0x24]; Slot slots[2]; int cur; int unk85c; int done; };
extern "C" void func_00484DB8(Obj *) throw();
extern "C" void func_00482A80(Obj *, int) throw();
extern "C" int func_00485310(Obj *arg0) {
    if (arg0->done) return 1;
    Slot *s = &arg0->slots[1 - arg0->cur];
    switch (s->state) {
    case 0: return 0;
    case 1:
        func_00484DB8(arg0);
        return 1;
    case 2:
        func_00482A80(arg0, -1);
        return 1;
    }
    return 1;
}
