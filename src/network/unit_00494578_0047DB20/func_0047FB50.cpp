typedef int s32;

struct Obj {
    char pad[0x1A80];
    s32 unk3290;
};

extern "C" void func_0047FF88(struct Obj *arg0);

extern "C" void func_0047FB50(struct Obj *arg0) {
    arg0->unk3290 = 1;
    func_0047FF88(arg0);
}
