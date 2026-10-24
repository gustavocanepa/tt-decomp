/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Vec2 { float x,y; };
struct Val;
extern "C" void func_0043D510(Val *) throw();
struct Val { int type,value; Val(const Val &); ~Val() {func_0043D510(this);} };
struct Item { unsigned short flags; short index; };
struct Array {
 Item *data; int count;
 Item *begin() const {return data;}
 Item *end() const {return data+count;}
};
struct Def { char pad[10]; unsigned short flags; Array items; };
struct Entry {int a,b;};
struct Class {char pad[0xa8]; Entry *entries;};
struct Obj {
 Class *cls;
 char pad4[0x24]; float scale;
 char pad2c[0x30]; char *vtable;
 char pad60[0x20]; Obj *child;
 char pad84[0x14]; int hidden;
};
struct Event {char pad[0x40]; int state[3]; Vec2 pos;};
struct VTest {short delta,index; int (*fn)(void *,Vec2 *,float);};
struct VGet {short delta,index; void *(*fn)(void *);};
extern "C" int func_00444680(Obj *,Event *,u32) throw();
extern "C" Def *func_0044BAA0(Obj *) throw();
extern "C" int func_00443D50(void *) throw();
extern "C" int func_00443F18(void *,u32) throw();
extern "C" void func_004449A0(Obj *,Vec2 *,int) throw();
extern "C" int func_0044BAC8(Obj *,int,int,Event *) throw();
extern "C" Val func_00448568(void *,Entry *,Event *) throw();
static inline void *vget(Obj *o) {
 VGet *e=(VGet *)(o->vtable+0x18);
 return e->fn((char *)o+e->delta);
}
extern "C" int func_0044BE70(Obj *self, Event *event,u32 mask) {
 int r=func_00444680(self,event,mask);
 if(r) return 1;
 if(self->hidden) return r;
 Def *def=func_0044BAA0(self);
 int state=func_00443D50(event->state);
 int found=0;
 int flags=0;
 if(mask&0x38) {
   Obj **slot=&self->child;
   if(*slot) {
     Vec2 pos=event->pos;
     func_004449A0(self,&pos,0);
     Obj *child=*slot;
     VTest *e=(VTest *)(child->vtable+0x28);
     if(e->fn((char *)child+e->delta,&pos,self->scale))
       flags=func_0044BAC8(self,1,state,event);
     else flags=func_0044BAC8(self,0,state,event);
   }
 }
 if((def->flags&flags) || (mask && (def->flags&0x200))) {
   for(Item *it=def->items.begin();it!=def->items.end();++it) {
     u32 code=it->flags>>9;
     if((it->flags&flags) || (code && func_00443F18(event->state,code)))

       func_00448568(vget(self),self->cls->entries+it->index,event);
     found=1;
   }
 }
 return found;
}
