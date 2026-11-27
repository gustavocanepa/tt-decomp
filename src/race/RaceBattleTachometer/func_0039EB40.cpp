/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Builder { char data[0x990]; };
struct V3 { float x,y,z; };
extern "C" int func_00462798(Builder *, void *);
extern "C" void PGLXshapeBuilder__structor_2(Builder *, int);
extern "C" void func_00462868(Builder *, int);
extern "C" void func_004628B8(Builder *, int);
extern "C" void func_004629F8(Builder *, V3 *, void *, void *, void *);
extern "C" void func_00462C18(Builder *);
extern "C" void *func_004630C8(Builder *, int, int);
extern "C" void func_004A6328(float, float *, float *);
extern "C" void func_0039EB40(char *self) {
 Builder b;
 V3 v;
 float sine, cosine;
 float radius = *(float *)(self+0x74);
 if (!(radius <= 0.0f)) {
  float end = *(float *)(self+0x4c);
  float angle = 0.0f;
  float low = *(float *)(self+0x1c);
  float step = 0.0f;
  float start = *(float *)(self+0x48);
  start += (end-start) * (*(float *)(self+0x7C)-low) / (*(float *)(self+0x20)-low);
  float span = end-start;
  int count = (int)(span * 36.0f / 360.0f);
  float outer = radius + *(float *)(self+0x78);
  if (end <= start) count = 0;
  else {
   if (count < 2) count = 2;
   angle = start * 0x1.1df468p-6f;
   step = span * 0x1.1df468p-6f / (float)count;
  }
  int next = (*(int *)(self+0x64)+1)&1;
  *(int *)(self+0x64) = next;
  func_00462798(&b, ((void **)(self+0x6C))[next]);
  func_004628B8(&b, 0x44);
  func_00462868(&b, 0);
  v.z = 0.0f;
  if (count > 0) {
   for (int i=0; i<count+1; i++) {
    float current=angle;
    angle += step;
    func_004A6328(current, &sine, &cosine);
    float c = cosine;
    float s = sine;
    v.x = c * radius;
    v.y = s * radius;
    c *= outer;
    s *= outer;
    func_004629F8(&b, &v, 0, 0, self+0x80);
    v.x = c;
    v.y = s;
    func_004629F8(&b, &v, 0, 0, self+0x80);
   }
  }
  func_00462C18(&b);
  *(void **)(self+0x68) = func_004630C8(&b,0,0);
  PGLXshapeBuilder__structor_2(&b,2);
 }
}
