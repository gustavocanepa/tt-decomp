/* compiler: ee-gcc2.96-nsa-nosib */
extern char D_005A07B0[];
extern void func_004A4D68(void *);
extern void func_004A4DD8(void *);
extern void func_004A59F0(void);
extern int func_004DAFE0(void);

void func_004CB5D0(void) {
    func_004A4D68(D_005A07B0);
    while (func_004DAFE0() != 0)
        func_004A59F0();
    func_004A4DD8(D_005A07B0);
}
