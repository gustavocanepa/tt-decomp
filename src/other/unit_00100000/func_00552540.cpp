/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

extern "C" void func_002E8088(void *, int);

extern "C" void func_00552540(void *self, u8 *cur, u8 *next) {
    func_002E8088(self, *next - *cur);
    *cur = *next;
}
