/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef long long s64;
typedef unsigned char u8;
struct Ids { s64 v[3]; };
struct Src { char p0[8]; Ids a; Ids b; };
struct Dst { char pad[0x408]; char el[3][0xA8]; };
extern "C" {
int SPEC_DATABASE__DatabaseStorage__getRow(void *, s64, void *);
void func_00409EE8(int, void *, void *, void *);
extern char D_00585A30[];
void func_00409DB0(int self, Dst *d, Src *s) {
    struct { Ids a; s64 gap; Ids b; } ids;
    u8 bufA[0x60];
    u8 bufB[0x20];
    u8 bufC[0x10];
    ids.a = s->a;
    ids.b = s->b;
    u8 *pa = bufA;
    char *e = d->el[0];
    int off = 0;
    int k = 2;
    do {
        k--;
        SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30, *(s64 *)((char *)&ids + off), pa);
        u8 *pb = bufB;
        SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30, *(s64 *)((char *)&ids.b + off), pb);
        off += 8;
        func_00409EE8(self, e, pa, pb);
        e += 0xA8;
    } while (k >= 0);
    SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30, *(s64 *)s, bufC);
    u8 c2 = bufC[2];
    u8 c0 = bufC[0];
    u8 c3 = bufC[3];
    ((u8 *)d)[0x1CB] = c2;
    ((u8 *)d)[0x1CD] = c0;
    ((u8 *)d)[0x1CF] = 4;
    ((u8 *)d)[0x1C9] = c3;
}
}
