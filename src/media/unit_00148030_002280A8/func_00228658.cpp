/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Vec4 { f32 x, y, z, w; };
struct VT0 { short delta; short pad; void *ti; };
struct Base { int x; VT0 *vt; };
struct VE { short delta; short index; f32 (*fn)(void *, int); };
struct Obj { int x; char *vt; };

extern char func_005284F8[];
extern char func_0052A150[];

extern "C" void func_001B95A8(void *, void *);
extern "C" void func_001C9E10(void *, void *);
extern "C" void func_001C9EA0(void *, void *, Vec4 *, f32);
extern "C" f32 func_001E48A0(void *);
extern "C" f32 func_001E48C0(void *);
extern "C" f32 func_001E48E0(void *);
extern "C" f32 func_001E4900(void *);
extern "C" void *GT4MC__FileGT4GameData__loadInstance(void *, void *, int, void *, void *, void *);

extern "C" void func_00228658(Obj *self, Base *arg1) {
    Vec4 v;
    void *p = 0;
    char *s3 = (char *)self + 0xE8;
    if (arg1 != 0) {
        VT0 *t = arg1->vt;
        p = GT4MC__FileGT4GameData__loadInstance(t->ti, func_005284F8, 0, (char *)arg1 + t->delta, func_0052A150, arg1);
    }
    func_001C9E10(p, s3);
    func_001B95A8(self, arg1);
    f32 a = func_001E48A0(arg1);
    f32 b = func_001E48C0(arg1);
    f32 c = func_001E48E0(arg1);
    f32 d = func_001E4900(arg1);
    v.x = a;
    v.y = b;
    v.z = c;
    v.w = d;
    VE *e = (VE *)(self->vt + 0x290);
    f32 r = e->fn((char *)self + e->delta, 0);
    func_001C9EA0(p, s3, &v, r);
}
