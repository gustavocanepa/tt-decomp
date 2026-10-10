typedef int s32;
typedef signed char s8;

struct Struct_002A39F0 {
    char pad[0x8];
    s32 unk8;
    s32 unkC;
};

extern "C" void func_001DC258(Struct_002A39F0 *arg0, s32 arg1, s32 arg2);

extern "C" void func_001DC578(Struct_002A39F0 *arg0) {
    func_001DC258(arg0, arg0->unk8, arg0->unkC);
}
