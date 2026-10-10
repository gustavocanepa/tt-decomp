typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern char D_005F9398[];

extern "C" s32 func_004A8268(const char *a, const char *b);

extern "C" void func_003F23F8(Obj *self, const char *name) {
    if (func_004A8268(name, D_005F9398) == 0) {
        self->unk8 = 1;
        self->unk0 = 1;
    }
}
