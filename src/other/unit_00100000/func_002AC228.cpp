typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" void func_002ACA68(struct Obj *arg0);

extern "C" void func_002AC228(struct Obj *arg0)
{
    char unused[0x10];
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    func_002ACA68(arg0);
}
