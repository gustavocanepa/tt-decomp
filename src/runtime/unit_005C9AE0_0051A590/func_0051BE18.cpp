typedef int s32;

struct Obj;

struct S005CBC98 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_003FF600(Obj *arg0);

extern "C" void func_0051BE18(struct S005CBC98 *arg0) {
    func_003FF600((Obj *)(arg0->unk10 + 0x13AC));
}
