typedef int s32;

struct Obj {
    char pad[0x1A20];
    s32 unk1AA0;
};

extern "C" void func_002E8DD0(s32 arg0, struct Obj *arg1, s32 arg2);

extern "C" void func_0037AC70(s32 arg0, struct Obj *arg1) {
    arg1->unk1AA0 = 1;
    func_002E8DD0(arg0 + 0x13AE0, arg1, 1);
}
