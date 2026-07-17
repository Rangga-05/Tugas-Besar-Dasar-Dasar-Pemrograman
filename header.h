/*"Saya Muhammad Rangga Nur Praditha dengan NIM 2400297 mengerjakan Tugas Masa Depan dalam mata kuliah Dasar-Dasar Pemrograman untuk 
keberkahan-Nya maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan"*/

//header atau library
#include <stdio.h>
#include <string.h>

//bungkusan untuk data pelaku
typedef struct{
    //variabel data untuk menyimpan data pelaku
    char noID_Pelaku[20], nama_Pelaku[200], korban_Pelaku[200], kasus_Pelaku[200], tanggalPenangkapan_Pelaku[50], tempat_Pelaku[200], jenisHukuman_Pelaku[200], masaHukuman_Pelaku[100];
}data_Pelaku;

//bungkusan untuk data khusus
typedef struct{
    //variabel data untuk menyimpan data khusus 
    char kode_Data[20], nama_Data[200];
}data_Khusus;

//variabel global untuk mesin kata
extern int indeks, panjangKata;
//indeks untuk mencari posisi karakter dalam pita(input)
//panjang kata untuk menyimpan panjang kata
extern char ckata[1000];
//ckata untuk menyimpan kata yang sedang diproses

//fungsi untuk mendapatkan kata yang sedang diproses
char* GETCKATA();
//fungsi untuk mendapatkan panjang kata saat ini
int GETPANJANGKATA();
//mengecek EOP pada input
int EOPKATA(char pita[]);
//fungsi untuk memulai mesin kata
void STARTKATA(char pita[]);
//fungsi untuk mereset kata saat ini
void RESETKATA();
//fungsi untuk berpindah ke kata berikutnya
void INCKATA(char pita[]);
//fungsi untuk membaca file data khusus pelaku
void readKhusus_Pelaku(int *n, data_Khusus listKhusus_Pelaku[], char khususPelaku[]);
//fungsi untuk membaca file data pelaku seluruhnya
void read_Pelaku(int *n, data_Pelaku list_Pelaku[], char pelaku[]);
//fungsi untuk mengurutkan data khusus
void sortDataKhusus(int nData, data_Khusus listKhusus[]);
//fungsi untuk menambahkan data khusus
void insertDataKhusus(char *pita, int *nData, data_Khusus listKhusus[]);
//fungsi untuk mengupdate data khusus
void updateDataKhusus(char *pita, int nData, data_Khusus listKhusus[]);
//fungsi untuk mengecek apakah kode korban, kasus, atau tanggal penangkapan sedang digunakan di Pelaku.txt
int cekKodeTerpakai(char *kode);
//fungsi untuk menghapus data khusus
void deleteDataKhusus(char *pita, int *nData, data_Khusus listKhusus[]);
//fungsi untuk memeriksa apakah kode terdapat dalam file khusus
int cekKodeValid(char *fileName, char *kode);
//fungsi untuk mengurutkan data pelaku
void sortDataPelaku(int nData, data_Pelaku listPelaku[]);
//fungsi untuk menambahkan data pelaku
void insertDataPelaku(char *pita, int *nData, data_Pelaku listPelaku[]);
//fungsi untuk mengupdate data pelaku
void updateDataPelaku(char *pita, int *nData, data_Pelaku listPelaku[]);
//fungsi untuk menghapus data pelaku
void deleteDataPelaku(char *pita, int *nData, data_Pelaku listPelaku[]);
//fungsi untuk menggabungkan data korban, kasus, dan tanggal penangkapan ke dalam data pelaku
void dataGabunganPelaku(data_Pelaku dataPelaku[], int *nPelaku, data_Khusus dataKorban[], int nKorban, data_Khusus dataKasus[], int nKasus, data_Khusus dataTanggalPenangkapan[], int nTanggalPenangkapan);
//fungsi untuk menampilkan tabel data khusus
void tabelKhusus(data_Khusus listData[], int nData);
//fungsi untuk menampilkan tabel ddata pelaku
void tabelPelaku(data_Pelaku listPelakuComplete[], int nPelakuComplete);