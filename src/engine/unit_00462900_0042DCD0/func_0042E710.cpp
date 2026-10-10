struct Slot {
    char data[0x24];
};

extern int D_00585F64;
extern Slot D_0076BD00[3];

extern "C" void func_004A45D0(int h);
extern "C" void func_0042E040(int a);
extern "C" void func_0042DBD8(Slot *s);
extern "C" void func_0042E2F8(void);
extern "C" void func_0042E318(void);

extern "C" void func_0042E710(void) {
    int *h = &D_00585F64;
    if (*h) {
        func_004A45D0(*h);
        *h = 0;
    }
    func_0042E040(1);
    func_0042DBD8(&D_0076BD00[0]);
    func_0042DBD8(&D_0076BD00[1]);
    func_0042DBD8(&D_0076BD00[2]);
    func_0042E2F8();
    func_0042E318();
}
