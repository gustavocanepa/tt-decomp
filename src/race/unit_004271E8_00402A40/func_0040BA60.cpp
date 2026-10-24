struct Name {
    int id;
    int index;
};

extern "C" int func_004A8268(const char *a, const char *b);
extern const char *D_00585A20[];

extern "C" void func_0040BA60(Name *n, const char *s) {
    int i = 0;
    do {
        if (func_004A8268(s, D_00585A20[i]) == 0) {
            n->index = i;
            return;
        }
        i++;
    } while (i < 3);
    n->index = 0;
}
