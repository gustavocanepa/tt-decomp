
typedef struct Vec3 Vec3;
typedef struct Result Result;
struct Vec3
{
  float x;
  float y;
  float z;
};
struct Result
{
  float u;
  float v;
  float height;
};
inline float root(float value)
{
  float r;
  asm("sqrt.s %0, %1" : "=f"(r) : "f"(value));
  return r;
}

extern "C" int func_0055D478(Result *out, const Vec3 *point, const Vec3 *a, const Vec3 *b, const Vec3 *c, const Vec3 *d)
{
  float ax = c->x - a->x;
  float az = c->z - a->z;
  float bx = b->x - d->x;
  float bz = b->z - d->z;
  if ((((ax == 0) && (az == 0)) && (bx == 0)) && (bz == 0))
  {
    return 0;
  }
  float px = point->x - a->x;
  float pz = point->z - a->z;
  float crossA = (pz * ax) - (px * az);
  if (crossA > 0)
  {
    return 0;
  }
  float qx = b->x - a->x;
  float qz = b->z - a->z;
  float crossQ = (pz * qx) - (px * qz);
  if (crossQ < 0)
  {
    return 0;
  }
  float rx = point->x - d->x;
  float rz = point->z - d->z;
  if (((rz * bx) - (rx * bz)) > 0)
  {
    return 0;
  }
  float dx = c->x - d->x;
  float dz = c->z - d->z;
  if (((rz * dx) - (rx * dz)) < 0)
  {
    return 0;
  }
  float cx = (-dx) - qx;
  float cz = (-dz) - qz;
  float crossC = (pz * cx) - (px * cz);
  if ((ax == 0) && (az == 0))
  {
    out->u = (-crossQ) / crossC;
    out->v = crossC / ((qz * cx) - (qx * cz));
  }
  else
  {
    float detLeft = qz * ax;
    float detRight = qx * az;
    float det = detLeft - detRight;
    float curve = (az * cx) - (ax * cz);
    float sum = crossC + det;
    float difference = det - crossC;
    float discriminant = (sum * sum) + ((crossQ * 4.0f) * curve);
    float r = root(discriminant);
    out->u = (crossA + crossA) / (difference - r);
    out->v = (crossQ * (-2.0f)) / (sum - r);
  }
  float u = out->u;
  float v = out->v;
  float mixed = u * v;
  float oneU = 1.0f - u;
  float oneV = 1.0f - v;
  out->height = point->y - (((((oneU * oneV) * a->y) + ((u * oneV) * b->y)) + ((oneU * v) * c->y)) + (mixed * d->y));
  return 1;
}
