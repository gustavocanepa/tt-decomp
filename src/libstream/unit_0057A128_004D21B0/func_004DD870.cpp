/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
extern const char *D_005A0D20[];
extern u8 D_00614868;
extern "C" char *func_004F7B74(char *, const char *);
extern "C" void func_004DD870(unsigned idx, u8 *out) {
    if (idx < 4) {
        func_004F7B74((char *)out, D_005A0D20[idx]);
        return;
    }
    *out = D_00614868;
}
