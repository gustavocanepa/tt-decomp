/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mat { float a,b,c,d,e,f,g,h,i; Mat &operator=(const Mat &o) {
a=o.a;b=o.b;c=o.c;d=o.d;e=o.e;f=o.f;g=o.g;h=o.h;i=o.i;return *this;} };
extern "C" void func_0044FFD0(Mat *m,const Mat *n) { Mat t;
t.a=m->a*n->a+m->d*n->b+m->g*n->c;
t.d=m->a*n->d+m->d*n->e+m->g*n->f;
t.g=m->a*n->g+m->d*n->h+m->g*n->i;
t.b=m->b*n->a+m->e*n->b+m->h*n->c;
t.e=m->b*n->d+m->e*n->e+m->h*n->f;
t.h=m->b*n->g+m->e*n->h+m->h*n->i;
t.c=m->c*n->a+m->f*n->b+m->i*n->c;
t.f=m->c*n->d+m->f*n->e+m->i*n->f;
t.i=m->c*n->g+m->f*n->h+m->i*n->i;
*m=t;
}
