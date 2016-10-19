#include <stdio.h>


struct bin_tree {
    struct bin_tree *parent;
    void *val;
    struct bin_tree *left;
    struct bin_tree *right;
};

typedef struct bin_tree Tree;

Tree *create_node();
void bin_t_clear(Tree*);
void bin_t_add(Tree**, void*, size_t, int(*)(const void*, const void*));
Tree *bin_t_get_left(Tree*);
Tree *bin_t_get_right(Tree*);
Tree *bin_t_get_parent(Tree*);
void *bin_t_get_val(Tree*);

