typedef int s32;

extern char D_00769588[];

struct Obj {
    char pad[4316];
    s32 unk4;
};

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FD170(struct Obj *arg0) {
    func_004AC378(D_00769588, arg0->unk4);
}
