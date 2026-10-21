/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Vec { float x, y, z; };
struct Vec4 { float x, y, z, w; };
struct Body { int v; Vec rot, pos, vel, angular; float nx, ny, nz, d; unsigned char idx; };
struct Shape { Vec4 head; Vec4 pts[7]; };
struct Rec { char pad[0x20]; Shape shape; };
extern Rec *D_0061B704;
extern "C" void func_002DDC80(Vec *, Vec *, void *) throw();
extern "C" void func_002DDD18(Vec *, Vec *) throw();

extern "C" void func_002DF028(Body *self, Vec *out, int arg2, Vec *points, int count) {
    Vec force, local, velocity;
    Shape *shape = &D_0061B704[self->idx].shape;
    u128 r0, r1, r2, r3, t0, t1, t2, t3;
    float minimum;
    int i;
    __asm__ volatile("vmove.xyzw $vf24, $vf20");
    __asm__ volatile("vmove.xyzw $vf25, $vf21");
    __asm__ volatile("vmove.xyzw $vf26, $vf22");
    __asm__ volatile("vmove.xyzw $vf27, $vf23");
    __asm__ volatile("qmfc2.ni %0, $vf24" : "=r"(r0));
    __asm__ volatile("qmfc2.ni %0, $vf25" : "=r"(r1));
    __asm__ volatile("qmfc2.ni %0, $vf26" : "=r"(r2));
    __asm__ volatile("qmfc2.ni %0, $vf27" : "=r"(r3));
    __asm__ volatile("pextlw %0, %1, %2" : "=r"(t0) : "r"(r1), "r"(r0));
    __asm__ volatile("pextuw %0, %1, %2" : "=r"(t1) : "r"(r1), "r"(r0));
    __asm__ volatile("pextlw %0, %1, %2" : "=r"(t2) : "r"(r3), "r"(r2));
    __asm__ volatile("pextuw %0, %1, %2" : "=r"(t3) : "r"(r3), "r"(r2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r0) : "r"(t2), "r"(t0));
    __asm__ volatile("pcpyud %0, %1, %2" : "=r"(r1) : "r"(t0), "r"(t2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r2) : "r"(t3), "r"(t1));
    __asm__ volatile("pcpyud %0, %1, %2" : "=r"(r3) : "r"(t1), "r"(t3));
    __asm__ volatile("qmtc2.ni %0, $vf24" : : "r"(r0));
    __asm__ volatile("qmtc2.ni %0, $vf25" : : "r"(r1));
    __asm__ volatile("qmtc2.ni %0, $vf26" : : "r"(r2));
    __asm__ volatile("qmtc2.ni %0, $vf27" : : "r"(r3));
    minimum = 0.0f;
    for (i = 0; i < count; i++) {
        float ny, nx, nz;
        nx = self->nx;
        ny = self->ny;
        nz = self->nz;
        float dist = points[i].x * nx + points[i].y * ny + points[i].z * nz + self->d;
        if (dist < 0.0f) {
            float scale;
            if (dist < minimum) minimum = dist;
            scale = dist * -10.0f;
            force.x = nx * scale;
            force.y = ny * scale;
            force.z = nz * scale;
            func_002DDC80(&local, &self->angular, &shape->pts[i]);
            func_002DDD18(&velocity, &local);
            velocity.x += self->vel.x;
            velocity.y += self->vel.y;
            velocity.z += self->vel.z;
            force.x += velocity.x * -0x1.ff7cecp-1f;
            force.y += velocity.y * -0x1.ff7cecp-1f;
            force.z += velocity.z * -0x1.ff7cecp-1f;
            out->x += force.x;
            out->y += force.y;
            out->z += force.z;
        }
    }
    if (minimum != 0.0f) {
        self->pos.x -= minimum * self->nx;
        self->pos.y -= minimum * self->ny;
        self->pos.z -= minimum * self->nz;
    }
}
