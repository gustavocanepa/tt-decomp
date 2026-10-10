typedef int s32;

struct Obj {
    char pad0[0x48];
    s32 unk48;
    s32 unk4C;
};

extern "C" void func_004F64C4(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_002E7BB8(Obj *arg0, Obj *arg1)
{
    func_004F64C4(arg0->unk48, arg1->unk48, arg1->unk4C);
}
