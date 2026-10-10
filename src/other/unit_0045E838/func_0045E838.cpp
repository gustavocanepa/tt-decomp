typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" void func_0045E7F8(Obj *arg0);

extern "C" void func_0045E838(Obj *arg0) {
    s32 count = arg0->unk8;
    if (count > 0) {
        s32 i = count;
        do {
            i--;
            func_0045E7F8(arg0);
        } while (i != 0);
    }
}
