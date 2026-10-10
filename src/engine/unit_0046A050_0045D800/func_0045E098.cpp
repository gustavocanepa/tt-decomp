struct A;
struct B;

extern A *D_00586EF4;
extern B *D_00586EF8;

extern "C" void func_0045EA68(A *a);
extern "C" void func_0045EA98(B *b);
extern "C" void func_0050E1A8(void *p);

extern "C" void func_0045E098(void) {
    A *a = D_00586EF4;
    if (a != 0) {
        D_00586EF4 = 0;
        func_0045EA68(a);
        func_0050E1A8(a);
    }
    B *b = D_00586EF8;
    if (b != 0) {
        D_00586EF8 = 0;
        func_0045EA98(b);
        func_0050E1A8(b);
    }
}
