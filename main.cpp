#include <iostream>
#include "list.h"
#include <fstream>

using namespace std;

int main(){
    List beiju;
    beiju.insert(5);
    beiju.insert(4);
    beiju.insert(3);
    beiju.insert(5);
    beiju.insert(8);
    beiju.insert(2);
    beiju.print_all();
}