typedef int s32;

struct Obj {
    char pad[0x10F8];
    s32 unk10F8;
};

extern char D_00769598[];

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FD318(struct Obj *arg0) {
    func_004AC378(D_00769598, arg0->unk10F8);
}
