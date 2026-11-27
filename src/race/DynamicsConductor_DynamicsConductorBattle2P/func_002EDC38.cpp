/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Source { char pad[2]; unsigned char n; char pad3[0x29]; u16 values[30]; float scale[10]; };
struct Other { char pad[0xcc]; u16 value; };
struct Output { int n; u16 first[10]; u16 second[10]; float a[10]; float b[10]; };
extern "C" void func_002EDC38(Source *src, Other *other, Output *out) {
    int n = src->n;
    unsigned int i = 0;
    out->n = n;
    if (n >= (int)i) {
        float *b = out->b;
        u16 *second = out->second;
        float *scale = src->scale;
        u16 *values = src->values;
        float *a = out->a;
        u16 *first = out->first;
        do {
            u16 value = 1000;
            if (i >= 2U) value = *values;
            *first = value;
            float f = (float)value * 0.10471974313259124756f;
            if (i == 0) f = -f;
            *a = f / *scale;
            if (i == 0 || i == (unsigned int)n) value = other->value;
            else value = src->values[1];
            *second = value;
            f = (float)value * 0.10471974313259124756f;
            if (i == 0) f = -f;
            float divisor = *scale;
            scale++;
            i++;
            second++;
            a++;
            first++;
            values++;
            *b = f / divisor;
            b++;
        } while (n >= (int)i);
    }
}
