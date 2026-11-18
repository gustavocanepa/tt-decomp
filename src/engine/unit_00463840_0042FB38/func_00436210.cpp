/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad0[0x67]; char id; char pad68[0xC]; float score,time; };
struct Other { char pad[0x564]; char id; };
static inline void select(float *sc,float *tm,char *id,char bid,float score,float time) {
 if (time>0.0f) {
  if (*tm<=0.0f || score/time<*sc/ *tm) {
   *sc=score; *tm=time; *id=bid;
  }
 } else if (!(*tm>0.0f)) {
  if (score<*sc) { *sc=score; *tm=time; *id=bid; }
 }
}

extern "C" void func_00436210(Obj *o,Other *b,float x,float y,float score,float time) {
 select(&o->score,&o->time,&o->id,b->id,score,time);
}
