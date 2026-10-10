struct Req {
    int handle;
    char pad[0x3C];
    int arg0;
    int arg1;
    int arg2;
};
extern Req D_00776D80;

extern "C" void func_004F4348(int);
extern "C" int func_004F45D8(void *obj, int a1, int a2, void *buf, int size);

extern "C" void func_004BEBB0(int a0, int a1, int a2) {
    func_004F4348(D_00776D80.handle);
    D_00776D80.arg0 = a0;
    D_00776D80.arg1 = a1;
    D_00776D80.arg2 = a2;
    func_004F45D8(&D_00776D80, 5, 0, 0, 0);
}
