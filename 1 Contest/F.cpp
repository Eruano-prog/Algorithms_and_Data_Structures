#include stdio.h

struct Fridge{
    int milk;
    int meat;
    int cheese;
    int yummies;
};

int main() {

    struct Fridge my_fridge;
    my_fridge.meat = 5;
    my_fridge.cheese = 10;
    my_fridge.yummies = 23;
    my_fridge.yummies += 10;
    my_fridge.cheese -= 5;

    printf(%d %d %d, my_fridge.meat, my_fridge.cheese, my_fridge.yummies);
    return 0;
}
