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

bool needToVisitRightNode(int x, int y, int maxLength, const std::vector<std::unique_ptr<Node>> &nodes)
{
  std::cout << "needToVisitRightNode\n";
  return (x + 1 < maxLength && y + 1 == maxLength) &&
    (!nodes.at(translateIndex(x + 1, y, maxLength)));
}

bool needToVisitBelowNode(int x, int y, int maxLength, const std::vector<std::unique_ptr<Node>> &nodes)
{
  std::cout << "needToVisitBelowNode\n";
  return (y + 1 < maxLength && x + 1 == maxLength) &&
    (!nodes.at(translateIndex(x, y + 1, maxLength)));
}

bool needToVisitCentralNode(int x, int y, int maxLength, const std::vector<std::unique_ptr<Node>> &nodes)
{
  std::cout << "needToVisitCentralNode\n";
  return (x + 1 < maxLength && y + 1 < maxLength) &&
                  (!nodes.at(translateIndex(x + 1, y, maxLength)) ||
                   !nodes.at(translateIndex(x, y + 1, maxLength)));
}

bool needToVisitNode(int x, int y, int maxLength, const std::vector<std::unique_ptr<Node>> &nodes)
{
  return needToVisitRightNode(x, y, maxLength, nodes) ||
    needToVisitBelowNode(x, y, maxLength, nodes) ||
    needToVisitCentralNode(x, y, maxLength, nodes);
}

void visit(Node *node, int length, std::vector<std::unique_ptr<Node>> &nodes)
{
  if(!needToVisitNode(node->x, node->y, length, nodes))
  {
    std::cout << "path visited\n";
    return;
  }

  if(node->y < length)
  {
    int belowIndex = translateIndex(node->x, node->y + 1, length);
    std::unique_ptr<Node> &belowNode = nodes.at(belowIndex);
    if(!belowNode)
    {
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
