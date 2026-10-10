extern "C" int func_004A8268(const char *a, const char *b); /* strcmp */

extern "C" int func_003FEB98(const char **list, const char *s)
{
    for (int i = 0; list[i]; i++) {
        if (func_004A8268(s, list[i]) == 0)
            return i;
    }
    return -1;
}
