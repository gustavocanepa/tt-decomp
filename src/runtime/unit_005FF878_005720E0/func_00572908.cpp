/* compiler: ee-gcc2.96-nsa-nosib */
struct Self {
    int lock;
    char pad4[0x3C];
    int field40;
    int field44;
    int field48;
    int field4C;
    char name[1];
};
struct Slot { long long id; char pad8[0xC]; int count; };
extern Slot D_007740C0;
extern "C" void func_004F4348(int);
extern "C" char *func_004F7B74(char *, const char *);
extern "C" int func_004F45D8(void *, int, int, int, int);
extern "C" void func_00572908(Self *self, int a, int b, int c, int d, const char *name) {
    func_004F4348(self->lock);
    D_007740C0.id = -1;
    D_007740C0.count = 0;
    self->field40 = a;
    self->field44 = b;
    self->field48 = c;
    self->field4C = d;
    self->name[0] = 0;
    if (name) func_004F7B74(self->name, name);
    func_004F45D8(self, 1, 0, 0, 0);
}
