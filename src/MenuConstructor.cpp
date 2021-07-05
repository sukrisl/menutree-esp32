#include "MenuConstructor.h"

MenuItem::MenuItem(int n, int g) {
    parent = nullptr;
    sibling = nullptr;
    child = nullptr;
    name = n;
    group = g;
}

void MenuItem::setParent(MenuItem &p) {
    parent = &p;
}

void MenuItem::addSibling(MenuItem &s, MenuItem &p) {
    if (sibling) {
        sibling->addSibling(s, p);
    } else {
        sibling = &s;
        sibling->setParent(p);
    }
}

void MenuItem::addChild(MenuItem &c) {
    if (child) {
        child->addSibling(c, *this);
    } else {
        child = &c;
        child->setParent(*this);
    }
}

MenuItem* MenuItem::getChild(int which) {
    if (child) {
        return child->getSibling(which);
    } else {
        return nullptr;
    }
}

MenuItem* MenuItem::getSibling(int howfar) {
    if (howfar == 0) {
        return this;
    } else if (sibling) {
        return sibling->getSibling(howfar-1);
    } else {
        return nullptr;
    }
}

MenuItem* MenuItem::getParent() {
    if (parent) {
        return parent;
    } else {
        return this;
    }
}