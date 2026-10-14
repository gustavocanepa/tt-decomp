/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Obj { int *data; int unk; int flag; };
extern "C" int *func_001A3788(Obj *o) {
 int count;
 int q;
 int *p=o->data;
 int magic=*p++;
 if(magic!=0x10000) return 0;
 int type=*p++;
 if(type!=1 && type!=2 && type!=4 && type!=6 && type!=8) return 0;
 int flags=*p++;
 if(!(flags&4)) return 0;
 p++;
 int n=*p++;
 if(n%3!=0 || n<3) goto bad;
 q=n/3;
 if(q>=601 && type==1) goto bad;
 if(q>=551 && type==2) goto bad;
 if(q>=501 && type==4) goto bad;
 if(q>=451 && type==6) goto bad;
 if(q>=401 && type==8) goto bad;
 p=(int*)((char*)p+(type*8+16)*n);
 count=*p++;
 if((u32)count>256) { bad: return 0; }
 for(int i=0;i<count;i++) {
  p+=3;
  int count2=*p++;
  if((u32)count2>8) return 0;
  for(int j=0;j<count2;j++) {
   p++;
   int k=*p++;
   p=(int*)((char*)p+k*8);
   if((u32)k>10) goto bad;
  }
 }
 if(flags&8) o->flag=1;
 return p;
}
