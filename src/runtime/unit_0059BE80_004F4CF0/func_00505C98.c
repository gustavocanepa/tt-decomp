/* compiler: ee-gcc2.9-991111 */
extern void func_004FAC50(int, void *);
void func_00505C98(int a, int b, int c) {
    int buf[8];
    buf[1] = b;
    buf[0] = a & 0xff;
    buf[2] = c;
    func_004FAC50(0x20, buf);
}
