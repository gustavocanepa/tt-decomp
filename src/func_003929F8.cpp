/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char pad[0xC]; float x,y,z,p18,vx,vy,vz,scale,drag; char pad2[0x40-0x30]; float life; };
extern "C" void GT4Model__BinStreamWriter__writeFloat(int,float);
extern "C" void func_00423BD0(int,int);
extern "C" void func_00423BB0(int,int);
static inline const int &minimum(const int &a,const int &b) { return b<a?b:a; }
static inline const int &maximum(const int &a,const int &b) { return a<b?b:a; }
extern "C" void SparkParticle__write(Self *s,int stream) {
 GT4Model__BinStreamWriter__writeFloat(stream,s->x);
 GT4Model__BinStreamWriter__writeFloat(stream,s->y);
 GT4Model__BinStreamWriter__writeFloat(stream,s->z);
 func_00423BD0(stream,maximum(minimum((int)(s->vx*4.0f),127),-128));
 func_00423BD0(stream,maximum(minimum((int)(s->vy*4.0f),127),-128));
 func_00423BD0(stream,maximum(minimum((int)(s->vz*4.0f),127),-128));
 func_00423BB0(stream,maximum(minimum((int)(s->drag*256.0f/0x1.47ae14p-6f),255),0));
 func_00423BB0(stream,maximum(minimum((int)(s->life*256.0f*0.5f),255),0));
}
