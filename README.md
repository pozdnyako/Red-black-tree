# Red-black tree
Red-black tree realization in C++

# Example:
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

Function ```cpp rbt::Tree::runDotty()``` need in installed [Gravhviz](https://www.graphviz.org/).
Function ```cpp testingVsMap``` need in installed [gnuplot](http://www.gnuplot.info/).

[insert]: plot/insert.png
[remove]: plot/remove.png
[find]: plot/find.png
