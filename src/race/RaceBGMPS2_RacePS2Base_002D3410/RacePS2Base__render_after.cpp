/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short delta, index; float (*fn)(void *, float); };
struct O { V *vt; };
struct Handle { int pad; void *ptr; };
struct Race { char pad[0x80]; Handle *course; };
struct Self { char pad[0x6C]; Race *race; };
extern "C" void CourseData__render_after(void *, float, float, float);
static inline float query(O *o, int slot) { V *e = o->vt + slot; return e->fn((char *)o + e->delta, 0.0f); }
extern "C" void RacePS2Base__render_after(Self *self, O *o) {
    void *course = self->race->course->ptr;
    float z = query(o,6);
    float y = query(o,5);
    CourseData__render_after(course, query(o,4), y, z);
}
