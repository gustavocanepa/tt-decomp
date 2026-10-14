/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline int count() { return 2; }
extern "C" int func_00388CE0(int *self) {
    volatile int *record = self;
    int row = 0;
    int index = 0;
    int slots = (int)self + 4;
    do {
        if (*record != 0) {
            int *slot = (int *)(index * 4 + slots);
            int n = 0;
            for (; n < count(); n++, slot++) {
                if (*slot == 0) {
                    int value = *record + n * 0x4b000;
                    *slot = value;
                    return value;
                }
            }
        }
        row++;
        record += 3;
        index += 3;
    } while (row < 6);
    return 0;
}
