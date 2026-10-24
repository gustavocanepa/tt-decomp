struct B11 { char x[10]; };
extern "C" void func_0028FCE8(char *, int, const char *);
extern "C" int func_0040B330(int *, int);
extern "C" int func_0040B460(int *, int);
extern "C" int func_0040B590(int *);
extern "C" int func_0040B6A8(int *);
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_004F7A30(void *, void *);
extern char D_005FBD08[];
extern char D_005FBD18[];
extern char D_005FBD28[];
extern signed char D_00585C28[];

extern "C" void func_0040B1F0(int *self) {
    char buf[0x80];
    *(B11 *)buf = *(B11 *)D_005FBD08;
    func_004F6678(buf + 10, 0, 0x76);
    func_0028FCE8(buf, 0x80, D_005FBD18);
    func_004F7A30(self + 2, buf);
    func_004F7A30(self + 2, D_005FBD28);
    *self = 0;
    int i = 0;
    do {
        *self += func_0040B330(self, i++);
    } while (i < 0x2C);
    int j = 0;
    while (D_00585C28[j] != 0x2C) {
        *self += func_0040B460(self, D_00585C28[j]);
        j++;
    }
    *self += func_0040B590(self);
    *self += func_0040B6A8(self);
}
