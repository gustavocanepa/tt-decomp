/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Entry { s32 pad[2]; s32 id; s32 other; };
extern s32 D_00584068;
extern Entry *D_0058406C;
extern "C" s32 malloc(s32) throw();
extern "C" s32 func_0034D7A8(s32 **out) {
    s32 *count = &D_00584068;
    s32 *ids = (s32 *)malloc(*count * 4);
    s32 n = *count;
    if (n > 0) {
        s32 *p = ids;
        s32 *e = (s32 *)D_0058406C;
        e += 2;
        do {
            s32 value = *e;
            e += 4;
            n--;
            *p++ = value;
        } while (n != 0);
    }
    *out = ids;
    return D_00584068;
}
