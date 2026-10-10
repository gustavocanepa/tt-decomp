typedef int s32;

struct Elem {
    s32 unk0;
    s32 unk4;
};

extern Elem D_00779F84[];

extern "C" s32 func_004CC818(s32 arg0) {
    return D_00779F84[arg0].unk0;
}
