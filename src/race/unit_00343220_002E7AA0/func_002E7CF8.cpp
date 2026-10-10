struct BitReader;
extern "C" long func_004B2CE0(BitReader *r, int bits);
extern int D_00582D20[];

extern "C" int func_002E7CF8(BitReader *r) {
    int n = func_004B2CE0(r, 3);
    int neg = func_004B2CE0(r, 1);
    int v = func_004B2CE0(r, n * 2 + 1) + D_00582D20[n];
    return neg ? -v : v;
}
