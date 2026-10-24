struct O { char pad[0xB28]; int len; char buf[1]; };
extern "C" char *func_003F7488(O *self) {
    int n = self->len;
    if (n <= 0) return 0;
    int i = n - 2;
    while (i >= 0 && self->buf[i] != 0) i--;
    n = i + 1;
    self->len = n;
    return (char *)self + n + 0xB2C;
}
