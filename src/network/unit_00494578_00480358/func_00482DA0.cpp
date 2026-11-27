/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { signed char type; char pad[7]; };
struct Block { char pad[0x214]; int count; Record items[64]; int done; };
struct Obj { char pad[0x24]; Block blocks[2]; int current; };
extern "C" void func_00483360(Obj *,Record *);
extern "C" void func_00482DA0(Obj *self) {
 Block *b=&self->blocks[1-self->current];
 int finished;
 do {
  int n=b->count;
  finished=1;
  int i=0;
  if (n>0) {
   do {
    Record *r=&b->items[i];
    int type=r->type;
    if(type==2) goto handle;
    if(type==3) goto handle;
    if(type==4) goto handle;
    if(type==5) {
     handle: func_00483360(self,r); finished=0; break;
    }
    ++i;
   } while(i<n);
  }
 } while(!finished);
 b->done=1;
}
