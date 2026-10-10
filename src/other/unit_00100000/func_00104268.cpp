typedef int s32;

struct Obj {
    char pad[0x54];
    s32 unk40;
};

extern "C" s32 func_00104268(Obj *arg0) {
    return (arg0->unk40 != 0) ? 1 : -1;
}
