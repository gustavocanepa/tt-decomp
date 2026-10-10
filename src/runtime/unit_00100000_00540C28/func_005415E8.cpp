extern "C" void func_002C0FE8(void *arg0);
extern "C" void func_002C1050(void *arg0);

extern "C" void func_005415E8(void **arg0, void **arg1, void **arg2) {
    void **it = arg0;
    if (it != arg1) {
        do {
            if (it != arg2) {
                void *val = *arg2;
                if (val != 0) {
                    func_002C0FE8(val);
                }
                void *old = *it;
                if (old != 0) {
                    func_002C1050(old);
                }
                *it = val;
            }
            it += 1;
        } while (it != arg1);
    }
}
