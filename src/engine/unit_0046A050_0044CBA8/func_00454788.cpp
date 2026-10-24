/* compiler: ee-gcc2.96-no-strict-aliasing */
struct M { float m[9]; };
extern "C" int func_00454788(M *a, M *c) {
 int r=0; float b;
 b=c->m[0]; if(a->m[0]==b) {
 b=c->m[1]; if(a->m[1]==b) {
 b=c->m[2]; if(a->m[2]==b) {
 b=c->m[3]; if(a->m[3]==b) {
 b=c->m[4]; if(a->m[4]==b) {
 b=c->m[5]; if(a->m[5]==b) {
 b=c->m[6]; if(a->m[6]==b) {
 b=c->m[7]; if(a->m[7]==b) {
 r=1; b=c->m[8]; if(a->m[8]!=b) r=0;
}
}
}
}
}
}
}
}
 return r;
}
