struct Set { int m0; unsigned int bits[8]; };
extern "C" void func_00402478(Set *self, int a, unsigned int bit);

extern "C" void func_00402500(Set *self, int a, unsigned int bit)
{
    func_00402478(self, a, bit);
    self->bits[bit >> 5] |= 1 << (bit & 31);
}
