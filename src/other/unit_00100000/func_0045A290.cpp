extern "C" void func_0045A1C8(void *s, int nbits, unsigned int v);

extern "C" void func_0045A290(void *s, int nbits, unsigned int v)
{
    if (nbits > 8) {
        func_0045A1C8(s, nbits - 8, v >> 8);
        nbits = 8;
    }
    func_0045A1C8(s, nbits, v);
}
