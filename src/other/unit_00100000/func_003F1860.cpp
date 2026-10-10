typedef int s32;

struct Obj {
    s32 unk0;
    void *data;
};

extern "C" s32 func_003F1700(Obj *self);

extern "C" s32 func_003F1860(Obj *self, s32 i) {
    if (self->data == 0) {
        return 0;
    }
    if (i < 0) {
        return 0;
    }
    return i < func_003F1700(self);
}
