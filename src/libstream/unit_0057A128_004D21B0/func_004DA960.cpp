/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern char D_005A0BD0[];
extern "C" void func_004DA8F0(void);

extern "C" s32 func_004DA960(void) {
    char *p = D_005A0BD0;
    if (p[0] == 0) func_004DA8F0();
    return p[4] == 'T';
}
