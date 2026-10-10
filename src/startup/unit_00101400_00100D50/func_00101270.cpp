void func_004A59F0(void);
extern "C" int func_004DDA70(void);
extern "C" void func_004BF650(void);
extern "C" void func_004BA1B8(void);

extern "C" void func_00101270(void) {
    while (func_004DDA70() != 1)
        func_004A59F0();
    func_004BF650();
    func_004BA1B8();
}
