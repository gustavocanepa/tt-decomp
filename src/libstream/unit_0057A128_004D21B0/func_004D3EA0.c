/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
typedef int s32;

struct G {
    char p0[0x20];
    s32 f20;
    s32 f24;
    s32 f28;
};

extern struct G D_0077A028;
extern char D_004D54C0[];
u32 func_004D2FD8(u32, s32, s32);
void func_004F6678(void *, s32, unsigned int);
int func_005059C0(u32, void *, s32);

s32 func_004D3EA0(s32 n) {
    s32 s1;
    s32 r;
    s1 = n * 0x48;
    r = func_004D2FD8(0, s1, 0);
    D_0077A028.f24 = r;
    if (r == 0)
        return (s32)0x8105000C;
    D_0077A028.f28 = n;
    D_0077A028.f20 = 1;
    func_004F6678((void *)r, 0, s1);
    func_005059C0(0x8000000B, D_004D54C0, 0);
    return 0;
}
