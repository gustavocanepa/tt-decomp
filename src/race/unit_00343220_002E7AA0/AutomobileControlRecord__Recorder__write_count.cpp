/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004B2D68(void *, unsigned long, int);
extern "C" void AutomobileControlRecord__Recorder__write_count(void *w, unsigned int count) {
    unsigned long n = count;
    if (count != 0) n = count - 1;
    unsigned long one = 1;
    int bits = 0;
    while (n >= (one << bits)) {
        n -= one << bits;
        bits++;
    }
    func_004B2D68(w, ~0UL, bits);
    func_004B2D68(w, 0UL, 1);
    func_004B2D68(w, n, bits);
}
