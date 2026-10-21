/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long U64;
struct Bits { U64 x:14,pad:23,y:14,end:13; };
struct Rec { U64 a,b,c,d,e; };
struct Small { int a; unsigned short x; char pad[6]; };
struct Obj { char pad[16]; unsigned short x,y,n,m; Rec *r; Small *s; };
#define UPDATE(P,D,S) { U64 *p=(P); U64 v=*p; int x=(int)((v>>(S))&0x3fffUL); *p=(v&~(0x3fffUL<<(S)))|((U64)((x+(D))&0x3fffUL)<<(S)); }
extern "C" Obj *func_00466828(Obj *o,unsigned pos) {
 pos>>=6;
 int delta=pos-o->x;
 if(!delta) return o;
 {
  o->x=pos;
  int i;
  for(i=0;i<o->n;i++) {
   ((Bits *)(i*40+(int)o->r))->x=(int)((Bits *)(i*40+(int)o->r))->x+delta;
   ((Bits *)(i*40+(int)o->r))->y=(int)((Bits *)(i*40+(int)o->r))->y+delta;
   int k=(int)((o->r[i].b>>2)&7UL);
   if(k>0) {
    UPDATE((U64 *)(i*40+(int)o->r+16),delta,0);
    UPDATE((U64 *)(i*40+(int)o->r+16),delta,20);
    UPDATE((U64 *)(i*40+(int)o->r+16),delta,40);
    if(k>=4) {
     UPDATE((U64 *)(i*40+(int)o->r+24),delta,0);
     UPDATE((U64 *)(i*40+(int)o->r+24),delta,20);
     UPDATE((U64 *)(i*40+(int)o->r+24),delta,40);
    }
   }
  }
  if(!o->s) return o;
  for(i=0;i<o->m;i++)o->s[i].x+=delta;
 }
 return o;
}
