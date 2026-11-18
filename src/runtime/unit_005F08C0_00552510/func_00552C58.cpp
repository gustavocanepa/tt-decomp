/* compiler: ee-gcc2.9-991111 */
/* Accumulates a 3D float vector into another (component-wise addition) and
   returns the destination pointer. */

typedef struct Vec3 Vec3;
typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern Vec3 *func_00552C58(Vec3 *a0, const Vec3 *a1) {
    Vec3 *v0 = a0;
    v0->z += a1->z;
    v0->y += a1->y;
    v0->x += a1->x;
    do { } while (0);
    return v0;
}
