/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pos {float x,y,z;};
struct Point {float x,z;};
struct List {char pad[16];};
struct Seg {char pad[8]; unsigned short n; char padA[10]; unsigned short *ids; char tail[40];};
struct Tbl {char pad[0x18]; int nseg; Seg *segs; int nlist; List *lists;};
struct Mid {char pad[0xCC]; Tbl *tbl;};
struct Ctx {char pad[4]; Mid *mid;};
extern "C" bool func_00379768(List *,Point *);
extern "C" int func_003AA540(Pos *pos,Ctx *ctx,int idx) {
 Tbl *t=ctx->mid->tbl;
 if(idx<0) return -1;
 if(idx>=t->nseg) return -1;
 Seg *s=t->segs+idx;
 if(t==0) return -1;
 Point p;
 p.x=pos->x; p.z=pos->z;
 int i=0;
 if(s->n!=0) {
 do {
 int n=s->ids[i];
 i++;
 if(n<0) return -1;
 if(n>=t->nlist) return -1;
 if(func_00379768(t->lists+n,&p)) return n;
 }while(i<s->n);
 }
 return -1;
}
