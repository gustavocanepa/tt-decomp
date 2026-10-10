/* compiler: ee-gcc2.96-no-strict-aliasing */
extern const char *D_005981E8; /* "0123456789abcdef" */

char *func_004AAA88(const unsigned char *in, char *out)
{
    const unsigned char *end = in + 16;
    char *p = out;
    for (; in < end; in++) {
        *p++ = D_005981E8[*in >> 4];
        *p++ = D_005981E8[*in & 0xF];
    }
    *p = 0;
    return out;
}
