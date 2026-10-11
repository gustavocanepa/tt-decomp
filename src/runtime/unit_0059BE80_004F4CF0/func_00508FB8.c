/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __do_global_dtors (libgcc2.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* The function's own statics (p = __DTOR_LIST__ + 1, completed) live in its .data and are
 * reached through their addresses; __EH_FRAME_BEGIN__ is 0x006D3E00. */
typedef void (*func_ptr)(void);

extern func_ptr *D_005A478C;
extern int D_005A4790;
extern char D_00619600[];
extern void *func_0050B8F8(void *begin);

void func_00508FB8(void) {
    while (*D_005A478C) {
        D_005A478C++;
        (*(D_005A478C - 1))();
    }
    if (!D_005A4790) {
        D_005A4790 = 1;
        func_0050B8F8(D_00619600);
    }
}
