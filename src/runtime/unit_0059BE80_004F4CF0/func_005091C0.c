/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): new_eh_context? (libgcc2.c, exception handling).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef struct {
    int m0;
    char *m4;
    char data[0xE8];
} Obj_005BC640;

void *func_004A45F8(int size);
void func_00509170(void) __attribute__((noreturn));
void *func_004F6678(void *p, int c, int n);

Obj_005BC640 *func_005091C0(void) {
    Obj_005BC640 *p = func_004A45F8(sizeof(Obj_005BC640));
    if (p == 0) {
        func_00509170();
    }
    func_004F6678(p, 0, sizeof(Obj_005BC640));
    p->m4 = (char *)p + 0xE0;
    return p;
}
