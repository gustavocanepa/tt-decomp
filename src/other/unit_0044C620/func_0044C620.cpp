typedef int s32;

extern char D_005D9F98[];

extern "C" void *func_004AE9C0(void *self);

struct Obj {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    void *vtbl;
    Obj() __asm__("func_0044C620");
};

Obj::Obj() {
    vtbl = D_005D9F98;
    func_004AE9C0(this);
    unk30 = 0;
    unk34 = 0;
    unk38 = 0;
}
