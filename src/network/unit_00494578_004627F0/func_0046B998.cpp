/* compiler: ee-gcc2.96-nsa-g */
typedef unsigned long u64;
struct G { u64 f0; u64 f8; u64 f10; unsigned short h18; char pad1a[2]; unsigned char b1c; char pad1d[0x60 - 0x1D]; unsigned char b60; };
extern G D_00587180;
#define CLR(x, m) do { (x) &= ~(m); } while (0)
extern "C" void func_0046B998(unsigned int a0) {
    G *g = &D_00587180;
    switch (a0) {
    case 0x1000: g->b1c = 0; return;
    case 0x1001: g->b60 = 0; return;
    case 0x1100: CLR(g->h18, 0x8); return;
    case 0x1101: CLR(g->h18, 0x10); return;
    case 0x1102: CLR(g->h18, 0x20); return;
    case 0x1103: CLR(g->h18, 0x40); return;
    case 0x1104: CLR(g->h18, 0x80); return;
    case 0x1105: CLR(g->f0, 0x1800000000UL); return;
    case 0x1106: CLR(g->f8, 0x20UL); return;
    case 0x1107: CLR(g->f8, 0x1C0UL); return;
    case 0x1108: CLR(g->f10, 0xFFFFF3UL); return;
    case 0x1109: CLR(g->f10, 0xFFFFF00000CUL); return;
    }
}
