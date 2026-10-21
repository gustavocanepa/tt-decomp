/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 { float x,y; };
struct Chain { Vec2 *items[48]; int count,side; };
extern "C" void func_0044C278(void *,const Vec2 *,const Vec2 *,const Vec2 *);
extern "C" void func_0056B568(Chain *,Vec2 **);
extern "C" void func_0056B598(Chain *,unsigned int,int);
static inline Vec2 *get(Vec2 *const &v) { return v; }
extern "C" void func_0056B160(Chain *s,void *out,Vec2 *point,int side) {
 int n=s->count;
 if(n<2) { func_0056B568(s,&point); s->side=side; return; }
 if(side==s->side) {
  Vec2 **cursor=(Vec2 **)(n*4+(int)s-8);
  int used=2;
  int back=n-1;
  Vec2 *prev=s->items[back];
  int i=n-2;
  float dx=get(prev)->x-point->x;
  float dy=get(prev)->y-point->y;
  int last;
  while(1) {
   Vec2 *current=*cursor--;
   last=i;
   Vec2 **pcur=&current;
   float ex=get(*pcur)->x-point->x;
   float ey=get(*pcur)->y-point->y;
   float cross=dx*ey-dy*ex;
   if(side) cross=-cross;
   if(!(cross<0.0f)) break;
   ++used;
   func_0044C278(out,current,prev,point);
   i=last-1;dx=ex;dy=ey;prev=current;
   if(n<used) { last=n-used; break; }
  }
  func_0056B598(s,last+2,0);
  func_0056B568(s,&point);
 } else {
  --n;
  s->side=side;
  int i=0;
  while(i<n) {
   int next=i+1;
   func_0044C278(out,s->items[i],s->items[next],point);
   i=next;
  }
  s->items[0]=s->items[n]; s->items[1]=point;
  func_0056B598(s,2,0);
 }
}
