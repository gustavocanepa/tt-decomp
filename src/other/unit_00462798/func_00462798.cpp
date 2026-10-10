typedef int s32;

struct Obj00494520 {
    char pad[0x98C];
    void *unk98C;
};

extern char D_005DA2C8[];
extern "C" s32 func_004627F0(struct Obj00494520 *arg0);

extern "C" s32 func_00462798(struct Obj00494520 *arg0) {
    arg0->unk98C = D_005DA2C8;
    return func_004627F0(arg0);
}
