/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004A45D0(void *) throw();
extern "C" char *func_004A4690(int, int);
extern "C" char *func_0051D5E8(char *, int, char *);
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" void *func_004F6678(void *, int, unsigned);
struct Self { char pad[0x50]; char *data; };
extern "C" int func_0019C308(Self *, void *, char *, int, int) throw();
struct Vec { int allocator; char *start; char *finish; char *eos; char spare[16]; char *tmp; char zero;
 Vec() { start=0; finish=0; eos=0; char *p=func_004A4690(0x40,0xCC0); eos=p+0xCC0; start=p; finish=p; tmp=p; zero=0; finish=func_0051D5E8(p,0xCC0,&zero); }
 ~Vec() { if (start) func_004A45D0(start); }
};
extern "C" int func_001981F8(Self *self, void *arg1, int arg2, int arg3) {
 Vec v;
 if (self->data) func_004F64C4(v.start,self->data,0xC88);
 else func_004F6678(v.start,0,0xC88);
 if (func_0019C308(self,arg1,v.start,v.finish-v.start,arg3)==0) return 1;
 return 0;
}
