/* compiler: ee-gcc2.9-991111 */
typedef struct Slot {
    int unk0;
    int flags;
    int unk8;
    int unkC;
} Slot;

extern int D_005A3168;
extern Slot D_0078F200[32];
extern void func_004FEC60(void);
extern int func_004FA860(int sema);
extern int func_004FA840(int sema);

Slot *func_004FED50(void)
{
    Slot *s;

    func_004FEC60();
    func_004FA860(D_005A3168);
    for (s = D_0078F200; s < D_0078F200 + 32; s++) {
        if (s->flags == 0) {
            s->flags = 0x10000000;
            func_004FA840(D_005A3168);
            return s;
        }
    }
    func_004FA840(D_005A3168);
    return 0;
}
