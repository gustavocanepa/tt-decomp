extern const char D_005DCFA0[], D_005FA560[];
extern "C" unsigned int func_004C0480(void);
extern "C" int func_004A8268(const char *, const char *);

extern "C" int func_003FE1A8(void) {
    switch (func_004C0480()) {
    case 0:
        return 0;
    case 1:
        return (func_004A8268(D_005DCFA0, D_005FA560) == 0) ? 2 : 1;
    case 2:
        return 3;
    case 3:
        return 6;
    case 4:
        return 4;
    case 5:
        return 5;
    case 7:
        return 7;
    default:
        return 2;
    }
}
