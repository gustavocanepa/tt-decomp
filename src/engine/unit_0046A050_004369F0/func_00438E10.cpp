/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int a,n,c,d; };
struct E { char pad[0x14]; float t; };
extern "C" int func_004369F0(void *, int);
extern "C" void func_004368A8(O *, void *, int);
extern "C" float func_00436A50(void *);
extern "C" E *func_00436968(O *, int);
extern "C" int func_00438E10(void *p, int i, float t) {
 int r = func_004369F0(p,4);
 if (!r) return r;
 O o;
 func_004368A8(&o,p,4);
 int n=o.n;
 if(n<6) return 0;
 float len=func_00436A50(p);
 if(t < len*0.5f) t+=len;
 if (func_00436968(&o,i+1)->t < t && t < func_00436968(&o,n-i-3)->t) return 1;
 return 0;
}
