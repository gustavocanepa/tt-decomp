typedef int s32;

struct Obj {
    char pad0[8];
    s32 unk8;
};

extern "C" s32 func_00418C68(s32 arg0);

extern "C" s32 func_00566900(Obj *arg0)
{
    return func_00418C68(arg0->unk8);
}
