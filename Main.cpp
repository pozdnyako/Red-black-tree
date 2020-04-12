// Main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Tree.h"
#include <ctime>

int main() {
    rbt::Tree<int, int> tree;

    tree.insert(1, 0);
    tree.insert(5, 0);
    tree.insert(9, 0);
    tree.insert(8, 0);
    tree.insert(2, 0);
    tree.insert(10, 0);
    tree.insert(4, 0);
    tree.insert(6, 0);
    tree.insert(3, 0);
    tree.insert(7, 5);

    int *data = tree.find(7);
    std::cout << "data: " << (*data) ;

    tree.remove(9);
    tree.remove(5);
    tree.remove(1); 
    tree.remove(2);
    tree.remove(3);

    tree.runDotty();
}
