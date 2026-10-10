struct S { int unk0; char pad4[0x34 - 4]; int unk34; };

extern "C" void func_00478310(int arg0);
extern "C" void func_0050E1A8(void *arg0);

extern "C" void func_00104868(S *arg0, int arg1) {
    if (arg0->unk34 != 0) {
        func_00478310(arg0->unk0);
    }
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
