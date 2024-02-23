#include "quadtree.h"

Quad* Quad::Create() {
    Quad* quadTree = static_cast<Quad*>(malloc(sizeof(Quad)));
    quadTree->topLeft       = pt();
    quadTree->bottomRight   = pt();
    quadTree->node          = nullptr;

    quadTree->tlTree = nullptr;
    quadTree->trTree = nullptr;
    quadTree->blTree = nullptr;
    quadTree->brTree = nullptr;

    return quadTree;
}

Quad* Quad::Create(pt tl, pt br) {
    Quad* quad = Quad::Create();
    quad->topLeft = tl;
    quad->bottomRight = br;

    return quad;
}

void Quad::InsertNode(nd* node) {

    if (node == nullptr) return;
    if (!Quad::isInBoundary(node->position)) return;

    if (abs(topLeft.x - bottomRight.x) <= 1 && abs(topLeft.y - bottomRight.y) <= 1) 
    {
        if (node == nullptr) this->node = node;
        return;
    }
    if ((topLeft.x + bottomRight.x) / 2 >= node->position.x)
    {
        if ((topLeft.y + bottomRight.y) / 2 >= node->position.y) {
            if (tlTree == nullptr) 
                tlTree = Quad::Create(
                    pt(topLeft.x, topLeft.y), 
                    pt((topLeft.x + bottomRight.x) / 2, (topLeft.y + bottomRight.y) / 2));
                    
            tlTree->InsertNode(node);
        }
        else {
            if (blTree == nullptr) 
                blTree = Quad::Create(
                    pt(topLeft.x, (topLeft.y + bottomRight.y) / 2),
                    pt((topLeft.x + bottomRight.x) / 2, bottomRight.y));
                    
            blTree->InsertNode(node);
        }
    }
    else {}

}

bool Quad::isInBoundary(pt point) {
    return false;
}