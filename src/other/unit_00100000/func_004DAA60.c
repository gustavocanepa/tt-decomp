/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

extern u8 D_005A0BCD;

s32 func_004DA960(void);
void func_004FA8D0(s32 *buf);

s32 func_004DAA60(void) {
    s32 buf[4];
    if (func_004DA960() != 0) {
        return D_005A0BCD;
    }
    func_004FA8D0(buf);
    return buf[0] & 1;
}
