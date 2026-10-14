typedef float f32;

struct Elem {
    int unk0;
    f32 unk4;
};

extern "C" void func_00418090(char *arg0, int arg1, f32 fparg0) {
    arg1 = arg1 + 0xA4;
    arg0 = arg0 + arg1 * 4;
    ((Elem *)arg0)->unk4 = fparg0;
}
