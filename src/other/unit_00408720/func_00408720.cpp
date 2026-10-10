typedef int s32;

extern "C" s32 func_00408750(s32 arg0, s32 arg1);
extern "C" s32 func_0040FB40(s32 arg0);

extern "C" s32 func_00408720(s32 arg0, s32 arg1) {
    return func_00408750(arg0, func_0040FB40(arg1));
}
