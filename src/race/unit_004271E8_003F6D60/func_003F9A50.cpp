/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef long long s64;
struct D { int a; short b; char c; char d; s64 e; s64 f; unsigned char g; };
extern char D_006A5758[];
struct Src { s64 f; unsigned char g; };
extern "C" char *strcpy(char *, const char *);
extern "C" void func_003F9A50(D *d) {
    d->a = 0;
    d->b = 0;
    d->c = 0;
    d->d = 0;
    d->e = -1;
    strcpy((char *)&d->f, "--------");
}
