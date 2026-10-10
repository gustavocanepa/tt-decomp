typedef int s32;

struct Pair {
    s32 unk0;
    s32 unk4;
};

extern Pair D_0076A008;
extern "C" void func_004A45D0(s32 arg0);

extern "C" void func_0042C148(void) {
    Pair *p = &D_0076A008;
    s32 temp_v1 = p->unk4;
    if (temp_v1 != 0) {
        func_004A45D0(temp_v1);
        p->unk4 = 0;
    }
}
