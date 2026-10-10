typedef int s32;

struct Buf { char b[0x1E0]; };
extern "C" void func_00411400(void *, s32, Buf *);
extern "C" void func_00411620(void *, Buf *, s32);

extern "C" void func_004113B8(void *self, s32 a, s32 b) {
    Buf buf;
    func_00411400(self, a, &buf);
    func_00411620(self, &buf, b);
}
