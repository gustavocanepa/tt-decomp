/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Curve { float x0,x1,y0,y1; };
extern "C" float func_00318138(Curve *p, float x) {
    float result;
    float hiY;
    float hiX;
    float loY;
    float loX;
    loX = 0.0f;
    hiX = p->x0;
    loY = 0.0f;
    hiY = p->y0;
    result = 0.0f;
    if (x <= 0.0f) x = 0.0f;
    if (x >= 1.0f) x = 1.0f;
    if (hiX < x) {
        loX = hiX;
        hiX = p->x1;
        loY = hiY;
        hiY = p->y1;
    }
    if (p->x1 < x) {
        loX = hiX;
        hiX = 1.0f;
        loY = hiY;
        hiY = 1.0f;
    }
    if (hiX <= loX) return result;
    return ((hiY-loY)*(x-loX))/(hiX-loX)+loY;
}
