struct Obj { int base; void *table; int f8; int fC; int owned; void * car; char storage[4]; };
extern "C" char D_005A63F8[];
extern "C" int func_002A7618(Obj *);
extern "C" void func_00411E18(void *);
extern "C" int func_00132268(Obj *);
extern "C" int func_00145AD8(Obj *, int);
extern "C" void *exception__structor_0(int);
extern "C" void func_00405098(void *, int);
extern "C" void func_0043DC20(void *);
extern "C" int func_00132668(Obj *self, int value) {
func_002A7618(self); self->table=D_005A63F8; self->owned=1; void *car=exception__structor_0(0x508); func_00405098(car,value); self->car=(void *)car; func_00411E18((char *)self+0x18); return func_00132268(self);
}
