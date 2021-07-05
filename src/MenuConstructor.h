#ifndef MENU_CONSTRUCTOR_H
#define MENU_CONSTRUCTOR_H

class MenuItem {
private:
 MenuItem* parent;
 MenuItem* sibling;
 MenuItem* child;

 void setParent(MenuItem &p);
 void addSibling(MenuItem &s, MenuItem &p);
 
public:
 int name;
 int group;

 MenuItem(int n, int g);

 void addChild(MenuItem &c);

 MenuItem* getChild(int which);
 MenuItem* getSibling(int howfar);
 MenuItem* getParent();
};

#endif // MENU_CONSTRUCTOR_H