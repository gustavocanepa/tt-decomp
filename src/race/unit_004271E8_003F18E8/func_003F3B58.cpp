/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Element { short *ids; float start, offset, length; unsigned short count; unsigned char reverse; };
struct List { char data[32]; };
struct Motion { int a,b; List *lists; };
struct Interval { float start,end; };
extern "C" Element *GT4_Motion__PlayList__getElement(List *, float) throw();
extern "C" float func_003F3B30(Motion *, int, float, float, int) throw();
static inline float mn(float a,float b) { float c; __asm__("min.s %0, %1, %2":"=f"(c):"f"(a),"f"(b)); return c; }
static inline float mx(float a,float b) { float c; __asm__("max.s %0, %1, %2":"=f"(c):"f"(a),"f"(b)); return c; }
static inline void adjust(Interval *r,Element *e) { r->start=r->start-e->start+e->offset; r->end=r->end-e->start+e->offset; }
extern "C" float func_003F3B58(Motion *m,int index,float from,float to,float span,int arg) {
 float total=0.0f;
 List *list=&m->lists[index];
 Element *a=GT4_Motion__PlayList__getElement(list,from);
 Element *b=GT4_Motion__PlayList__getElement(list,to);
 bool ra=a->reverse!=0, rb=b->reverse!=0;
 float r[4];
 Element *next;
 if(a==b) {
  bool back=to<from;
  float lo=back?to:from;
  float hi=back?from:to;
  if ((back && ra) || (!back && !ra)) {
   r[0]=lo; r[1]=hi; next=0;
  } else {
   r[0]=a->start; r[1]=lo;
   r[2]=hi; r[3]=a->start+a->length; next=a;
  }
 } else {
  if(!ra) {r[0]=from; r[1]=mn(from+span,a->start+a->length);}
  else {r[0]=mx(from-span,a->start); r[1]=from;}
  if(!rb) {r[2]=mx(to-span,b->start); r[3]=to;}
  else {r[2]=to; r[3]=mn(to+span,b->start+b->length);}
  next=b;
 }
 r[0]=r[0]-a->start+a->offset; r[1]=r[1]-a->start+a->offset;
 for(int i=0;i<a->count;i++) total+=func_003F3B30(m,a->ids[i],r[0],r[1],arg);
 if(next) {
  r[2]=r[2]-next->start+next->offset; r[3]=r[3]-next->start+next->offset;
  for(int i=0;i<next->count;i++) total+=func_003F3B30(m,next->ids[i],r[2],r[3],arg);
 }
 return total;
}
