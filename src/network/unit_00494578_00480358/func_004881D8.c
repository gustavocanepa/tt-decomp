/* Stores a 32-bit value as two unaligned 16-bit halves: the high half at +0x14, the low half at
   +0x1A. The packed struct makes the compiler split each store into byte stores. */
struct UnalignedU16 {
    unsigned short v;
} __attribute__((packed));

static inline void put_u16(void *p, int v)
{
    ((struct UnalignedU16 *)p)->v = v;
}

void func_004881D8(char *obj, int v)
{
    put_u16(obj + 0x14, v >> 16);
    put_u16(obj + 0x1a, (unsigned short)v);
}
