/* compiler: ee-gcc2.96-nsa-nosib */
typedef unsigned short u16;

extern void *func_004F6678(void *, int, unsigned int);
extern void *func_004F64C4(void *, const void *, unsigned int);

void func_004C99F0(void *dst, u16 *src) {
    func_004F6678(dst, 0, 0x42);
    func_004F64C4(dst, src, *src);
}
