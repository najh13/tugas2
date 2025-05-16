#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama;
    string kode;
    float harga;
    int jumlah;
    Barang* next;
};

void tambahBarang(Barang*& head, string nama, string kode, float harga, int jumlah) {
    Barang* baru = new Barang;
    baru->nama = nama;
    baru->kode = kode;
    baru->harga = harga;
    baru->jumlah = jumlah;
    baru->next = head; 
    head = baru;
}

void tampilkanBarang(Barang* head) {
    Barang* temp = head;
    while (temp != nullptr) {
        cout << "Nama: " << temp->nama << ", Kode: " << temp->kode 
             << ", Harga: " << temp->harga << ", Jumlah: " << temp->jumlah << endl;
        temp = temp->next;
    }
}

void hapusBarang(Barang*& head, string nama) {
    Barang* temp = head;
    Barang* prev = nullptr;

    while (temp != nullptr && temp->nama != nama) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Barang tidak ditemukan!" << endl;
        return;
    }

    if (prev == nullptr) {
        head = temp->next; 
    } else {
        prev->next = temp->next; 
    }

    delete temp; 
    cout << "Barang " << nama << " berhasil dihapus." << endl;
}

int main() {
    Barang* head = nullptr;
    int pilihan;
    string nama, kode;
    float harga;
    int jumlah;

    do {
        cout << "Menu:\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Hapus Barang\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Barang: ";
                cin >> nama;
                cout << "Masukkan Kode Barang: ";
                cin >> kode;
                cout << "Masukkan Harga Barang: ";
                cin >> harga;
                cout << "Masukkan Jumlah Barang: ";
                cin >> jumlah;
                tambahBarang(head, nama, kode, harga, jumlah);
                break;
            case 2:
                cout << "Daftar Barang:\n";
                tampilkanBarang(head);
                break;
            case 3:
                cout << "Masukkan Nama Barang yang ingin dihapus: ";
                cin >> nama;
                hapusBarang(head, nama);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}
