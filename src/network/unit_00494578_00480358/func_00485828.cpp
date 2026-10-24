/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Slot { s32 state; s32 unk4; char pad[0x41C - 8]; };
struct Obj {
    char pad0[0x24];
    Slot slots[2];
    char pad[0x85C - 0x24 - 0x41C * 2];
    s32 cur;
    char pad85C[4];
    s32 unk860;
};
extern "C" void func_00482CC8(Obj *) throw();
extern "C" void func_00482DA0(Obj *) throw();
extern "C" s32 func_00485828(Obj *arg0) {
    if (arg0->unk860 != 0) return 1;
    Slot *s = &arg0->slots[1 - arg0->cur];
    switch (s->state) {
    case 0:
        return 0;
    case 1:
        s->unk4 = 4;
        func_00482CC8(arg0);
        s->state = 2;
        return 1;
    case 2:
        func_00482DA0(arg0);
        s->unk4 = 4;
        func_00482CC8(arg0);
        return 1;
    }
    return 1;
}
