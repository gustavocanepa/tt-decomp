typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
};

extern "C" s32 func_005038D8();

extern "C" void func_004A4930(Obj *arg0) {
    s32 temp_a0 = func_005038D8();
    s32 temp_v0 = arg0->unk0 + 1;
    arg0->unk0 = temp_v0;
    if (temp_v0 == 1) {
        arg0->unk4 = temp_a0;
    }
}
