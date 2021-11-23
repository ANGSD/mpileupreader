#include <cstdio>
#include <zlib.h>
#include <cstring>
#include <cstdlib>

#define LENS 4096


int main(int argc,char **argv){

  //is input a terminal?
  int isterm= isatty(fileno(stdin));
  fprintf(stderr,"isterm: %d argc: %d\n",isterm,argc);
  if(argc>1 && isterm==0 ||argc==1&&isterm){
    fprintf(stderr,"\t1) ./mpileupreader file.gz\n\t2) cat file.gz|./mpileupreader\n");
    return 0;
  }
  gzFile gz = Z_NULL;
  char buf[LENS];
  if(argc>1)
    gz = gzopen(argv[1],"rb");
  else
    gz = gzdopen(fileno(stdin),"rb");

  if(gz==Z_NULL){
    fprintf(stderr,"\t-> Problem opening inputfile or inputstream\n");
    return 0;
  }


  while(gzgets(gz,buf,LENS)){
    if(strlen(buf)>4096-5){
      fprintf(stderr,"\t-> Problem parsing inputfile, increase buffer size\n");
      return 1;
    }
    char *chr = strtok(buf,"\n\t ");
    int pos = atoi(strtok(NULL,"\n\t "));
    char ref = strtok(NULL,"\n\t ")[0];
    fprintf(stderr,"chr: %s pos: %d ref: %c\n",chr,pos,ref);
    char *tmp = NULL;
    int intid = 0;
    while(((tmp = strtok(NULL,"\n\t ")))){
      int idep = atoi(tmp);
      char *mpil = strtok(NULL,"\n\t ");
      char *qscores = strtok(NULL,"\n\t ");
      fprintf(stderr,"intid[%d] idep: %d mpil: %s qscores: %s\n",intid++,idep,mpil,qscores);
    }
  }
  
  return 0;
}
