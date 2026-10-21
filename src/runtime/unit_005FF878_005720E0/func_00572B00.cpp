/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { long data[8]; };
extern Block D_00774080, D_007740C0;
extern "C" void func_004F4348(int);
extern "C" int func_004F45D8(void *, int, int, void *, int);
extern "C" int func_005038D8();
extern "C" void func_00572B00(int *self) {
    func_004F4348(self[0]);
    func_004F45D8(self, 8, 0, &D_00774080, 0x40);
    int intr = func_005038D8();
    D_007740C0 = D_00774080;
    if (intr) __asm__ volatile("ei");
}
