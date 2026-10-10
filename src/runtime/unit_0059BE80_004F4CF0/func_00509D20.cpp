extern signed char D_00793308[];

extern "C" int func_00509C90(int ch, int a, int b);
extern "C" int func_004F64C4(int a, int b, int c);

extern "C" int func_00509D20(int ch, int a, int b) {
    int x = func_00509C90(ch, a, 0);
    int y = func_00509C90(ch, b, 0);
    return func_004F64C4(y, x, D_00793308[ch]);
}
