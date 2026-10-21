/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob { int v[6]; };
struct Result { int status, exists, a, b; char pad[0x30]; };
struct Src { char pad[0x48]; int handle; };
extern "C" void func_0047EFD8(void *);
extern "C" const char *func_004816D0(int);
extern "C" void func_004816F0(int);
extern "C" void func_004BECB0(Result *, const char *);
extern "C" Blob *func_004805F0(Blob *out, void *, Src *src) {
 Blob b;
 int h = src->handle;
 func_0047EFD8(&b);
 Result r;
 func_004BECB0(&r, func_004816D0(h));
 b.v[0] = 9;
 if (r.status == 0) {
  b.v[0] = 0;
  b.v[1] = r.exists != 0;
  b.v[2] = r.b;
  b.v[3] = r.a;
  b.v[5] = 0;
 }
 func_004816F0(h);
 *out = b;
 return out;
}
