/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
extern "C" s32 func_002F04D8(void *, s32);
extern "C" void func_00385B40(void *);
extern "C" u32 func_00388EF0();
extern "C" u32 func_00388F00();
extern "C" s32 func_00388F10();
extern "C" void func_003C8670(void *, const char *, s32, s32);
extern "C" s32 LicenseConcourse__init(void *, void *, void *);
extern char D_005F6DB0[];
extern "C" void func_00371660(char *arg0) {
    u32 temp_s0;
    char *temp_s0_2;
    char *temp_v1;
    temp_s0 = func_00388F00();
    if (func_00388EF0() < temp_s0) {
        temp_v1 = *(char **)(arg0 + 0x70);
        if (*(s32 *)(temp_v1 + 0x23968) < 2) {
            temp_s0_2 = arg0 + 0x3A8C0;
            func_002F04D8(temp_v1, 0);
            if (*(s32 *)temp_s0_2 == 0) {
                func_003C8670(temp_s0_2, D_005F6DB0, func_00388F10(), 0x96000);
                func_00385B40(temp_s0_2);
            }
        }
    }
    char *p = arg0 + 0x3A8C0;
    if (*(s32 *)p != 0) {
        LicenseConcourse__init(p, *(void **)(arg0 + 0x70), *(void **)(*(char **)(arg0 + 0x6C) + 0x80));
    }
}
