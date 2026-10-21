/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta,index; int (*fn)(void *,int); };
struct Obj { int error,flag; char pad8[0xAA8-8]; int state; char padAAC[0xD80-0xAAC]; int mode; char padD84[0x11D0-0xD84]; Entry *vt; };
extern "C" int func_00458A38(Obj *) throw();
extern "C" void func_00458778(Obj *) throw();
extern "C" int func_00458D78(Obj *);
extern "C" int func_00458DF8(Obj *);
extern "C" int func_00458EE0(Obj *);
extern "C" int func_00458FC8(Obj *,int);
extern "C" int func_00459358(Obj *);
extern "C" int func_00459538(Obj *);
extern "C" int func_004596D8(Obj *);
extern "C" int func_00458AA8(Obj *o) {
 int result=0;
 int marker=func_00458A38(o);
 if(marker>=0) {
  switch(marker) {
  case 0xFFDA: result=3; if(func_004596D8(o)) break; return -1;
  case 0xFFDD: if(func_00458DF8(o)) break; return -1;
  case 0xFFFE: if(func_00458D78(o)) break; return -1;
  case 0xFFE0: if(func_00458EE0(o)) break; return -1;
  case 0xFFC0: if(func_00458FC8(o,o->mode)) break; return -1;
  case 0xFFC4: if(func_00459358(o)) break; return -1;
  case 0xFFDB: if(func_00459538(o)) break; return -1;
  case 0xFFE1 ... 0xFFEF: {
   Entry *v=o->vt+2;
   int r=v->fn((char *)o+v->delta,marker);
   if(r!=-1) { o->error=r; o->flag=1; goto fail; }
   if(o->state) goto cleanup;
   break;
  }
  case 0xFF01:
  case 0xFFC1 ... 0xFFC3:
  case 0xFFC5 ... 0xFFCF:
  case 0xFFDC:
  case 0xFFDE ... 0xFFDF:
  case 0xFFF1 ... 0xFFFD:
   o->error=3; o->flag=1; return -1;
  default: o->error=1; o->flag=1; return -1;
  case 0xFFD8: result=1; break;
  case 0xFFD9: result=2; break;
  }
  return result;
 }
 cleanup:
 func_00458778(o);
 fail: return -1;
}
