typedef int s32;
typedef float f32;
char *func_002F04D8(void *a, s32 b);
void func_003A3A90(void *a, s32 b, f32 f, s32 c, s32 d);
void func_003A4498(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 fparg0) {
    char *temp_s2;
    temp_s2 = func_002F04D8(arg0, arg1) + 0x104;
    func_003A3A90(arg0, arg1, fparg0, arg2, arg3);
    *(s32 *)(temp_s2 + 0x630) = 0;
}
