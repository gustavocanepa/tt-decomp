extern "C" const char *func_0040B8A0(void *table, int id);
extern "C" char *func_004F7B74(char *dst, const char *src); /* strcpy */
extern "C" char D_00585A30[];

extern "C" int func_0040FC28(int id, char *out)
{
    const char *s = func_0040B8A0(D_00585A30, id);
    if (s) {
        func_004F7B74(out, s);
        return 1;
    }
    out[0] = 0;
    return 0;
}
