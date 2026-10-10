typedef int s32;

struct Obj {
    char pad[0x28];
    s32 unk28;
};

extern "C" void func_004A45D0(s32 arg0);

extern "C" void func_001CF7B0(Obj *arg0) {
    s32 temp_v0 = arg0->unk28;

    if (temp_v0 != 0) {
        arg0->unk28 = 0;
        func_004A45D0(temp_v0);
    }
}
