/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_001EC130(void *);
extern "C" int func_001EBCA0(void *self, int key) {
    if (func_001EC130(self)) {
        switch (key) {
        case 0xFEE5:
        case 0xFEE7:
        case 0xFF53:
        case 0xFF98: return 1;
        default: return 0;
        }
    } else {
        switch (key) {
        case 0xFEE6:
        case 0xFEE7:
        case 0xFF54:
        case 0xFF99: return 1;
        default: return 0;
        }
    }
}
