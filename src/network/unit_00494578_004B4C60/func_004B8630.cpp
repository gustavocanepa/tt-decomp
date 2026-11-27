static inline int value(const int *p) { return *p; }
static inline int clamp(int code) { if (code < -10) return -11; return code; }
extern "C" int func_004B8630(int fallback, int code) {
    int c = clamp(code);
    switch (c) {
    case -4: return 2;
    case -11: case -2:
    case -1: return 3;
    default: return value(&fallback);
    }
}
