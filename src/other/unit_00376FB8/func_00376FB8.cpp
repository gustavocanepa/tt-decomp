typedef int s32;

struct Obj {
    char pad[0x24];
    s32 unk24;
};

extern "C" s32 func_004F7B74(char *arg0);

extern "C" void func_00376FB8(struct Obj *arg0) {
    func_004F7B74((char *)arg0 + 0x14);
    arg0->unk24 = 1;
}
