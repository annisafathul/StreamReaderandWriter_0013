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

//Menampilkan seluruh data barang dari file gudang.txt
void bacaBarang()
{
    ifstream file("gudang.txt");

    string barang;
    int nomor = 1;

    cout << "\n===== DAFTAR BARANG DI GUDANG =====\n";

    if (!file)
    {
        cout << "Belum ada data barang.\n";
        return;
    }

    while (getline(file, barang))
    {
        cout << nomor++ << ". " << barang << endl;
    }

    file.close();
}

//Menambahkan data barang baru ke file gudang.txt
void tambahBarang()
{
    ofstream file("gudang.txt", ios::app);

    string barang;

    cin.ignore();

    cout << "Masukkan nama barang: ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan.\n";
}

