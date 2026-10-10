struct func_0047CA58 { char pad0[0xC]; int mC; char pad10[0x94]; func_0047CA58(); virtual ~func_0047CA58(); };
extern char D_00605A28[];
struct D_005DA818 : func_0047CA58 { const char *name; int mAC; D_005DA818(const char *name, int b, int c); virtual ~D_005DA818(); };
D_005DA818::D_005DA818(const char *n, int b, int c) : name(n ? n : D_00605A28), mAC(b) {
    mC = c;
}
