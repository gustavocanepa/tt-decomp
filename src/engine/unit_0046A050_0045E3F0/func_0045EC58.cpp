/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x3C]; float sx; float sy; int digit; };
extern "C" const char *func_0045EBF8(const char *s, int *out);
extern "C" void func_0045EDE8(Obj *o, const char *s);
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" void func_0045EC58(Obj *o, const char *str) {
    int v[2];
    char buf[0x40];
    const char *first = 0;
    const char *p = str;
    o->sy = 1.0f;
    o->sx = 1.0f;
    char c = *p++;
    if (c != 0) {
        do {
            switch (c) {
            case '#': {
                if (!first) first = p - 1;
                int d = *p++ - '0';
                if ((unsigned)d < 10) o->digit = d;
                break;
            }
            case '*':
                if (!first) first = p - 1;
                v[0] = 100;
                p = func_0045EBF8(p, &v[0]);
                v[1] = v[0];
                if (*p == ',') p = func_0045EBF8(p + 1, &v[1]);
                float fb = (float)v[1] * 0.01f;
                float fa = (float)v[0] * 0.01f;
                o->sx = fa;
                o->sy = fb;
                break;
            }
        } while ((c = *p++) != 0);
    }
    int n = first - str;
    if (first) {
        if (n < 0x3F) {
            func_004F64C4(buf, str, n);
            buf[n] = 0;
            func_0045EDE8(o, buf);
        }
    } else {
        func_0045EDE8(o, str);
    }
}
