/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libgcc2.c-style __terminate (noreturn call through the terminate hook) glued to the
   following eh helper that returns &(*get_eh_context())->field at +8. */
typedef void (*vfp)(void);

extern vfp D_005A484C __attribute__((__noreturn__));
extern void **func_00509268(void);

void func_0050E240(void) {
    (*D_005A484C)();
}

void *func_005C16D8(void) {
    return (char *)*func_00509268() + 8;
}
