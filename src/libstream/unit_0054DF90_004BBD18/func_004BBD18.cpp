/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {
 char pad0[0x80]; unsigned int size; void *entry; char p88[8]; char name[0x80]; char *str; char p114[0x190-0x114]; char *base; char *cur; char p198[0x3F4-0x198]; int mode;
};
struct Block { char bytes[0xA000]; };
extern "C" int func_004FA710();
extern "C" int func_004A4690(int,int);
extern "C" int func_004BC018(void*,void*,void*,void*,void*);
extern "C" int func_004F8588(void*,void*,int) throw();
extern "C" int func_004FA6B0(int,int);
extern "C" void func_004BD120(int*,void*,int,char**);
extern "C" int func_004CC818(int);
extern "C" void func_004BD1B8(void*,int);
extern "C" int func_004BCD90(void*,int*,int*,long*,long*);
extern "C" void func_004BD3F8();
extern "C" void func_004BBD18(Self *self,void *name,int size) {
 int x,y; long z,w; int old;
 int state=func_004FA710();
 self->base=(char*)func_004A4690(0x40,size);
 func_004BC018(self,name,&self->entry,&self->size,&self->str);
 func_004F8588(self->name,name,0x80);
 char *end=self->base+size;
 old=func_004FA6B0(state,self->mode);
 self->cur=self->base;
 func_004BD120(0,self->entry,(self->size+0x7FF)>>11,&self->str);
 char *buf=(char*)func_004CC818(0);
 do {
  func_004BD1B8(buf,0xA000);
  *(Block*)self->cur=*(Block*)buf;
  int i; char *p;
  for(i=0,p=buf;i<8;i++,p+=0x1400) {
   if(func_004BCD90(p,&x,&y,&z,&w)) goto done;
  }
  self->cur+=0xA000;
 } while((unsigned int)self->cur<(unsigned int)end);
 done:
 func_004FA6B0(state,old);
 func_004BD3F8();
 self->cur=self->base;
}
