/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef void (*Func)(void);

extern Func D_005A4798;
extern int D_005A479C;

void func_00509290(void);
void func_005094B0(void);
void func_00509518(void);

void func_005094B0(void)
{
    Func *entry = &D_005A4798;

    if (*entry == func_005094B0)
        *entry = func_00509518;
    if (D_005A479C == 0)
        func_00509290();
    (*entry)();
}
