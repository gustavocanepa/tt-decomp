/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class iostream (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef struct {
    int inited;
} Module_00614CB0;

extern Module_00614CB0 D_00793C10;
extern char D_005E98F0[];
extern char D_005E98F8[];

void func_0052EC40(void);
void func_0054CC78(void);
void func_0050C6C0(Module_00614CB0 *m, const char *a, const char *b, int n);

Module_00614CB0 *func_00529600(void) {
    if (D_00793C10.inited == 0) {
        func_0052EC40();
        func_0054CC78();
        func_0050C6C0(&D_00793C10, D_005E98F0, D_005E98F8, 2);
    }
    return &D_00793C10;
}
