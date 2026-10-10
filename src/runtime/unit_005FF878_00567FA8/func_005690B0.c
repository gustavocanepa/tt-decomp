void *func_00569110(void);
void *func_005690B0(void) {
    char *t = func_00569110();
    *(void **)(t + 0xEC) = t;
    *(void **)(t + 0xE8) = t;
    return t;
}
