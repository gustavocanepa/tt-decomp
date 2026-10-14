/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Obj { int head; void *vt; int a,b,c; char storage[0xb0]; char *str; };
extern char D_005B9550[];
extern char *D_00766260;
extern "C" void *func_002A7618(void *);
extern "C" char *func_0050F0F0(Rep *);
extern "C" void func_004C9CC0(void *,int,void *,void *,void *);
extern "C" void mGamePort__structor_0(Obj *o) {
    char **dst = &o->str;
    func_002A7618(o);
    o->vt = D_005B9550;
    o->c = 0;
    char *p = D_00766260;
    Rep *r = (Rep *)(p-16);
    char *out = p;
    if (r->sel) out = func_0050F0F0(r);
    else r->ref++;
    *dst = out;
    return func_004C9CC0(o->storage,0,0,0,0);
}
