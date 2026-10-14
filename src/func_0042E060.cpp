/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_004C6DF0(int,int,int,float);
extern "C" void func_0042E060(int channel,float volume){
 float scaled=volume*16383.0f;
 func_004C6DF0((int)scaled,channel,0,scaled);
}
