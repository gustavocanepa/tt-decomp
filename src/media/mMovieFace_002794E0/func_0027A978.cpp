typedef int s32;

struct S {
    char p0[0xE0];
    s32 fBC;
};

extern "C" void func_00279ED8(S *self);
extern "C" void func_0027AAB0(S *self, s32 oldIndex, s32 newIndex);
extern "C" void func_004AC580(s32 *arg0, s32 arg1);

extern "C" void func_0027A978(S *arg0, s32 arg1) {
    s32 *p = &arg0->fBC;
    s32 old = *p;
    func_004AC580(p, arg1);
    func_0027AAB0(arg0, old, arg1);
    func_00279ED8(arg0);
}
