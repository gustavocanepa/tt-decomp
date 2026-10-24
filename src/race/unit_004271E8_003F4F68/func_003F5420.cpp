struct Vertex { float x,y; float zero; };struct UV { float u,v; };struct R { Vertex p[4];UV uv[4]; };
extern "C" R *func_00473980(int);
extern "C" void func_0046D810(int,void *,void *,int,int,int);
extern "C" void func_003F5420(float x0,float y0,float x1,float y1,float u0,float v0,float u1,float v1) {
volatile R *r=func_00473980(5);
r->p[0].x=x0;r->p[0].y=y0;r->p[0].zero=0;
r->p[1].x=x1;r->p[1].y=y0;r->p[1].zero=0;
r->p[2].x=x0;r->p[2].y=y1;r->p[2].zero=0;
r->p[3].x=x1;r->p[3].y=y1;r->p[3].zero=0;
r->uv[0].u=u0;r->uv[0].v=v0;r->uv[1].u=u1;r->uv[1].v=v0;
r->uv[2].u=u0;r->uv[2].v=v1;r->uv[3].u=u1;r->uv[3].v=v1;
func_0046D810(4,(void*)r,(void*)r->uv,0,0,0);
}
