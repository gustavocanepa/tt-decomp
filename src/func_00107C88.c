extern int D_00586EF4;
extern int D_00579738;

void func_0040F7D0(void);
void func_0040F810(void);
void func_0040F868(void);
void func_0045E068(void);
void func_0045DFE0(void);
int func_00107EF0(int a);
void func_0045E010(int a);
void func_0045EBA8(int a0, const char *a1);

void func_00107C88(void) {
    if (D_00579738 != 0) {
        func_0040F7D0();
        func_0040F810();
        func_0040F868();
        func_0045E068();
        func_0045DFE0();
        func_0045E010(func_00107EF0(0));
        func_0045EBA8(D_00586EF4, "Q212GranTurismo413UpdateManager");
        D_00579738 = 0;
    }
}
