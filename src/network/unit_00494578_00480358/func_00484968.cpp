/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { int state; char pad[0x418]; };
struct Obj { char pad[0x24]; Item items[2]; char pad858[0]; int current; int x85c; int done; };
extern "C" int func_00482300(Obj *,int) throw();
extern "C" void func_00482EE0(Obj *) throw();
extern "C" void func_00483A10(Obj *) throw();
extern "C" int func_00484968(Obj *p) {
 if (p->done) return 1;
 Item *i=&p->items[1-p->current];
 switch(i->state) {
 case 0: return 0;
 case 1:
 if (func_00482300(p,1)<=0) return 0;
 func_00482EE0(p); func_00483A10(p); return 1;
 case 2:
 func_00482EE0(p); func_00483A10(p); i->state=1; return 1;
 default: return 0;
 }
}
