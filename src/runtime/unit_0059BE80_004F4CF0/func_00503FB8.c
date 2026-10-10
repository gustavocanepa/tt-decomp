/* compiler: ee-gcc2.9-991111 */
extern char D_00617C50[];
extern char *D_005A44B8;
extern void func_00503DB8(void *list, void *self, int arg);
extern void func_00503ED0(void);
extern void func_004FAC40(void *self, char *p);

void func_00503FB8(void *self, int arg) {
    func_00503DB8(D_00617C50, self, arg);
    func_00503ED0();
    func_004FAC40(self, D_005A44B8 + 4);
}
