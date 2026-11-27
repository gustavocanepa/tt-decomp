/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Car { char pad[0x5C8]; float position; };
struct Entry { char pad[0x18]; Car *car; };
struct Context { char pad[0x80]; void *course; };
extern "C" short func_002E4CB0(void *);
extern "C" float RaceCourse__getCourseLength(void *);
extern "C" float func_002DAA28(Context *ctx, Entry *a, Entry *b) {
    Car *ca = a->car;
    Car *cb = b->car;
    int la = func_002E4CB0(ca);
    int lb = func_002E4CB0(cb);
    float result = 0.0f;
    if (!(la != 0 && lb != 0)) return result;
    float length = RaceCourse__getCourseLength(ctx->course);
    float result_2 = (length * (float)la + ca->position) - (length * (float)lb + cb->position);
    return result_2;
}
