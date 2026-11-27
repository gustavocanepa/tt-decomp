/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Reader { int m0, m4, m8, mode; unsigned char *p; int avail, m18, m1C, eof; };
struct Tile { int offset, w, h, x, y; };
struct Component { int id, h, v, tq, f10, f14; };
struct Frame {
    int ntiles, f4;
    Component comp[3];
    int hmax, vmax, pwidth, pheight;
    unsigned int flags;
};
struct Obj {
    int error, failed;
    char p8[0xA88 - 8];
    Reader rd;
    char pAAC[0xAB0 - 0xAAC];
    int bufsize;
    char pAB4[0xAC0 - 0xAB4];
    int width, height, ncomp, precision;
    char pAD0[0xAFC - 0xAD0];
    Tile tiles[32];
    Frame f;
};
extern "C" int func_004587A0(Obj *) throw();
extern "C" unsigned int func_004599A8(Reader *);
extern "C" int func_00459A38(Reader *);
static inline void error(Obj *self, const int &code) { self->error = code; self->failed = 1; }
extern "C" int func_00458FC8(Obj *self, int tiled) {
    Reader *rd = &self->rd;
    int len = func_00459A38(rd) - 2;
    self->precision = func_004599A8(rd);
    self->height = func_00459A38(rd);
    self->width = func_00459A38(rd);
    int n = func_004599A8(rd);
    self->ncomp = n;
    int r = func_004587A0(self);
    if (r == 0) return r;
    if (n != 1 && n != 3) { error(self, 3); return 0; }
    if (len != n * 3 + 6) goto invalid;
    for (int i = 0; i < n; i++) {
        int id = func_004599A8(rd);
        unsigned int s = func_004599A8(rd);
        self->f.comp[i].id = id;
        self->f.comp[i].h = s >> 4;
        self->f.comp[i].v = s & 0xF;
        self->f.comp[i].tq = func_004599A8(rd);
        self->f.comp[i].f10 = 0;
        self->f.comp[i].f14 = 0;
        if (self->f.hmax < self->f.comp[i].h) self->f.hmax = self->f.comp[i].h;
        if (self->f.vmax < self->f.comp[i].v) self->f.vmax = self->f.comp[i].v;
    }
    r = func_004587A0(self);
    if (r == 0) return r;
    if (self->f.hmax <= 0 || self->f.vmax <= 0) {
invalid:
        error(self, 1);
        return 0;
    }
    int bw = (self->width + 7) >> 3;
    int bh = (self->height + 7) >> 3;
    int mx = (bw + self->f.hmax - 1) / self->f.hmax;
    int my = (bh + self->f.vmax - 1) / self->f.vmax;
    self->f.pheight = my * self->f.vmax * 8;
    self->f.pwidth = mx * self->f.hmax * 8;
    if (tiled) {
        int total = 0;
        int count = 0;
        self->f.pwidth = ((self->f.pwidth + 63) >> 6) << 6;
        for (int y = 0; y < self->f.pheight; y += 256) {
            for (int x = 0; x < self->f.pwidth; x += 512) {
                if (count >= 32) { error(self, 8); return 0; }
                int w = (self->f.pwidth < x + 512 ? self->f.pwidth : x + 512) - x;
                int h = (self->f.pheight < y + 256 ? self->f.pheight : y + 256) - y;
                Tile *t = &self->tiles[count];
                t->offset = total;
                t->w = w;
                t->h = h;
                t->x = x;
                t->y = y;
                total += w * h;
                count++;
                t++;
            }
        }
        self->f.ntiles = count;
    } else {
        Tile *t = self->tiles;
        t->offset = 0;
        t->w = self->f.pwidth;
        t->h = self->f.pheight;
        t->x = 0;
        t->y = 0;
        self->f.ntiles = 1;
    }
    if (self->bufsize < self->f.pwidth * self->f.pheight * 3) { error(self, 6); return 0; }
    self->f.flags |= 8;
    return 1;
}
