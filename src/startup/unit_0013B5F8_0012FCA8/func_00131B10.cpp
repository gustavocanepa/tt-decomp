extern const char *D_00579948[];
extern "C" int func_004A8268(const char *a, const char *b); /* strcmp */

/* Index of a name in a null-terminated table, -1 when absent. */
extern "C" int func_00131B10(const char *name)
{
    const char **p = D_00579948;
    int i = 0;
    for (; *p != 0; p++, i++) {
        if (func_004A8268(*p, name) == 0)
            return i;
    }
    return -1;
}
