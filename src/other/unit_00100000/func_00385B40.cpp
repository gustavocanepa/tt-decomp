typedef int s32;

struct SomeStruct {
    char pad[4];
    s32 unk4;
};

extern void func_00385A70(s32);

extern "C" void func_00385B40(struct SomeStruct *arg0) {
    s32 temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        func_00385A70(temp_v0);
    }
}
