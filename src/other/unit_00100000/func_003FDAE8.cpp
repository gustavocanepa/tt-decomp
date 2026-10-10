typedef int s32;

extern char D_007695D0[];

struct Obj {
    char pad[4420];
    s32 unk4;
};

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FDAE8(struct Obj *arg0) {
    func_004AC378(D_007695D0, arg0->unk4);
}
