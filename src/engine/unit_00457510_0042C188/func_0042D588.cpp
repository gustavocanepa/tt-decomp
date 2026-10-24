/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef long s64;
struct Record { int x[6]; };
struct Obj { Record *base; u32 count; };
extern "C" void func_0042D140(Obj *, int) throw();
extern "C" int func_00418938(int);
extern "C" Record func_0042D588(s64 *key, u32 *index) {
    Obj obj;
    u32 i = 0;
    func_0042D140(&obj, 12);
    if (obj.count) {
    u32 off = 0;
    do {
        Record *r = (Record *)(off + (u32)obj.base);
        if (*key == func_00418938(r->x[1])) {
            if (index) *index = i;
            return *(Record *)(off + (u32)obj.base);
        }
    } while (++i < obj.count && (off += 24, 1));
    }
    if (index) *index = 0;
    return *obj.base;
}
