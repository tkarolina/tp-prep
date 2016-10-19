#include "bintree.h"
#include <stdlib.h>

#define ERR(x){ printf(x); return 0; }

void bin_t_print(Tree *t, FILE *out){
    if(t!=NULL){
        bin_t_print(bin_t_get_left(t), out);
        fprintf(out, "%i ", *(int*)bin_t_get_val(t));
        bin_t_print(bin_t_get_right(t), out);
    }
    return;
} 

int cmp(const void* a, const void* b){
    if(*(int*)a>*(int*)b) return 1; else 
    if(*(int*)a<*(int*)b) return -1; else 
        return 0;
}

int main(int argc, char *argv[]){
    FILE* f_in;
    FILE* f_out;

    if(argc<2){
        ERR("error: a few many arguments\n");
    }
    
    if((f_in=fopen(argv[1],"r"))==NULL){
        ERR("error: cant open input file\n");
    }

    if((f_out=fopen(argv[2],"w"))==NULL){
        ERR("error: cant open output file\n");
        fclose(f_in);
    }

    Tree *tree = NULL;
    int x;

    while(fscanf(f_in,"%i",&x)==1){
        bin_t_add(&tree,&x,sizeof(int),cmp);
    }

    bin_t_print(tree, f_out);

    bin_t_clear(tree);

    fclose(f_in);
    fclose(f_out);
    return 0;
}
