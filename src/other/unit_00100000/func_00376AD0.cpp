typedef int s32;

struct S;

extern "C" void func_0040CE20(S *arg0, S *arg1);

struct Inner60 {
    char pad0[8];
    S **unk8;
};

struct Obj {
    char pad0[0x60];
    Inner60 *unk60;
};

extern "C" void func_00376AD0(Obj *arg0, s32 arg1, S *arg2) {
    S *p = arg0->unk60->unk8[arg1];
    func_0040CE20((S *)((char *)p + 0xFD8), arg2);
}
