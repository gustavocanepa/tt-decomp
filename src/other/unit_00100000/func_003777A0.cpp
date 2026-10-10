typedef int s32;

extern "C" s32 func_004A8268(s32 arg0, const char *arg1);

extern "C" s32 func_003777A0(s32 arg0) {
    return func_004A8268(arg0, "BRIGHTNESS") != 0;
}
