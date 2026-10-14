typedef int s32;

extern char D_005F7BE8[];
extern char D_005F7BF0[];

extern "C" s32 pdiRiderman__Skeleton__getBoneIndex(s32 arg0);
extern "C" s32 func_004A8268(void *arg0, s32 arg1);

extern "C" void *func_003949B8(char *arg0, s32 arg1) {
    s32 temp = pdiRiderman__Skeleton__getBoneIndex(arg1);
    char *var = arg0 + (temp << 6) + 0x544;
    if (temp >= 0) {
        return var;
    }
    if (arg1 == 0) {
        return 0;
    }
    void *a = *(void **)(arg0 + 0xA98);
    if (a != 0) {
        if (func_004A8268(a, arg1) == 0) {
            return arg0 + 0xA44;
        }
    }
    if (func_004A8268(D_005F7BE8, arg1) == 0) {
        return *(void **)(arg0 + 0xA84);
    }
    if (func_004A8268(D_005F7BF0, arg1) == 0) {
        return *(void **)(arg0 + 0xA88);
    }
    return 0;
}
