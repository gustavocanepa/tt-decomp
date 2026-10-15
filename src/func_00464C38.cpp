/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern char D_00603F30[], D_0076D570[];
extern char *D_00587130;


void func_00464C38() {
 char *src=D_00603F30; char *p=D_0076D570;
 int done=0; char **table=&D_00587130; int slot=16; char *base=D_00603F30; int off=0; int i;
 do {
  int n=72-done; char *start=p;
  if(n>=22) n=21;
  int triple=n*3;
  *(u32 *)(start+0)=0x6c01c0c0;
  *(u32 *)(start+4)=triple|0x8000;
  *(u32 *)(start+8)=0x30264000;
  *(u32 *)(start+12)=0x412;
  *(u32 *)(start+20)=((n+1)<<16)|0x6200c040;
  *(u32 *)(start+16)=0;
  p=start+24; *p=n;
  for(i=0;i<n;i++) start[25+i]=3;
  p+=(n+4)/4*4;
  int upper=triple<<16;
  *(u32 *)p=upper|0x6800c000; p+=4;
  char *out=p;
  if(n>0) { char *q=(char *)(off+(u32)base);
  i=n; do {
   *(u32 *)out=0; out+=4; *(u32 *)out=0; out+=4; *(u32 *)out=0; out+=4;
   *(float *)out=*(float *)(q+0)*0.03125f; out+=4;
   *(float *)out=*(float *)(q+4)*0.03125f; out+=4;
   *(u32 *)out=0; out+=4;
   *(float *)out=*(float *)(q+16)*0.03125f; out+=4;
   *(float *)out=*(float *)(q+20)*0.03125f; out+=4;
   *(u32 *)out=0; out+=4;
   q+=48;
  } while(--i);
  }
  p=out;
  *(u32 *)p=upper|0x6e00c080; p+=4;
  if(n>0) { char *q=src+40;
  i=n; do {
   u32 g=*(u32 *)(q-4); u32 b=*(u32 *)q; u32 r=*(u32 *)(q-8);
   *(u32 *)p=r|((b<<16)|(g<<8))|0xff000000; p+=4;
   *(u32 *)p=0; p+=4; *(u32 *)p=0; p+=4;
   q+=48;
  } while(--i);
  }
  while(((p-start)>>2)&3) { *(u32 *)p=0; p+=4; }
  int size=(p-start)>>2;
  *(char **)(*table+slot)=start;
  done+=21; src+=1008; off+=1008;
  *(short *)(*table+slot+4)=size/4;
  *(short *)(*table+slot+6)=0;
  slot+=8;
 } while(done<72);
 D_00587130[8]=0; D_00587130[9]=0;
 *(short *)(D_00587130+10)=4;
 *(short *)(D_00587130+12)=216;
 *(short *)(D_00587130+14)=72;
}
