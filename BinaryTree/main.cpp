#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Traversal_Recursion.h"
#include "Traversal_Iteration.h"


int main()
{
    int a[5] = {3,2,5,10,9};

    node *root = BinaryTree(a,5);s

    std :: cout << "PrevOrderTraversal" << std :: endl;
    PrevOrderTraversal(root);
    std :: cout << "MiddOrderTraversal" << std :: endl;
    MiddOrderTraversal(root);
    std :: cout << "PostOrderTraversal" << std :: endl;

    std :: cout << "PrevOrderTraversal_Iter" << std :: endl;
    PrevOrderTraversal_Iter(root);
    std :: cout << "MiddOrderTraversal_Iter" << std :: endl;
    MiddOrderTraversal_Iter(root);
    std :: cout << "PostOrderTraversal_Iter" << std :: endl;
    PostOrderTraversal_Iter(root);
    return 0;
}
