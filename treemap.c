#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {

    //new->lower_than = lower_than;
    
    TreeMap *new = (TreeMap *)malloc(sizeof(TreeMap));

    new->current = NULL;
    new->root = NULL;
    new->lower_than = lower_than;

    return new;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
    if (searchTreeMap(tree, key) == NULL){
        return;
    }
    int valor = 1;
    //crear el nodo, poner los valores en el lugar correcto
    while(valor == 1){
        if (tree->lower_than(key, tree->current->pair->key)){ //si el dato es menor al del arbol
            if (tree->current->left == NULL){
                //tree->current = tree->current->left;
                tree->current->left->left->pair->key = key;
                tree->current->left->left->pair->value = value;
                valor = 0;
            }else{
                tree->current = tree->current->left;
            }


        }else{ //si el dato es mayor al del arbol
            if (tree->current->right == NULL){
                //tree->current = tree->current->right;
                tree->current->right->right->pair->key = key;
                tree->current->right->right->pair->value = value;
                valor = 0;           
            }else{
                tree->current = tree->current->right;
            }
        }    
    }
    return;
}

TreeNode * minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
    tree->current = tree->root;
    int valor = 1;

    while (valor == 1){
        if(is_equal (tree, tree->current->pair->key, key) == 1){
            return tree->current->pair;
        }

        if (tree->lower_than(key, tree->current->pair->key)){ //si el dato es menor al del arbol
            if (tree->current->left != NULL){
                tree->current = tree->current->left;
            }else{
                valor = 0;
            }

        }else{ //si el dato es mayor al del arbol
            if (tree->current->right!= NULL){
            tree->current = tree->current->right;                
            }else{
                valor = 0;
            }
        }

    }
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
