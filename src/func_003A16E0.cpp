/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline int longitudinal(float b, float d, float e) {
    if (d*4.0f < b) return 6;
    if (d < b) return 5;
    if (0.0f < b) return 4;
    float t=-e;
    if (t <= b) return 3;
    if (t*4.0f <= b) return 2;
    return 1;
}
extern "C" int func_003A16E0(float a,float b,float c,float d,float e,float f) {
    if (a>50.0f) return 0;
    int r=longitudinal(b,d,e);
    float u=-f;
    if (c<u*4.0f) r |= 0x10;
    else if(c<u) r |= 0x20;
    else if(c<u*0.5f) r |= 0x30;
    else if(c<=f*0.5f) r |= 0x40;
    else if(c<=f) r |= 0x50;
    else if(c<=f*4.0f) r |= 0x60;
    else r |= 0x70;
    return r;
}
