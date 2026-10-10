typedef int s32;

struct Obj {
    char pad[0x44];
    s32 index;
};

extern s32 D_00585708[5];

extern "C" s32 func_003FF5C0(Obj *self) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (self->index == i)
            return D_00585708[i];
    }
    return 0;
}
