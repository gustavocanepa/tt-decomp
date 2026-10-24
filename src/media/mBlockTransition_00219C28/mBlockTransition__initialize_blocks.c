typedef struct {
    char pad0[0x20];
    int rng;
    float spread;
    float slope;
    int pad2c;
    int w;
    int h;
} Grid;
void *BlockUnit__initialize(Grid *, int, int);
float func_00535758(void *, float, float);
void PDISTD__RandomT_PDISTD_RandomUpdateDefault__getRange(void *, float, float, float, float, float);

void mBlockTransition__initialize_blocks(Grid *self) {
    float sx = 640.0f / self->w;
    float sy = 480.0f / self->h;
    int i, j;
    for (j = 0; j < self->h; j++) {
        for (i = 0; i < self->w; i++) {
            void *cell = BlockUnit__initialize(self, i, j);
            float r = func_00535758(&self->rng, 1.0f, self->spread + 1.0f);
            float k = self->slope;
            if (0.0f <= k) {
                r += (float)i / (float)self->w * k;
            } else {
                r += (float)(self->w - i) / (float)self->w * -k;
            }
            PDISTD__RandomT_PDISTD_RandomUpdateDefault__getRange(cell, i * sx, j * sy, sx, sy, r);
        }
    }
}
