/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Light { float x,y,z,k; float a,b,c,d; float e,f,g,h; float i,j,l,m; };
struct Obj { char pad[0xC60]; Light light[8]; };
extern "C" void func_00390328(int,int,float,float,float,float,float,float,float,float,float,float,float,float,float);
extern "C" void func_0034E4F8(Obj *self,int arg) {
    for (int n=0;n<8;n++) {
        func_00390328(arg,n,
            self->light[n].x*self->light[n].k,
            self->light[n].y*self->light[n].k,
            self->light[n].z*self->light[n].k,
            self->light[n].a,self->light[n].b,
            self->light[n].c,self->light[n].d,
            self->light[n].e,self->light[n].f,
            self->light[n].g,self->light[n].h,
            self->light[n].i,self->light[n].j);
    }
}
