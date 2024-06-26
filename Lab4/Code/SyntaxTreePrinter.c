#include "SyntaxTreePrinter.h"
#include "stdio.h"

void printSyntaxTree(Node* node, int depth){
    if(node == NULL){
        return ;
    }
    for(int i = 0; i < depth; i++){
        printf("  ");
    }
    if(!node->is_token){
        printf("%s (%d)\n", node->data.specifier, node->data.lineno);
        for(int i = 0; i < node->child_count; i++){
            printSyntaxTree(node->children[i], depth + 1);
        }
    }
    else{
        printf("%s", node->data.specifier);
        if(strcmp(node->data.specifier, "ID") == 0){
            printf(": %s", node->data.value.string_type);
        }
        else if(strcmp(node->data.specifier, "TYPE") == 0){
            printf(": %s", node->data.value.string_type);
        }
        else if(strcmp(node->data.specifier, "INT") == 0){
            printf(": %d", node->data.value.int_type);
        }
        else if(strcmp(node->data.specifier, "FLOAT") == 0){
            printf(": %.6f", node->data.value.float_type);
        }
        printf("\n");
    }
}