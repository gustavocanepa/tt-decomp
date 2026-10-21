/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00486928(int, int, int) throw();
extern "C" int func_004869E0(int, int, int) throw();
extern "C" int func_00486A50(int self, int ch, int flag, int mode) {
    if (mode != 0) {
        if (flag != 0) return 0;
        if (ch == 0x40 || ch == 0x5B)
            return func_00486928(self, mode, ch) != 0;
        return 0;
    } else {
        return func_004869E0(self, ch, flag) != 0;
    }
}
