inline void *operator new(unsigned int, void *p) throw() { return p; }

/* The singleton class (D_006898D8 in src/func_004C0570.cpp), named after its constructor so the
   call resolves. */
struct func_004C0570 {
    func_004C0570();
};

extern char D_007773D0[];
extern func_004C0570 *D_00598818;

extern "C" void func_004C04D0(void) {
    if (D_00598818 == 0)
        D_00598818 = new (D_007773D0) func_004C0570;
}
