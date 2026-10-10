typedef int s32;

struct SomeStruct {
    char pad[0x1C];
    s32 unk1C;
};

extern void func_004672F8(s32);

void func_00418FA0(struct SomeStruct *arg0) {
    s32 temp_v0;

    if (arg0 != 0) {
        temp_v0 = arg0->unk1C;
        if (temp_v0 != 0) {
            func_004672F8(temp_v0);
        }
    }
}
