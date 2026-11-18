/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void (*fn)(void *); };
struct Conn { char pad[0x38]; int owner; char p2[0x44]; int state, status; char p3[0x10]; int timer, busy; char p4[8]; char *vtbl; };
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0047CBF8(int, void *);
extern "C" void func_0047CCC8(int, void *);
extern "C" void func_0047CE70(int, void *);
extern "C" int func_0047EE40(void *);
static inline void notify(Conn *c, int off) { VEntry *e = (VEntry *)(c->vtbl + off); e->fn((char *)c + e->delta); }
extern "C" void func_0047EB88(Conn *c) {
 int changed = 0;
 func_004A4D68(c);
 int state = c->state;
 c->busy = 1;
 switch (state) {
 case 0:
 func_0047CBF8(c->owner, c); c->status = 1; changed = 1; notify(c, 0x40); break;
 case 1:
 if (func_0047EE40(c)) { func_0047CCC8(c->owner, c); c->status = 1; changed = 1; notify(c, 0x40); c->timer = 0; } break;
 case 2:
 if (func_0047EE40(c)) { func_0047CE70(c->owner, c); c->status = 1; changed = 1; notify(c, 0x40); c->timer = 0; } break;
 }
 func_004A4DD8(c);
 if (changed) notify(c, 0x48);
}
