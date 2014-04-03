#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

struct Node
{
  int x = 0;
  int y = 0;
};

int translateIndex(int x, int y, int maxLength)
{
  std::cout << "(" << x << "," << y << ") -> " << (x * maxLength + y) << "\n";
  return x * maxLength + y;
}

void visit(Node *node, int length, std::vector<std::unique_ptr<Node>> &nodes)
{
  if(node->y < length)
  {
    int belowIndex = translateIndex(node->x, node->y + 1, length);
    std::unique_ptr<Node> &belowNode = nodes.at(belowIndex);
    if(!belowNode)
    {
      std::cout << "criei below\n";
      belowNode = std::unique_ptr<Node>(new Node());
      belowNode->x = node->x;
      belowNode->y = node->y + 1;
    }

    visit(belowNode.get(), length, nodes);
  }

  if(node->x < length)
  {
    int rightIndex = translateIndex(node->x + 1, node->y, length);
    std::unique_ptr<Node> &rightNode = nodes.at(rightIndex);
    if(!rightNode)
    {
      std::cout << "criei right\n";
      rightNode = std::unique_ptr<Node>(new Node());
      rightNode->x = node->x + 1;
      rightNode->y = node->y;
    }

    visit(rightNode.get(), length, nodes);
  }
}

int visit(std::unique_ptr<Node> node, int maxLength)
{
  std::vector<std::unique_ptr<Node>> nodes;
  nodes.resize((maxLength+1)*(maxLength+1));
  nodes.at(0) = std::move(node);
  visit(nodes.at(0).get(), maxLength, nodes);
  return 0;//nodes.at(0)->visitedNodes;
}


int main(int argc, char **argv)
{
  std::stringstream formatter;
  formatter << argv[1];
  int maxLength;
  formatter >> maxLength;

  auto root = std::unique_ptr<Node>(new Node());
  std::cout << "Max paths: " << visit(std::move(root), maxLength) << std::endl;

  return 0;
}
