/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E2 { short delta,pad;int (*fn)(void*,void*); };
struct EV { short delta, pad; void (*fn)(void*,int); };
struct E { short delta, pad; int (*fn)(void*); };
struct Info { char pad[0xB8]; char body[0x60]; char tail[0x1C]; E *vt; };
struct Obj { int x; char pad4[0x5C]; char *p60; char pad64[0x1C]; void *p80; char pad84[0x40]; int c4; char padc8[8]; int d0; };
extern "C" void *exception__structor_0(int);
extern "C" void func_0034A6A0(void*), func_0040EB38(void*), func_00375640(void*);
extern "C" void func_00375888(void*,int),func_003759B0(void*,int),func_00375A30(void*,void*),func_00375808(void*,long),func_00376760(void*,long),func_0034ADD0(void*,int),func_003761D0(void*);
inline int call(Info *p,int i) { E *e=p->vt+i; return e->fn((char*)p+e->delta); }
inline void call2(Info *p,int i,void *a) { EV *e=(EV*)p->vt+i; e->fn((char*)p+e->delta,(int)a); }
extern "C" Obj *func_0036CA68(Info *self) {
 void *course=exception__structor_0(0xD8);func_0034A6A0(course);
 void *other=exception__structor_0(0xB8);func_0040EB38(other);
 char *src=(char*)call(self,5);
 Obj *obj=(Obj*)exception__structor_0(0x978);func_00375640(obj);func_00375888(obj,(int)other);
 __builtin_memcpy(obj,self->body,0x60);
 func_003759B0(obj,(int)src);func_00375A30(obj,course);
 func_00375808(obj,call(self,2));func_00376760(obj,call(self,3));
 obj->x=call(self,7);obj->c4=call(self,8);obj->d0=call(self,9);
 func_0034ADD0(obj->p80,call(self,18));
 int count=call(self,11);
 if(count>0) { int n=count; do {
  E *e=*(E**)(src+0x20)+2;
  char *car=(char*)e->fn(src+e->delta);
  char *p=obj->p60;E2 *v=*(E2**)(p+0x20)+5;
  if(v->fn(p+v->delta,car)!=-1)call2(self,13,car);
  else if(car){EV *v=*(EV**)(car+0x55B8)+1;v->fn(car+v->delta,3);}
  --n;
 }while(n); }
 call2(self,14,obj);func_003761D0(obj);return obj;
}
