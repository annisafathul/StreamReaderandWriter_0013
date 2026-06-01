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
    
    //jika file belum ada maka tampilkan informasi
    if (!file)
    {
        cout << "Belum ada data barang.\n";
        return;
    }
    //Membaca data barang satu per satu dari file
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

//Mengubah data barang yang sudah ada di file
void updateBarang()
{
    vector<string> daftarBarang;
    string barang;

    ifstream file("gudang.txt");

    while (getline(file, barang))
    {
        daftarBarang.push_back(barang);
    }

    file.close();

    int nomor;

    cout << "Masukkan nomor barang yang ingin diubah: ";
    cin >> nomor;
    
    //Validasi nomor barang
    if (nomor < 1 || nomor > daftarBarang.size())
    {
        cout << "Nomor barang tidak ditemukan.\n";
        return;
    }

    cin.ignore();

    cout << "Masukkan nama barang baru: ";
    getline(cin, barang);
    
    daftarBarang[nomor - 1] = barang;
    
    //Menulis ulang seluruh data ke file
    ofstream simpan("gudang.txt");

    for (string item : daftarBarang)
    {
        simpan << item << endl;
    }

    simpan.close();

    cout << "Data barang berhasil diperbarui.\n";
}

//Menghapus data barang dari file
void hapusBarang()
{
    vector<string> daftarBarang;
    string barang;

    ifstream file("gudang.txt");
    
    //Membaca seluruh data dari file
    while (getline(file, barang))
    {
        daftarBarang.push_back(barang);
    }

    file.close();

    int nomor;

    cout << "Masukkan nomor barang yang ingin dihapus: ";
    cin >> nomor;

    if (nomor < 1 || nomor > daftarBarang.size())
    {
        cout << "Nomor barang tidak ditemukan.\n";
        return;
    }
    //Menghapus data pada posisi yang dipilih
    daftarBarang.erase(daftarBarang.begin() + (nomor - 1));
    
    //Menulis ulang data ke file setelah penghapusan
    ofstream simpan("gudang.txt");

    for (string item : daftarBarang)
    {
        simpan << item << endl;
    }

    simpan.close();

    cout << "Barang berhasil dihapus.\n";
}

//Menguji pengambilan barang dari etalase
void simulasiEtalase()
{
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";
    
    //Skenario 1: Pengambilan barang di rak indeks ke-1
    cout << "\nSkenario 1 (Rak indeks 1)\n";

    try
    {
        cout << "Barang berhasil diambil: "
             << toko.ambilProduk(1)
             << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    
    //Skenario 2: Pengambilan barang di rak indeks ke-5 
    cout << "\nSkenario 2 (Rak indeks 5)\n";

    try
    {
        cout << "Barang berhasil diambil: "
             << toko.ambilProduk(5)
             << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    //Variabel untuk menyimpan pilihan menu
    int pilihan;

    do
    { 
        //Menampilkan daftar barang setiap kali menu dibuka
        bacaBarang();

        cout << "\n===== TOKO ELEKTRONIK GIBRAN JAYA =====\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Update Barang\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Simulasi Etalase\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        
        //Menjalankan fitur sesuai pilihan
        switch (pilihan)
        {
        case 1:
            tambahBarang();
            break;

        case 2:
            updateBarang();
            break;

        case 3:
            hapusBarang();
            break;

        case 4:
            simulasiEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}