typedef int s32;
typedef float f32;

struct Elem {
    char pad[0x4];
    f32 unk4;
};

extern "C" f32 func_00418108(char *arg0, s32 arg1) {
    arg1 = arg1 + 0x5C;
    arg0 = arg0 + arg1 * 4;
    return ((Elem *)arg0)->unk4;
}
