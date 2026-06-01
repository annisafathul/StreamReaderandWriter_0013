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
    //Mengambil produk berdasarkan nomor rak
    string ambilProduk(size_t nomorRak)
    {
        try
        {
            //Mengakses Array menggunakan at()
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&)
        {
            //Melempar pesan error kustom jika indeks tidak valid
            throw runtime_error(
                "Gagal Mengambil Barang : Rak nomor " +
                to_string(nomorRak) +
                " kosong atau tidak tersedia!");
        }
    }

};