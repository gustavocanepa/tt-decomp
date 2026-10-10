typedef int s32;

struct Handle { s32 p; s32 pad[3]; };
extern s32 D_0057AA18;
extern "C" void func_0029CF48(Handle *, s32);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_0029CEF0(Handle *, s32);

extern "C" void func_001D04E0(void *self, s32 n, s32 x) {
    if (n > 0) {
        Handle h;
        func_0029CF48(&h, x);
        s32 r = func_0029E9F0(h.p);
        D_0057AA18 = r != 0;
        func_0029CEF0(&h, 2);
    }
}
