/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Reader {
    int m0, m4, m8;
    int mode;
    unsigned char *p;
    int avail;
    int m18;
    int m1C;
    int eof;
    char pad[0xA88 - 0x24];
};
struct Obj { char pad[0xA88]; int dummy; };
extern "C" int func_004599A8(void *r);
extern "C" int func_00458A38(char *o)
{
    Reader *r = (Reader *)(o + 0xA88);
    for (;;) {
        if (func_004599A8(r) == 0xFF) {
            int c = func_004599A8(r);
            if (c != 0) {
                if (!r->eof) return c | 0xFF00;
                return -1;
            }
        }
        if (r->eof) return -1;
    }
}
