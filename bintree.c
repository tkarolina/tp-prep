#include "bintree.h"
#include <stdlib.h>
#include <string.h>


Tree *create_node(){
    Tree *t = NULL;
    t = (Tree*)calloc(1,sizeof(Tree));
    return t;
}

void bin_t_clear(Tree* root){
    if(root!=NULL){
        bin_t_clear(root->left);
        bin_t_clear(root->right);
        free(root->val);
        free(root);
    }
    return;
}

void bin_t_add(Tree** root, void *x, size_t size, int (*cmp)(const void *a, const void *b)){
    Tree *tmp = *root;
    Tree *parent = NULL;
    int f = 0;
    while(tmp!=NULL){
        if(cmp(tmp->val,x)==-1){
            parent = tmp;
            tmp = tmp->right;
            f = 2;
        } else
        if(cmp(tmp->val,x)==1){
            parent = tmp;
            tmp = tmp->left;
            f = 1;
        } else
        {
            memcpy(tmp->val, x, size);
            return;
        }
    }
    Tree *t = create_node();
    t->val = malloc(sizeof(size));
    memcpy(t->val, x, size);
    t->parent = parent;
    if(parent!=NULL){
        if(f==1){
            parent->left = t;
        } else 
            parent->right = t;
    } else {
        *root=t;     
    }
    return;
}

void *bin_t_get_val(Tree *x){
    return x->val;
}

Tree *bin_t_get_left(Tree *x){
    return x->left;
}

Tree *bin_t_get_right(Tree *x){
    return x->right;
}

Tree *bin_t_get_parent(Tree *x){
    return x->parent;
}

