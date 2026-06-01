#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
using namespace std;

class TokoElektronik
{
    private:
    array<string, 3> etalase;

    public:
    TokoElektronik()
    {
        etalase[0] = "Laptop";
        etalase[1] = "Keyboard";
        etalase[2] = "Mouse";
    }

};