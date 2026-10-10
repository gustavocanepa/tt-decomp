typedef int s32;

struct Obj {
    char pad[0x28];
    s32 unk68;
};

extern "C" void func_0038E3A0(Obj *arg0);

extern "C" void func_0035A058(Obj *arg0) {
    arg0->unk68 = 0;
    func_0038E3A0(arg0);
}
