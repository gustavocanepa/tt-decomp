typedef unsigned long long u64;

extern "C" u64 func_004B2CE0(void *bits, int count);

extern "C" int func_002E7C98(void *bits) {
    int n = 0;
    while (func_004B2CE0(bits, 1))
        n++;
    return (int)func_004B2CE0(bits, n) + (1 << n);
}
