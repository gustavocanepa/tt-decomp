/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { long data[8]; };
extern Block D_00774080, D_007740C0;
extern int D_00773FC0[];
extern "C" void func_004F4348(int);
extern "C" int func_004F45D8(void *, int, int, void *, int);
extern "C" int func_005038D8();
extern "C" void func_004B5E98() {
    func_004F4348(D_00773FC0[0]);
    func_004F45D8(D_00773FC0, 8, 0, &D_00774080, 0x40);
    int intr = func_005038D8();
    D_007740C0 = D_00774080;
    if (intr) __asm__ volatile("ei");
}
