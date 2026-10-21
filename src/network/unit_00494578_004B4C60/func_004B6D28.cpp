/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { char b[0x800]; };
extern Block D_00774B00;
extern "C" signed char *func_004B6AD8(signed char *) throw();
extern "C" Block *func_004B67D8(int, int) throw();
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" int func_004F7958(const void *, const void *);
extern "C" unsigned char *func_004B6D28(signed char *name, int sector) {
    unsigned char *base = (unsigned char *)&D_00774B00;
    unsigned char *end = base + 0x800;
    unsigned char *cur = base;
    name = func_004B6AD8(name);
    for (;;) {
        *(Block *)base = *func_004B67D8(sector, 1);
        unsigned char *prev = cur;
        while (cur < end) {
            if (func_004F7958(name, cur + 0x21) == 0) return cur;
            if (*cur == 0) return 0;
            prev = cur;
            cur = prev + *prev;
        }
        unsigned size = prev - end;
        ++sector;
        cur = base - size;
        func_004F64C4(cur, prev, size);
    }
}
