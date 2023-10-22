#ifndef ___ENTITY_H___
#define ___ENTITY_H___

class Entity{
    private:
        int x, y;
        char symbol;
      
    public:
        Entity();
        virtual ~Entity();
        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
        char getSymbol();
        void setSymbol(char c);
};

#endif

