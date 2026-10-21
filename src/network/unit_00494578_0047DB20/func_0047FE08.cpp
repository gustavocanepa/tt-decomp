typedef int s32;

struct P8 {
    s32 a;
    s32 b;
};

extern "C" void func_004AEB30(void *arg0);

extern "C" void func_0047FE08(void *arg0) {
    s32 idx = *(s32 *)((char *)arg0 + 0x1884);
    s32 off = idx * 8;
    char *e = (char *)(off + (s32)arg0);
    *(struct P8 *)((char *)arg0 + 0x1A8C) = *(struct P8 *)(e + 0x1874);
    func_004AEB30((char *)arg0 + 0x19C0);
}
