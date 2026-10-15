/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Value { short data[87]; };
struct HeaderA { unsigned short len, count, data[38]; };
struct HeaderB { unsigned short len, count; unsigned char n, data[43]; };
struct Self { char pad[0x44]; int state; unsigned short count; char pad4a[2]; int mode; unsigned char flags; char pad51[15]; int bytes; unsigned char bits[4]; char pad68[4]; unsigned char data[64]; };
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004C9CC0(Value *, int, HeaderA *, HeaderB *, void *);
extern "C" Value func_004BFD10(Self *s) {
 Value result;
 HeaderA a;
 HeaderB b;
 void *lock=(char *)s+0x10;
 func_004A4D68(lock);
 int id=0;
 a.count=0;
 b.count=0;
 b.n=0;
 switch(s->state) {
 case 0: break;
 case 1: case 2: {
   b.count=s->count;
   unsigned int mask=0;
   switch(s->bytes) {
   case 0: break;
   default: mask=s->bits[3]<<24;
   case 3: mask|=s->bits[2]<<16;
   case 2: mask|=s->bits[1]<<8;
   case 1: mask|=s->bits[0]; break;
   }
   switch(mask) {
   case 0xfff9: id=1; break;
   case 0xfffff: id=2; if(s->mode) { id=(s->flags&1)?3:2; if(s->flags&2) id=4; } break;
   case 0xffffffff: id=5; break;
   }
   int pos=0;
   unsigned int out=0;
   for(int i=0;i<16;i++) {
    unsigned int bit=1<<i;
    if(mask&bit) {
     if(!((s->data[pos>>3]>>(pos&7))&1)) out|=bit;
     pos++;
    }
   }
   b.n=16;
   b.data[1]=out>>8;
   b.data[0]=out;
   pos=(pos+7)&~7;
   int n=0;
   for(int i=0;i<16;i++) if(mask&(1<<(i+16))) n++;
   a.count=n;
   for(int i=0;i<n;i++) { a.data[i]=s->data[pos>>3]; pos+=8; }
  } break;
 default: break;
 }
 func_004C9CC0(&result,id,&a,&b,0);
 func_004A4DD8(lock);
 return result;
}
