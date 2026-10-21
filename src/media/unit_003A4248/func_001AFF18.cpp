typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x2B];
    u8 unk2B;
};

extern "C" void func_004F8588(void *arg0, s32 arg1, s32 arg2);

extern "C" void func_001AFF18(Obj *arg0, s32 arg1) {
    func_004F8588((char *)arg0 + 0x1C, arg1, 0x10);
    arg0->unk2B = 0;
}
