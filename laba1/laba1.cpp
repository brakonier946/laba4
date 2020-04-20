#include <iostream>
#include <iomanip>
#include "work.h"
#include "sortEnum.h"

int main()
{
	work w;

	w.read();

	w.add();
	w.add();

	w.write();

	w.read();

	w.print();


	return 0;
}
