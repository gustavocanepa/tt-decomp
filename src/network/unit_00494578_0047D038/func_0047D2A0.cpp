/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct VEntry { short delta,index; void (*fn)(void*); };
struct TestEntry { short delta,index; int (*fn)(void*,Obj*); };
struct EventEntry { short delta,index; void (*fn)(void*,Obj*); };
struct Obj { char pad[0x74]; int mode; char gap[8]; int f80,f84; char gap88[0x10]; int f98,f9c; char gapA0[8]; VEntry *vt; };
struct Self { char pad[0x4C]; Obj **entry; char gap[0x54]; char *vt; };
extern "C" {
int func_0047EE40(Obj*);
void func_0047C9A8(Obj*) throw();
void func_0047CCC8(Self*,Obj*) throw();
void func_0047CE70(Self*,Obj*) throw();
void func_0047CF68(Self*,Obj*) throw();
void func_004A4D68(Obj*);
void func_004A4DD8(Obj*);
}
static inline int blocked(Obj *o) { return o->f80 ^ 3; }
static inline int test(Self *s,Obj *o) { TestEntry *v=(TestEntry*)(s->vt+0x60); return v->fn((char*)s+v->delta,o); }
static inline void notify(Self *s,Obj *o) { EventEntry *v=(EventEntry*)(s->vt+0x68); v->fn((char*)s+v->delta,o); }
extern "C" void func_0047D2A0(Self *self) {
    Obj *o=*self->entry;
    if(func_0047EE40(o)) {
        int changed=0;
        int mode=o->mode;
        int refreshed=0;
        if(mode>=0) {
            if(mode>=2) {
                if(mode!=2) goto reset;
                goto event;
            }
            {
                if(test(self,o)) {
                    func_0047CF68(self,o);
                    changed=1;
                    VEntry *v=o->vt+7;
                    v->fn((char*)o+v->delta);
                } else {
                    goto refresh;
                }
            }
            goto post;
event:
            {
                refreshed=1;
                notify(self,o);
                func_0047CCC8(self,o);
            }
        } else {
reset:
            o->f84=2;
refresh:
            func_0047CCC8(self,o);
            refreshed=1;
            func_0047C9A8(o);
        }
post:
        o->f98=0;
        func_004A4D68(o);
        if((o->f9c || o->f84) && blocked(o)) {
            if(changed==0) func_0047CCC8(self,o);
            else func_0047CE70(self,o);
            int *state=&o->f84;
            if(*state==0) *state=1;
            if(refreshed==0) func_0047C9A8(o);
            refreshed=1;
        }
        func_004A4DD8(o);
        if(refreshed) {
            VEntry *v=o->vt+9;
            v->fn((char*)o+v->delta);
        }
    }
}
