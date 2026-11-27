typedef char Obj;

extern "C" {
void func_00321358(Obj *self, int a);
void func_00321538(Obj *self, int a);
void func_00321580(Obj *self, int a);
void func_003215C8(Obj *self, int a);
void func_00321620(Obj *self, int a);
void func_00321678(Obj *self, int a);
void func_003A6010(void *p);
void func_003187A8(void *a, void *b);
void func_0032DC90(void *cam, void *b);
void func_0032D888(void *cam, void *b);
void func_00321B08(void *cam, int a, void *b, void *c, void *d);
void func_003187D0(void *a, void *cam, void *d);
}

extern "C" void func_00320B40(Obj *self, int a, int unused, int *mode) {
    void *s4 = self + 0xEA8;
    void *s5 = self + 0xF00;
    *(int *)(self + 0x100C) = *mode;
    void *s6 = self + 0xDC0;
    switch (*mode) {
    case 1:
    case 2:
        func_00321358(self, a);
        break;
    case 6:
        func_00321538(self, a);
        break;
    case 7:
        func_00321580(self, a);
        break;
    case 3:
        func_003215C8(self, a);
        break;
    case 4:
        func_00321620(self, a);
        break;
    case 5:
        func_00321678(self, a);
        break;
    default:
        func_003A6010(s4);
        func_003187A8(s5, s4);
        break;
    }
    void *cam = *(void **)(self + 0xD04);
    void *s1 = self + 0xA80;
    func_0032DC90(cam, s5);
    func_00321B08(cam, a, s4, s6, s1);
    void *cam2 = *(void **)(self + 0xD00);
    func_0032D888(cam2, s5);
    func_00321B08(cam2, a, s4, s6, s1);
    func_003187D0(s5, *(void **)(self + 0xD00), s1);
}
