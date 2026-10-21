/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64; typedef unsigned int U __attribute__((mode(TI)));
union Row { U q; float f[4]; };
struct Light { Light *next; char p4[5]; signed char index; char pa[0x60-0xa]; Row pos,dir,half,axis,axisout; };
struct S { unsigned char dirty; volatile unsigned char mode; char p2[0xc]; unsigned char scale; char pf[0x48-0xf]; volatile unsigned short flags; char p4a[0x2e0-0x4a]; Row a[3]; char p310[0x360-0x310]; Row b[3]; Row view; char p3a0[0xab0-0x3a0]; Row eye,eyeout,normal; char pae0[0xb18-0xae0]; Light *lights; char pb1c[0xbe0-0xb1c]; Row scaling; char pbf0[0xed0-0xbf0]; U m[4]; };
extern "C" void func_0046C8A0(S *s) {
u64 r0,r1,r2,t0,t1,t2,t3;
s->flags &= ~2;
if(s->mode==0) {
__asm__ volatile("vmove.xyzw  $vf20, $vf28");
__asm__ volatile("vmove.xyzw  $vf21, $vf29");
__asm__ volatile("vmove.xyzw  $vf22, $vf30");
__asm__ volatile("vmove.xyzw  $vf23, $vf31");
} else {
__asm__ volatile("lqc2 $vf20, %0"::"m"(s->m[0]));
__asm__ volatile("lqc2 $vf21, %0"::"m"(s->m[1]));
__asm__ volatile("lqc2 $vf22, %0"::"m"(s->m[2]));
__asm__ volatile("lqc2 $vf23, %0"::"m"(s->m[3]));
}
s->a[0].q=0;s->a[1].q=0;s->a[2].q=0;s->b[0].q=0;s->b[1].q=0;s->b[2].q=0;
    __asm__ volatile("vsub.xyz $vf23, $vf0, $vf23");
    __asm__ volatile("qmfc2.ni %0, $vf20" : "=r"(r0));
    __asm__ volatile("qmfc2.ni %0, $vf21" : "=r"(r1));
    __asm__ volatile("qmfc2.ni %0, $vf22" : "=r"(r2));
    __asm__ volatile("pextlw %0, %1, %2" : "=r"(t0) : "r"(r1), "r"(r0));
    __asm__ volatile("pextuw %0, %1, %2" : "=r"(t1) : "r"(r1), "r"(r0));
    __asm__ volatile("pextlw %0, $0, %1" : "=r"(t2) : "r"(r2));
    __asm__ volatile("pextuw %0, $0, %1" : "=r"(t3) : "r"(r2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r0) : "r"(t2), "r"(t0));
    __asm__ volatile("pcpyud %0, %1, %2" : "=r"(r1) : "r"(t0), "r"(t2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r2) : "r"(t3), "r"(t1));
    __asm__ volatile("qmtc2.ni %0, $vf20" : : "r"(r0));
    __asm__ volatile("qmtc2.ni %0, $vf21" : : "r"(r1));
    __asm__ volatile("qmtc2.ni %0, $vf22" : : "r"(r2));
    __asm__ volatile("vmulax.xyz ACC, $vf20, $vf23x");
    __asm__ volatile("vmadday.xyz ACC, $vf21, $vf23y");
    __asm__ volatile("vmaddz.xyz $vf23, $vf22, $vf23z");
if(s->scale) {
__asm__ volatile("lqc2 $vf2, %0"::"m"(s->scaling));
__asm__ volatile("vmul.xyzw   $vf20, $vf20, $vf2");
__asm__ volatile("vmul.xyzw   $vf21, $vf21, $vf2");
__asm__ volatile("vmul.xyzw   $vf22, $vf22, $vf2");
}
__asm__ volatile("lqc2 $vf2, %0"::"m"(s->eye));
__asm__ volatile("vmr32.xyzw  $vf4, $vf0");
__asm__ volatile("vmulax.xyzw ACC, $vf20, $vf2x");
__asm__ volatile("vmadday.xyzw ACC, $vf21, $vf2y");
__asm__ volatile("vmaddaz.xyzw ACC, $vf22, $vf2z");
__asm__ volatile("vmaddw.xyzw $vf2, $vf23, $vf2w");
__asm__ volatile("vmulax.xyzw ACC, $vf20, $vf4x");
__asm__ volatile("vmadday.xyzw ACC, $vf21, $vf4y");
__asm__ volatile("vmaddz.xyzw $vf4, $vf22, $vf4z");
__asm__ volatile("sqc2 $vf2, %0":"=m"(s->eyeout));
__asm__ volatile("sqc2 $vf2, %0":"=m"(s->view));
__asm__ volatile("vmul.xyzw   $vf1, $vf4, $vf4");
__asm__ volatile("vaddy.x     $vf1, $vf1, $vf1y");
__asm__ volatile("vaddz.x     $vf1, $vf1, $vf1z");
__asm__ volatile("vrsqrt      Q, $vf0w, $vf1x");
__asm__ volatile("vwaitq");
__asm__ volatile("vmulq.xyzw  $vf4, $vf4, Q");
__asm__ volatile("sqc2 $vf4, %0":"=m"(s->normal));
for(Light *l=s->lights;l;l=l->next) {
if(l->pos.f[3]==0.0f) {
__asm__ volatile("lqc2 $vf2, %0"::"m"(l->pos));
__asm__ volatile("vmulax.xyzw ACC, $vf20, $vf2x");
__asm__ volatile("vmadday.xyzw ACC, $vf21, $vf2y");
__asm__ volatile("vmaddaz.xyzw ACC, $vf22, $vf2z");
__asm__ volatile("vmaddw.xyzw $vf2, $vf23, $vf2w");
__asm__ volatile("vmul.xyzw   $vf1, $vf2, $vf2");
__asm__ volatile("vaddy.x     $vf1, $vf1, $vf1y");
__asm__ volatile("vaddz.x     $vf1, $vf1, $vf1z");
__asm__ volatile("vrsqrt      Q, $vf0w, $vf1x");
__asm__ volatile("vwaitq");
__asm__ volatile("vmulq.xyzw  $vf2, $vf2, Q");
__asm__ volatile("sqc2 $vf2, %0":"=m"(l->dir));
__asm__ volatile("vadd.xyzw   $vf2, $vf2, $vf4");
__asm__ volatile("vmul.xyzw   $vf1, $vf2, $vf2");
__asm__ volatile("vaddy.x     $vf1, $vf1, $vf1y");
__asm__ volatile("vaddz.x     $vf1, $vf1, $vf1z");
__asm__ volatile("vrsqrt      Q, $vf0w, $vf1x");
__asm__ volatile("vwaitq");
__asm__ volatile("vmulq.xyzw  $vf2, $vf2, Q");
__asm__ volatile("sqc2 $vf2, %0":"=m"(l->half));
} else {
__asm__ volatile("lqc2 $vf2, %0"::"m"(l->pos));
__asm__ volatile("vmulax.xyzw ACC, $vf20, $vf2x");
__asm__ volatile("vmadday.xyzw ACC, $vf21, $vf2y");
__asm__ volatile("vmaddaz.xyzw ACC, $vf22, $vf2z");
__asm__ volatile("vmaddw.xyzw $vf2, $vf23, $vf2w");
__asm__ volatile("sqc2 $vf2, %0":"=m"(l->dir));
__asm__ volatile("lqc2 $vf2, %0"::"m"(l->axis));
__asm__ volatile("vmulax.xyzw ACC, $vf20, $vf2x");
__asm__ volatile("vmadday.xyzw ACC, $vf21, $vf2y");
__asm__ volatile("vmaddaz.xyzw ACC, $vf22, $vf2z");
__asm__ volatile("vmaddw.xyzw $vf2, $vf23, $vf2w");
__asm__ volatile("vmul.xyzw   $vf1, $vf2, $vf2");
__asm__ volatile("vaddy.x     $vf1, $vf1, $vf1y");
__asm__ volatile("vaddz.x     $vf1, $vf1, $vf1z");
__asm__ volatile("vrsqrt      Q, $vf0w, $vf1x");
__asm__ volatile("vwaitq");
__asm__ volatile("vmulq.xyzw  $vf2, $vf2, Q");
__asm__ volatile("sqc2 $vf2, %0":"=m"(l->axisout));
}
int i=l->index;
if(i>=0) {
s->a[0].f[i]=l->dir.f[0];s->a[1].f[i]=l->dir.f[1];s->a[2].f[i]=l->dir.f[2];
s->b[0].f[i]=l->half.f[0];s->b[1].f[i]=l->half.f[1];s->b[2].f[i]=l->half.f[2];
}
}
}
