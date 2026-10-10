inline void *operator new(unsigned int, void *p) throw() { return p; }

/* The singleton class (D_006898D8 in src/func_004C1150.cpp), named after its constructor so the
   call resolves. */
struct func_004C1150 {
    func_004C1150();
};

extern char D_007774F0[];
extern func_004C1150 *D_00598C08;

extern "C" void func_004C1100(void) {
    if (D_00598C08 == 0)
        D_00598C08 = new (D_007774F0) func_004C1150;
}
