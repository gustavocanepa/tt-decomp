/* compiler: ee-gcc2.9-991111 */
extern char D_00783080[];
extern int D_005A0BF8;
unsigned int func_004A8368(const char *s);
void *memcpy(void *dst, const void *src, unsigned int n);
void func_004FA850(int sema);

#define UNCACHED(p) ((char *)((unsigned int)(p) | 0x20000000))

void func_004DBF58(char *dst) {
    if (dst) {
        unsigned int n = func_004A8368(UNCACHED(D_00783080)) < 0x400 ? func_004A8368(UNCACHED(D_00783080)) : 0x3FF;
        memcpy(dst, UNCACHED(D_00783080), n);
        dst[n] = 0;
    }
    func_004FA850(D_005A0BF8);
}
