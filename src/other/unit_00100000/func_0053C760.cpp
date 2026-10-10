typedef int s32;

struct Obj {
    char pad[0x150];
    s32 unkE8;
};

extern "C" void func_0053C760(struct Obj *arg0, s32 arg1) {
    s32 temp = (s32)(arg1 != 0);
    s32 v = arg0->unkE8;
    v = v & ~0x20;
    v = v | (temp << 5);
    arg0->unkE8 = v;
}
