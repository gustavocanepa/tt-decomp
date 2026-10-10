typedef int s32;
typedef unsigned long long u64;

struct Obj { char pad[0xAC]; s32 unk98; };

extern "C" u64 func_0020D928(Obj *arg0) {
    u64 v = arg0->unk98;
    v = v >> 2;
    return v & 1;
}
