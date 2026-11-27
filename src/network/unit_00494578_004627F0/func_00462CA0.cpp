/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Packer {
 int *head; int *out; int packets;
 float pos[64][3]; float norm[64][3]; float uv[64][2];
 int color[64]; int runs[21];
 int attr, prim, flags, count, pending, nruns, dirty, total, unk980, enabled, words;
};
extern "C" void func_00462C18(Packer *) throw();
extern "C" void func_00462CA0(Packer *p) {
 func_00462C18(p);
 if (p->count == 0) return;
 if (p->enabled) {
  int *base=p->out+4;
  int *q=base;
  q[0]=0x6c01c0c0;
  q[1]=p->count|0x8000;
  q[2]=(p->prim<<15)|0x30004000;
  q[3]=0x412;
  q[4]=0;
  q+=5;
  *q++=((p->nruns+1)<<16)|0x6200c040;
  unsigned char *b=(unsigned char*)q;
  *b++=p->nruns;
  int i;
  for(i=0;i<p->nruns;i++) *b++=p->runs[i]*3-6;
  while((int)b&3) *b++=0;
  q=(int*)b;
  if(p->flags&1) {
   *q++=(p->count<<16)|0x6800c000;
   float *f=(float*)q;
   for(i=0;i<p->count;i++) {
    f[0]=p->pos[i][0]; f[1]=p->pos[i][1]; f[2]=p->pos[i][2]; f+=3;
   }
   q=(int*)f;
  }
  if(p->flags&2) {
   *q++=(p->count<<16)|0x6800c080;
   float *f=(float*)q;
   for(i=0;i<p->count;i++) {
    f[0]=p->norm[i][0]; f[1]=p->norm[i][1]; f[2]=p->norm[i][2]; f+=3;
   }
   q=(int*)f;
  }
  if(p->flags&4) {
   *q++=(p->count<<16)|0x7400c040;
   float *f=(float*)q;
   for(i=0;i<p->count;i++) { f[0]=p->uv[i][0]; f[1]=p->uv[i][1]; f+=2; }
   q=(int*)f;
  }
  if(p->flags&8) {
   *q++=(p->count<<16)|0x6e00c080;
   for(i=0;i<p->count;i++) *q++=p->color[i];
  }
  while((int)q&15) *q++=0;
  p->out[1]=(q-base)/4;
  if(p->dirty) { p->out[2]=p->attr; p->dirty=0; }
  else p->out[2]=0;
  *(int**)p->out=q;
  p->out=q;
 } else {
  p->words+=(p->nruns+4)/4+10;
  if(p->flags&1) p->words+=p->count*3+1;
  if(p->flags&2) p->words+=p->count*3+1;
  if(p->flags&4) p->words+=p->count*2+1;
  if(p->flags&8) p->words+=p->count+1;
  while(p->words&3) p->words++;
  p->dirty=0;
 }
 p->packets++;
 p->total+=p->count;
 p->count=0;
 p->pending=0;
 p->nruns=0;
}
