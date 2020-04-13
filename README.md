# Red-black tree
[Red-black tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree) realization in C++.

# Example
```cpp
#include <iostream>
#include "Tree.h"

int main() {
  rbt::Tree<int, int> tree;
  
  tree.insert(4, 7);  
  std::cout << "data at key 4:" << *(tree.find(4)) << std::endl;
  tree.remove(4);
}
```

Function ``` rbt::Tree::runDotty()``` need in installed [Gravhviz](https://www.graphviz.org/).

Function ``` testingVsMap() ``` need in installed [gnuplot](http://www.gnuplot.info/).

# Performance
Сomparison rbt::Tree<int, int> with std::map<int,int> realized at ``` testingVsMap() ```:
![insert](https://raw.githubusercontent.com/pozdnyako/Red-black-tree/master/plot/insert.png)
![remove](https://raw.githubusercontent.com/pozdnyako/Red-black-tree/master/plot/remove.png)
![find](https://raw.githubusercontent.com/pozdnyako/Red-black-tree/master/plot/find.png)
