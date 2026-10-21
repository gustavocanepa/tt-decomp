/* compiler: ee-gcc2.9-991111 */
struct Plugin { char pad[0x3c]; int (*query)(unsigned,int,unsigned*); int (*run)(unsigned,unsigned,int); char pad44[8]; int (*error)(int,int); };
extern struct Plugin *func_004D9EC0(void *,unsigned);
extern char D_00613EE0[],D_00613EF0[];
int __attribute__((register_precision(s0, 128))) func_004D7A48(int source,unsigned size,int mode,unsigned *error) {
 int (*query)(unsigned,int,unsigned*);
 int (*convert)(int,int);
 int (*run)(unsigned,unsigned,int);
 unsigned len;
 int r;
 if(mode==0) {
  struct Plugin *p=func_004D9EC0(D_00613EE0,0x102);
  if(!p) { *error=0x81050053; return -134; }
  query=p->query;
  run=p->run;
  convert=p->error;
 } else {
  struct Plugin *p=func_004D9EC0(D_00613EF0,0x102);
  if(!p) { *error=0x81050053; return -134; }
  query=p->query;
  run=p->run;
  convert=p->error;
 }
 {
  len=0;
  r=query(size,source,&len);
  if(r<0) { *error=convert(0,r); return *error; }
  {
   if(len==0) { *error=0x8105902c; return 0xffff6fd4; }
   if(size<len) { *error=0x8105000c; return -12; }
   r=run(size,len,source);
   if(r<0) {
    *error=convert(0,r);
    return *error;
   }
   return len;
  }
 }
}
