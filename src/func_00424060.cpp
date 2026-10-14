/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { int tag, off, size; };
struct Stream { unsigned int base, end, cur; };
extern "C" void func_00424450(Record *, Stream *, int);
extern "C" Record *func_00424060(Record *dst, Record *in, Stream *s, int tag) {
 if (in->off < 0) {
   dst->size=0; dst->tag=0; dst->off=-1;
 } else {
   Stream t;
   t.base=s->base;
   t.end=s->base + (in->off + in->size);
   t.cur=s->base + (in->off + 8);
   Record r;
   func_00424450(&r,&t,tag);
   Record *ok=((~(unsigned int)r.off >> 31) != 0) ? &r : 0;
   if (ok) s->cur=s->base+r.off;
   *dst=r;
 }
 return dst;
}
