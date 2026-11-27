/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { int v[3]; };
struct Row { int v[3]; char pad[0x24]; };
struct Camera {
    int v0[3];
    int vC[3];
    int v18[3];
    int n24, n28, n2C, n30, n34;
    int a38[6];
    int a50[6];
    int a68[6];
    int a80[6];
    int a98[6];
    int aB0[6];
    int aC8[6];
    int aE0[6];
    int aF8[6];
    int a110[6];
    float a128[6];
    int a140[6];
    V p[6];
    Row q[6];
};
extern "C" void Pitmen__Camera__clear(Camera *s) {
    int i;
    s->n24 = 0;
    s->n2C = 1;
    s->n28 = 1;
    s->n30 = 0;
    s->n34 = 0;
    for (i = 0; i < 6; i++) {
        s->a50[i] = 0;
        s->a68[i] = 0;
        s->a80[i] = 0;
        s->a98[i] = 0;
        s->aB0[i] = -1;
        s->aC8[i] = 0;
        s->aE0[i] = 0;
        s->a128[i] = -1.0f;
        s->a110[i] = -1;
        s->a140[i] = 0;
        s->p[i].v[0] = 0;
        s->p[i].v[1] = 0;
        s->p[i].v[2] = 0;
        s->q[i].v[0] = 0;
        s->q[i].v[1] = 0;
        s->q[i].v[2] = 0;
        s->a38[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        s->v0[i] = 0;
        s->vC[i] = 0;
        s->v18[i] = 0;
    }
}
