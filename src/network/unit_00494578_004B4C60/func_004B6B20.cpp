/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" signed char *func_004B6AD8(signed char *) throw();
extern "C" signed char *func_004B6B20(signed char *p) {
    p = func_004B6AD8(p);
    for (; *p && *p != '/' && *p != '\\'; ++p) {}
    return p;
}
