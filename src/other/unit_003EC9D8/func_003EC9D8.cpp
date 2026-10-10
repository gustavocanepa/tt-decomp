typedef int s32;

extern "C" s32 func_0028F650(s32 *arg0, const char *arg1);

extern "C" s32 func_003EC9D8(void) {
    s32 local;
    s32 result = func_0028F650(&local, "DemonstrationSlideNum");
    return (result == 0) ? 0 : local;
}
