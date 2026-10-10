extern "C" int func_0040B8D0(int a, int b, int c);

extern "C" int func_0040B8A0(int a, long b) {
    return func_0040B8D0(a, (int)(b & 0xFFFFFFFF), (int)(b >> 32));
}
