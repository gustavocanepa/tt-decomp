typedef int s32;
struct Obj;

extern "C" void func_003FDC30(struct Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_00562CE8(struct Obj *arg0, s32 arg1) {
    func_003FDC30(arg0, 0x200, arg1);
}
