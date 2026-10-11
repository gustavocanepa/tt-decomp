typedef int s32;
typedef struct { s32 (*f)(s32 a, s32 b); s32 a; } Hook;
extern Hook D_005983E8;
s32 func_004BB688(void) {
    return D_005983E8.f(D_005983E8.a, 0);
}
