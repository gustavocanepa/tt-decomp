/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Inner { char pad[0x24]; float scale; };
struct Obj { Inner *p; char pad[0x18]; int count; char pad20[0x20]; volatile float progress; int cancel; char pad48[0x18]; int current; };
struct Request { int x0,y0,x1,y1,sx,sy,w,h; char *data; int zero,stride,last; char pad[16]; };
extern "C" int func_001A6ED8(Obj *);
extern "C" int func_001A6F20(Obj *);
extern "C" char *malloc(int) throw();
extern "C" void func_004A45D0(void *) throw();
extern "C" void *func_004F6678(void *, int, unsigned);
extern "C" void func_001A58E8(Obj *,int,char *,int) throw();
extern "C" void func_001A5708(char *,char *,char *,int,int,int) throw();
extern "C" void func_001A5BB8(Obj *,char *,int) throw();
extern "C" void func_004A58A0(int);
extern "C" int func_0050E878(int,Request *);
extern char D_005E71B8[], D_005E71C0[];
extern "C" char *func_001A5D30(Obj *o,int dest,int width,int height,int outw,int outh) {
    char *rows[2];
    int cached[2];
    Request req;
    char *err = 0;
    int dx = (width-outw)/2;
    int dy = (height-outh)/2;
    int flag = o->p->scale < 1.0f;
    int inw = func_001A6ED8(o);
    int inh = func_001A6F20(o);
    char *row = malloc(outw*3);
    int index = 0;
    rows[0] = malloc(inw*3);
    rows[1] = malloc(inw*3);
    cached[0] = -1; cached[1] = -1;
    int step = ((inh-1)<<16)/outh;
    int pos = 0;
    for (int y=-dy; y<outh; y++) {
        if (o->cancel) { err=D_005E71B8; break; }
        if (y < -dy) continue;
        int dsty = dy+y;
        if (dsty >= height) break;
        if (y<0) {
            func_004F6678(row,255,outw*3);
        } else {
            int sy = pos>>16;
            if (sy != cached[index]) {
                int next = 1-index;
                if (sy == cached[next]) {
                    cached[index] = sy+1;
                    func_001A58E8(o,flag,rows[index],sy+1);
                    index = next;
                } else {
                    cached[index] = sy;
                    cached[next] = sy+1;
                    func_001A58E8(o,flag,rows[index],cached[index]);
                    func_001A58E8(o,flag,rows[next],cached[next]);
                }
            }
            int weight = 256-((pos>>8)&255);
            pos += step;
            func_001A5708(row,rows[index],rows[1-index],outw,inw,weight);
            func_001A5BB8(o,row,y);
        }
        float progress=(((float)y/(float)outh+(float)o->count)-(float)o->current-1.0f)/(float)o->count;
        if (progress<0.0f) progress=0.0f;
        if (progress>1.0f) progress=1.0f;
        o->progress=progress;
        if (!(y&7)) func_004A58A0(1000);
        int x=dx;
        char *data=row;
        int w=outw;
        if (x<0) { w+=x; data-=dx*3; x=0; }
        req.y0=dsty; req.x0=x; req.y1=dsty+1; req.x1=x+w;
        req.data=data; req.sy=0; req.h=1;
        req.sx=0; req.w=w; req.zero=0; req.stride=w*3; req.last=0;
        if(func_0050E878(dest,&req)) { err=D_005E71C0; break; }
    }
    func_004A45D0(rows[1]); func_004A45D0(rows[0]); func_004A45D0(row);
    return err;
}
