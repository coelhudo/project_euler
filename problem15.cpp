#include <iostream>
#include <memory>
#include <sstream>

struct Node
{
  std::unique_ptr<Node> below;
  std::unique_ptr<Node> right;
  int x = 0;
  int y = 0;
  bool belowVisited = false;
  bool rightVisited = false;
};

void visit(Node &node, int length, int max, int &count)
{
  if(!node.below)
  {
    node.below = std::unique_ptr<Node>(new Node());
    node.below->y = node.y + 1;
    node.below->x = node.x;
  }

  if(node.y < length)
  {
    node.belowVisited = true;
    visit(*node.below, length, max + 1, count);
  }

  if(!node.right)
  {
    node.right = std::unique_ptr<Node>(new Node());
    node.right->x = node.x + 1;
    node.right->y = node.y;
  }

  if(node.x < length )
  {
    node.rightVisited = true;
    visit(*node.right, length, max + 1, count);
  }

  if(max == (length * 2))
  {
    ++count;
  }
}

int visit(Node &node, int maxLength)
{
  int count = 0;
  visit(node, maxLength, 0, count);
  return count;
}


int main(int argc, char **argv)
{
  std::stringstream formatter;
  formatter << argv[1];
  int maxLength;
  formatter >> maxLength;

  auto root = std::unique_ptr<Node>(new Node());
  std::cout << "Max paths: " << visit(*root, maxLength) << std::endl;

  return 0;
}
