extern "C" void func_0019C9C0(char *buf, int c);

struct func_00198DD8_Obj {
    char pad[0x6A0];
    int state;
};

extern "C" void func_00198DD8(func_00198DD8_Obj *self, int k) {
    self->state = k;
    switch (k) {
    case 3:
        return func_0019C9C0((char *)self + 0x6A4, 0x52);
    case 4:
        return func_0019C9C0((char *)self + 0x6A4, 0x42);
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    default:
        return func_0019C9C0((char *)self + 0x6A4, 0);
    }
}
