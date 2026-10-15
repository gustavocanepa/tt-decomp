/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
struct S { s32 p0; s32 n; s32 p8; u8 *len; u16 *code; u8 *val; u8 *outLen; u8 *outVal; };
extern "C" void func_0045D4D8(S *s) {
    int n = s->n;
    for (int i = 0; i < n; i++) {
        u8 *len = s->len;
        u16 *codes = s->code;
        int next = i + 1;
        int l = len[i];
        int c = codes[i];
        int v = s->val[i];
        int lo = c << (16 - l);
        int hi = 0x10000;
        if (next < n) hi = codes[next] << (16 - len[next]);
        for (int j = lo; j < hi; j++) {
            s->outVal[j] = v;
            s->outLen[j] = l;
        }
    }
}
