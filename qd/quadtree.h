typedef struct Point {
    int x, y;
    Point(int ax, int ay) { x = ax; y = ay; }
    Point() {x = 0; y = 0; }
} pt;

typedef struct Node {
    pt position;
    int data;
    Node(pt point, int ay) { position = point; data = ay; }
    Node() { data = 0; }
} nd;

class Quad {
public:
    Point topLeft;
    Point bottomRight;

    Node* node;

    Quad* tlTree;
    Quad* trTree;
    Quad* blTree;
    Quad* brTree;

    Quad* Create();
    Quad* Create(pt tl, pt br);

    void InsertNode(nd* node);
    Node* NodeSearch(pt point);
    bool isInBoundary(pt point);
};