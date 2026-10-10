/* compiler: ee-gcc2.9-991111 */
extern "C" void *func_004FEA00(void *);
extern "C" void func_004FEA58(void *);
extern "C" void func_004FA740(void);

extern "C" void func_004FEC20(void *self) {
    for (;;) {
        void *e;
        while ((e = func_004FEA00(self)) != 0) {
            func_004FEA58(e);
        }
        func_004FA740();
    }
}
