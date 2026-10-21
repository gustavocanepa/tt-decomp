/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned char u8;
struct Obj {u32 x, pos, size; u8 data[256];};
extern "C" u32 func_005437A8(Obj *o,u8 *dst,u32 n) {
 u32 len=o->size;
 if(n<len) len=n;
 if(len) {
  u32 pos=o->pos;
  u32 count=len;
  u32 end=pos+len;
  u8 *src=(u8 *)o+pos+12;
  u32 lim=256;
  if(end>lim) {
   count=lim-pos;
   for(u32 i=0;i<count;i++) {u8 c=*src++; *dst++=c;}
   end-=256; src=o->data; count=end;
  }
  for(u32 i=0;i<count;i++) {u8 c=*src++; *dst++=c;}
  o->pos=end; o->size-=len;
 }
 return len;
}
