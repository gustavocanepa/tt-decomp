typedef int s32;

struct S003B7068 {
    char pad[0x18];
    void *unk18;
};

extern "C" char D_005D1578[];
extern "C" s32 func_0036C2F8(S003B7068 *arg0, s32 arg1, s32 arg2);

extern "C" s32 ErrorEventView__structor_0(S003B7068 *arg0) {
    arg0->unk18 = D_005D1578;
    return func_0036C2F8(arg0, 0x64, 0x64);
}
