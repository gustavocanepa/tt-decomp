/* compiler: ee-gcc2.9-991111 */
extern char D_00617C50[];
extern char *D_005A44B8;
extern char *func_00503DB8(const char *, int, const char **);
extern void func_00503ED0(void);
extern int func_004FA470(int, int, int, void *);
int func_00503ED8(int a, int b, int n, const char **v) {
    func_00503DB8(D_00617C50, n, v);
    func_00503ED0();
    return func_004FA470(a, b, n, D_005A44B8 + 4);
}
