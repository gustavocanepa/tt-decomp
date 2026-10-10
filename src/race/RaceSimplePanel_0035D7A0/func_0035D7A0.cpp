typedef unsigned char u8;

struct Obj_003A77B8 {
    char pad0[0x34];
    u8 f54;
    u8 f55;
};

extern "C" void func_003592B0(void *arg0);

extern "C" void func_0035D7A0(char *arg0) {
    func_003592B0((void *)(arg0 + 0x9D4));

    struct Obj_003A77B8 *self = (struct Obj_003A77B8 *)(arg0 + 0xA0C);
    self->f55 = self->f54;
}
