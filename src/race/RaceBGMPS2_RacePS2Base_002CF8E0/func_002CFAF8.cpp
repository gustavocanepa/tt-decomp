/* compiler: ee-gcc2.96-no-strict-aliasing */
struct State { char p[0xD94]; int disabled; };
struct World { char p[0x84]; State *state; };
struct Music { int p[2]; int rate; unsigned duration; int count[32]; unsigned *times[32]; };
struct VEntry {short delta,index; void (*fn)(void*,int,int);};
struct Obj { World *world; VEntry *vt; int p8; Music *(*get)(); float (*time)(int*,int*); Music *music; char p[0x20]; int old; int cursors[32]; float remaining[32]; int changed[32]; };
extern "C" int func_002CFA00(Obj *) throw() __attribute__((const));
extern "C" float func_002CFE88(Obj *);
extern "C" void func_004B57A8(float);


extern "C" void func_002CFAF8(Obj *o) {
 if(o->world->state->disabled==0) func_004B57A8(func_002CFE88(o));
 int current=0, end=0;
 float time=o->time(&current,&end)+0x1.111110p-5f;
 o->music=o->get();
 int i=0;
 int *cursor=o->cursors;
 for(;i<32;i++,cursor++) {
  o->remaining[i]=6.80564694e38f;
  o->changed[i]=0;
  Music *m=o->music;
  if(m && m->count[i]) {
   float next=-6.80564694e38f;
   if(*cursor < m->count[i]) {
    next=(float)m->times[i][*cursor]/(float)m->rate;
    if(next<time) {
     o->changed[i]=1;
     int pos=++o->cursors[i];
     if(pos==m->count[i]) next=-6.80564694e38f;
     else next=(float)m->times[i][pos]/(float)m->rate;
    }
   }
   if(next<0.0f) next=(float)m->times[i][0]/(float)m->rate+(float)m->duration/(float)m->rate;
   if(current!=o->old) {
    o->changed[i]=1;
    o->cursors[i]=0;
    next=(float)m->times[i][0]/(float)m->rate;
   }
   o->remaining[i]=next-time;
  }
 }
 if(end && *(int*)((char*)o+0x30) && !func_002CFA00(o)) {
  VEntry *e=o->vt+5; e->fn((char*)o+e->delta,12,0);
  current=o->old;
 }
 o->old=current;
}
