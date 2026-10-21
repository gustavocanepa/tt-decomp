/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S { int a,b,pos,bit; unsigned char *p; int d,flag; };
extern "C" int func_00459ED8(S *s,int *out) {
 if(s->bit<0) {
  int pos=s->pos;
  unsigned char *p=s->p;
  s->pos=pos+1;
  s->p=p+1;
  s->bit=7;
  if(s->flag==0) {
   s->pos=pos+2;
   s->p=p+2;
   s->flag=1;
  }
  if(*s->p==255) {
   if(s->p[1]!=0) {
    *out=1;
    return s->p[1]+0xff00;
   }
   s->flag=0;
  }
 }
 int v=*s->p;
 int bit=s->bit;
 s->bit=bit-1;
 return (v >> bit)&1;
}
