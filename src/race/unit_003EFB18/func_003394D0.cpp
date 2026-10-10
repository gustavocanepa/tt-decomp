typedef int s32;

struct Obj;

extern "C" void RaceBasic__cleanup(Obj *arg0);
extern "C" void func_0033DF60(Obj *arg0, s32 arg1);
extern "C" void func_0033E078(Obj *arg0, s32 arg1);
extern "C" void func_0033E130(Obj *arg0, s32 arg1);
extern "C" void func_0033E230(Obj *arg0, s32 arg1);
extern "C" void func_0033E250(Obj *arg0, s32 arg1);

extern "C" void func_003394D0(Obj *arg0) {
    Obj *s0 = arg0;
    RaceBasic__cleanup(arg0);
    func_0033DF60(s0, 0);
    func_0033E078(s0, 0);
    func_0033E250(s0, 0);
    func_0033E130(s0, 0);
    func_0033E230(s0, 0);
}
