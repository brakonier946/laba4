#include <iostream>
#include "work.h"

int main()
{
    work w;

    w.add();
    w.add();
    w.add();
    w.add();

    w.write();

    cout << endl << endl;
    w.print();

    w.sort(typeSort::nameProperty);


    cout << endl << endl;
    w.print();

    w.printAt(3);
    w.printAt(1);

    return 0;
}
