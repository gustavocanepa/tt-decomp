typedef int s32;
typedef float f32;

struct Elem {
    char pad[0x4];
    f32 unk4;
};

extern "C" void func_004183C8(char *arg0, s32 arg1, s32 arg2, f32 fparg0) {
    s32 index = (arg1 == 0) ? 0 : 0x10;
    Elem *entry = (Elem *)(arg0 + (index + arg2) * 4);
    entry->unk4 = fparg0;
}
