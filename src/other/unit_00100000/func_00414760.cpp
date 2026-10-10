struct Key {
    int a;
    int b;
};

extern "C" void func_00414188(unsigned char *p, unsigned char *q, int a, int b);

extern "C" void func_00414760(Key *key, unsigned char *buf, int size)
{
    unsigned char *p = buf;
    unsigned char *end = p + size - 8;
    for (; p <= end; p++)
        func_00414188(p, p, key->a, key->b);
}
