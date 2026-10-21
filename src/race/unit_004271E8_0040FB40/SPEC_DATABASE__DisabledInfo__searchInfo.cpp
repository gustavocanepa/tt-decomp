/* compiler: ee-gcc2.96-nsa-nosib */
struct Info { long code; char other[24]; }; extern char D_00585A30[];
extern "C" int SPEC_DATABASE__DatabaseStorage__getRow(void *,long,Info *);
extern "C" long SPEC_DATABASE__DisabledInfo__searchInfo(long identifier,int kind) {
 long high=identifier>>32;
 if(high==0)return identifier;
 Info info;
 if(!SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30,identifier,&info))return 0;
 return info.code;
}

