#include <stdlib.h>
#include <iostream>

struct Node{
    public:
        Node* parent_;
        Node* leftChild_;
        Node* rightChild_;
        int* data_;
        Node(Node* parent, Node* leftChild, Node* rightChild, int* data){
            parent_ = parent;
            leftChild_ = leftChild;
            rightChild_ = rightChild;
            data_ = data;
        }
};

void makeTree(int** array, int size, Node* node, int Lbound, int Rbound){
    int middle = (Lbound + Rbound)/2;
    if (array[middle] == NULL){
        return;
    }

    node->data_ = array[middle];
    array[middle] = NULL;

    if (array[(middle+Lbound)/2] != NULL){
        node->leftChild_ = new Node(node, NULL, NULL, NULL);
        makeTree(array, size, node->leftChild_, Lbound, middle);
    }

    if (array[(middle+Rbound)/2] != NULL){
        node->rightChild_ = new Node(node, NULL, NULL, NULL);
        makeTree(array, size, node->rightChild_, middle, Rbound);
    }
};

// void printTree(Node* node){
//     if (node->leftChild_ != NULL){
//         printTree(node->leftChild_);
//     }
//     std::cout << *(node->data_) << std::endl;
//     if (node->rightChild_ != NULL){
//         printTree(node->rightChild_);
//     }
// };

void prettyPrintTree(const std::string& prefix, const Node* node, bool isLeft)
{
    if(node != NULL)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << *(node->data_) << std::endl;

        // enter the next tree level - left and right branch
        prettyPrintTree( prefix + (isLeft ? "│   " : "    "), node->leftChild_, true);
        prettyPrintTree( prefix + (isLeft ? "│   " : "    "), node->rightChild_, false);
    }
}
void deleteTree(Node* node){
    node->leftChild_ = NULL;
    node->rightChild_ = NULL;
}

int main(){
    Node root(NULL, NULL, NULL, NULL);
    std::cout << "Вариант 8. Создать идеально сбалансированное дерево из N вершин с заданными значениями\n";
    std::cout << "Введите количество вершин N\n";
    int N;
    std::cin >> N;
    int* numbers[N];
    std::cout << "Введите значения\n";

    
    for(int i = 0; i < N; i++){
        int* znach = new int;
        std::cin >> (*znach);
        numbers[i] = znach;
    }
    std::cout << std::endl;
    
    makeTree(numbers, N, &root, 0, N);
    prettyPrintTree("", &root, false);
    std::cout << "\nРезультат удаления всех вершин кроме корня\n";
    deleteTree(&root);
    prettyPrintTree("", &root, false);
}