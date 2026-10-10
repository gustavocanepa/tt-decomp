/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class iostream (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef struct {
    int inited;
} Module_00614CB0;

extern Module_00614CB0 D_007A6470;
extern char D_006150E8[];
extern char D_006150F8[];

void func_00575180(void);
void func_005755E8(void);
void func_0050C6C0(Module_00614CB0 *m, const char *a, const char *b, int n);

Module_00614CB0 *func_00575D28(void) {
    if (D_007A6470.inited == 0) {
        func_00575180();
        func_005755E8();
        func_0050C6C0(&D_007A6470, D_006150E8, D_006150F8, 2);
    }
    return &D_007A6470;
}
