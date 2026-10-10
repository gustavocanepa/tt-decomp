typedef struct { float x, y, w, h; } Rect;
Rect *func_001E4968(void);
void func_001E3EE0(void *self, float *x, float *y) {
    Rect *r = func_001E4968();
    if (*x < r->x) *x = r->x;
    if (*y < r->y) *y = r->y;
    if (r->x + r->w < *x) *x = r->x + r->w;
    if (r->y + r->h < *y) *y = r->y + r->h;
}
