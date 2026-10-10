extern "C" int func_0040B9B0(int a, int b, int c);

extern "C" int func_0040B980(int a, long b) {
    return func_0040B9B0(a, (int)(b & 0xFFFFFFFF), (int)(b >> 32));
}
