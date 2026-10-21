/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern s32 D_005A30C8;
extern char D_0078C100[];

/* Caller sets both $a0 (buffer) and $a1 (count) before each call. */
extern "C" void func_00505DE0(char *p, s32 n);

extern "C" void func_004FC080(s32 arg0) {
    s32 n = D_005A30C8;
    if (n >= 0x7E) {
        D_005A30C8 = 0;
        D_0078C100[0x7F] = 0;
        func_00505DE0(D_0078C100, n);
        n = D_005A30C8;
    }
    if (arg0 == 0xA) {
        D_005A30C8 = 0;
        D_0078C100[n] = (char)arg0;
        D_0078C100[n + 1] = 0;
        func_00505DE0(D_0078C100, n);
        return;
    }
    D_005A30C8 = n + 1;
    D_0078C100[n] = (char)arg0;
}
