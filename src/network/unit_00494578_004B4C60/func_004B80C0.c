struct E { char pad[0x70]; int f; char pad2[0x1BC - 0x74]; };
extern struct E *D_0059834C;
int func_004B80C0(int i) {
    if (i < 2) return D_0059834C[i].f;
    return 0;
}
