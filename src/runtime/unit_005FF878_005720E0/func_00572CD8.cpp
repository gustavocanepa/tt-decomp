/* compiler: ee-gcc2.96-nsa-nosib */
struct Self {
    int lock;
    char pad4[0x38];
    int active;
    char pad40[0x40];
    int field80;
    int field84;
    int field88;
    int field8C;
    char pad90[0x30];
};
extern int D_00598334;
extern "C" void func_004F4348(int);
extern "C" void func_004F42C8(int);
extern "C" void func_004F43A8(int, int);
extern "C" int func_004F45D8(void *, int, int, void *, int);
extern "C" void func_00572CD8(Self *self, int a, int b, int c, int d) {
    func_004F4348(D_00598334);
    func_004F4348(self->lock);
    self->active = 1;
    self->field80 = b;
    self->field8C = d;
    self->field84 = c;
    self->field88 = a;
    func_004F43A8(a, c);
    func_004F45D8(self, 3, 1, (char *)self + 0xC0, 0x40);
    func_004F42C8(D_00598334);
}
