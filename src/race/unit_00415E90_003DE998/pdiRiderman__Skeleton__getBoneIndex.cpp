extern "C" const char *func_003E5988(int index);
extern "C" int func_004A8268(const char *a, const char *b); /* strcmp */

extern "C" int pdiRiderman__Skeleton__getBoneIndex(const char *name)
{
    if (name != 0) {
        for (int i = 0; i < 20; i++) {
            if (func_004A8268(func_003E5988(i), name) == 0)
                return i;
        }
    }
    return -1;
}
