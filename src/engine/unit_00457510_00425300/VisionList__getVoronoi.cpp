/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Point { int tag; float x,y,z; };
struct Vision { char pad[16]; unsigned short w,h; Point ***cells; float x,z; char pad20[8]; float sx,sz; };
extern float D_00600840;
static inline int clamp(int v, int lo, int hi) {
    if (v < lo) return lo;
    if (hi < v) v = hi;
    return v;
}
extern "C" Point *VisionList__getVoronoi(Vision *p, float x, float y, float z) {
    float px=x-p->x;
    float pz=z-p->z;
    int w=p->w;
    int h=p->h;
    int ix = (int)(px * (float)w * p->sx);
    int iz = (int)(pz * (float)h * p->sz);
    if(ix<0) ix=0;
    else if(w-1<ix) ix=w-1;
    if(iz<0) iz=0;
    else if(h-1<iz) iz=h-1;
    Point **list = p->cells[iz*w+ix];
    float bestDist = D_00600840;
    Point *best = *list;
    Point *cur = best;
    Point *next;
    if (cur) {
        do {
            float dx = cur->x-x;
            float dy = cur->y-y;
            float dz = cur->z-z;
            float d = dx*dx + dy*dy + dz*dz;
            ++list;
            if(d < bestDist) { bestDist=d; best=cur; }
            next=*list;
            cur=next;
        } while(next);
    }
    return best;
}
