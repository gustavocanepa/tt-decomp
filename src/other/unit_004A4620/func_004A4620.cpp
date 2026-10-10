/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern char D_007739A0[];

extern "C" s32 func_004A4530(void);
extern "C" void *func_004ADFA0(void *heap, s32 size, s32 align);

extern "C" void *func_004A4620(s32 n) {
    return func_004ADFA0(D_007739A0, func_004A4530() - n, 0x10);
}
