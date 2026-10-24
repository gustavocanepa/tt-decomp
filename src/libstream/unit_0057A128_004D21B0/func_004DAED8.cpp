/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
extern "C" void func_004DAE00(void *);
extern "C" void func_004DAED8(u8 *p) {
    if (p[3] == 0) {
        p[3] = 0x17;
        func_004DAE00(p);
        return;
    }
    p[3]--;
}
