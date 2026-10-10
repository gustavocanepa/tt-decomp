typedef int s32;

extern "C" s32 func_003FA0C8();
extern "C" void func_003F5B30(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_003FA128(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003F5B30(func_003FA0C8(), arg2, arg3);
}
