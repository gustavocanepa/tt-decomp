/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int a; int b; float x; char pad[0x178-12]; };
struct Inner { int a; void *p; };
struct Obj { int a; Inner *inner; int count; Entry *entries; };
struct Buf { float x; char pad[12]; int flag; int zero; char end[8]; };
extern "C" int func_003C8650(Obj *) throw();
extern "C" void *func_003EEC70(Buf *, float, int, float);
extern "C" int func_003F1200(void *, Buf *);
extern "C" void func_003C8948(Obj *obj, float f) {
    Buf buf;
    if (func_003C8650(obj)) {
        int i=0;
        for (; i<obj->count; i++) {
            Entry *e=obj->entries+i;
            func_003EEC70(&buf,e->x,e->a,f);
            buf.flag=1;
            buf.zero=0;
            func_003F1200(obj->inner->p,&buf);
            Entry *dest=obj->entries+i;
            dest->x=buf.x;
        }
    }
}
