typedef int s32;
typedef long long s64;

struct Obj_001C5220 {
    char pad[0xC];
    s32 unkC;
};

extern "C" s64 func_004B4240(Obj_001C5220 *arg0, s32 arg1);

extern "C" void func_004B42B8(Obj_001C5220 *arg0) {
    func_004B4240(arg0, arg0->unkC);
    arg0->unkC = 0;
}
