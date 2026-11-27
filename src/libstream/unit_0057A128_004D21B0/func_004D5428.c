/* compiler: ee-gcc2.9-991111 */
int func_004D5718(void *);
/* Preserve full registers, as in the neighbouring SDK dispatcher. */
int func_004D5428(char *, unsigned int)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));
int func_004D5428(char *p, unsigned int size) {
    unsigned int n = size >> 2;
    while ((int)n > 0) {
        if (func_004D5718(p) < 0) return 0x81059039;
        n -= 8;
        if (!(*(unsigned short *)(p+0x16) & 2)) return 0x81059037;
        p += 0x20;
    }
    return 0;
}
