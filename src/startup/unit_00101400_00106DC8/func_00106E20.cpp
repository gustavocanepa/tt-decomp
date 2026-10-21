struct Elem {
    char data[0x3C];
};

struct Pages {
    Elem elems[2];
    int cur;
    Elem *current() { return &elems[cur]; }
};

struct Screen {
    char pad[0x44];
    Pages pages;
};

extern Screen D_005794F0;

extern "C" void func_0046FD90(int a);
extern "C" void func_00105778(Screen *s, int a, int b, int c);
extern "C" void func_00105860(Screen *s, int a, int b);
extern "C" void func_00104BF0(Elem *e);

extern "C" void func_00106E20(void) {
    func_0046FD90(1);
    func_00105778(&D_005794F0, 1, 2, 1);
    func_00105860(&D_005794F0, 0, 0);
    func_00104BF0(D_005794F0.pages.current());
}
