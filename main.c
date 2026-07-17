/*"Saya Muhammad Rangga Nur Praditha dengan NIM 2400297 mengerjakan Tugas Masa Depan dalam mata kuliah Dasar-Dasar Pemrograman untuk 
keberkahan-Nya maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan"*/

//memanggil header.h
#include "header.h"

int main(){
    //deklarasi variabel untuk menyimpan data
    int nPelaku = 0, nPelakuComplete = 0, nKorban = 0, nKasus = 0, nTanggal = 0;
    //array untuk menyimpan data pelaku, pelaku lengkap, dan data khusus
    data_Pelaku list_Pelaku[200], list_PelakuComplete[200];
    data_Khusus list_Korban[200], list_Kasus[200], list_Tanggal[200];
    //variabel untuk menyimpan perintah
    char input[2000];
    //variabel untuk melanjutkan atau memberhentikan program
    int lanjutin_Program = 1;

    //membaca data dari file
    read_Pelaku(&nPelaku, list_Pelaku, "Pelaku.txt");
    readKhusus_Pelaku(&nKorban, list_Korban, "Korban.txt");
    readKhusus_Pelaku(&nKasus, list_Kasus, "Kasus.txt");
    readKhusus_Pelaku(&nTanggal, list_Tanggal, "TanggalPenangkapan.txt");
    //gabungkan data pelaku, korban, kasus, dan tanggal penangkapan
    dataGabunganPelaku(list_Pelaku, &nPelaku, list_Korban, nKorban, list_Kasus, nKasus, list_Tanggal, nTanggal);
    //membaca data PelakuComplete.txt
    read_Pelaku(&nPelakuComplete, list_PelakuComplete, "PelakuComplete.txt");

    //tampilan header program
    printf("  ____  _____ _        _    __  __    _  _____   ____    _  _____  _    _   _  ____ \n");
    printf(" / ___|| ____| |      / \\  |  \\/  |  / \\|_   _| |  _ \\  / \\|_   _|/ \\  | \\ | |/ ___|\n");
    printf(" \\___ \\|  _| | |     / _ \\ | |\\/| | / _ \\ | |   | | | |/ _ \\ | | / _ \\ |  \\| | |  _ \n");
    printf("  ___) | |___| |___ / ___ \\| |  | |/ ___ \\| |   | |_| / ___ \\| |/ ___ \\| |\\  | |_| |\n");
    printf(" |____/|_____|_____/_/__ \\_\\_|__|_/_/   \\_\\_|  _|____/_/   \\_\\_/_/ _ \\_\\_| \\_|\\____|\n");
    printf("  |  _ \\_ _| |  _ \\| __ )|  \\/  / ___|  |  _ \\| ____| |      / \\  | |/ / | | | | | |\n");
    printf("  | | | | |  | | | |  _ \\| |\\/| \\___ \\  | |_) |  _| | |     / _ \\ | ' /| | | | | | |\n");
    printf("  | |_| | |  | |_| | |_) | |  | |___) | |  __/| |___| |___ / ___ \\| . \\| |_| |_|_|_| \n");
    printf("  |____/___| |____/|____/|_|  |_|____/  |_|   |_____|_____/_/   \\_\\_|\\_\\___/(_|_|_)\n");
                                                                                    
    //tampilkan menu perintah utama
    printf("\nNotes:\n");
    printf("Input Setiap Kata Dengan Huruf Kapital Atau Kecil Semua Dan Diakhir Kalimat Dengan Titik Koma(;)\n");
    printf("Untuk Data Pelaku Utama Data Yang Dimasukkan Harus 11 Data Yang Berisi :\n");
    printf("\nMenu Perintah Utama:\n");
    printf("\n'INSERT PELAKU' Atau 'insert pelaku' Untuk Menambahkan Data Pelaku Utama\n");
    printf("'UPDATE PELAKU' Atau 'update pelaku' Untuk Mengupdate Data Pelaku Utama\n");
    printf("'DELETE PELAKU' Atau 'delete pelaku' Untuk Menghapus Data Pelaku Utama\n");
    printf("Notes: Setelah Memilih Menu Pelaku, Langsung Masukkan Data Yang Berisi:\n");
    printf("ID, Nama_Pelaku, Korban_Pelaku, Kasus_Pelaku, Tanggal_Penangkapan_Pelaku, Tempat_Penangkapan_Pelaku,\n");
    printf("Jenis_Hukuman_Pelaku, Dan Masa_Hukuman_Pelaku. Untuk Menu Delete Hanya Sampai ID saja\n");
    printf("\n'INSERT DATA KHUSUS' Atau 'insert data khusus' Untuk Menambahkan Data Pelaku Khusus\n");
    printf("'UPDATE DATA KHUSUS' Atau 'update data khusus' Untuk Mengupdate Data Pelaku Khusus\n");
    printf("'DELETE DATA KHUSUS' Atau 'delete data khusus' Untuk Menambahkan Data Pelaku Khusus\n");
    printf("Notes: Untuk Menu Setiap Data Khusus, Pastikan Menulis Data Khusus Yang Diubah Diantaranya:\n");
    printf("'KORBAN' Atau 'korban', 'KASUS' Atau 'kasus', Dan 'TANGGALPENANGKAPAN' Atau 'tanggalpenangkapan'\n");
    printf("Setelah Menulis Menu Data Khusus Dan Memilih Datanya, Langsung Masukkan Kode Dan Nama\n");
    printf("Sedangkan Delete Hanya Kode Saja\n");
    printf("\n'TAMPILKAN DATA' Atau 'tampilkan data' Untuk Menampilkan Data Gabungan\n");
    printf("'TAMPILKAN DATA KORBAN' Atau 'tampilkan data korban' Untuk Menampilkan Data Korban\n");
    printf("'TAMPILKAN DATA KASUS' Atau 'tampilkan data kasus' Untuk Menampilkan Data Kasus\n");
    printf("'TAMPILKAN DATA KORBAN' Atau 'tampilkan data' Untuk Menampilkan Data Tanggal Penangkapan\n");
    printf("'SEMOGA HARIMU MENYENANGKAN' Atau 'semoga harimu menyenangkan' Untuk Mengakhiri Program\n");

    while(lanjutin_Program){
        //menerima input pengguna
        printf("\nMasukkan Perintah: ");
        scanf(" %1999[^\n]s", input);
        printf("\n");

        //menghitung jumlah kata dalam input
        int jumlahKata = 1;//minimal ada satu kata
        for(int i = 0; input[i] != '\0'; i++){//menghitung kata dengan spasi
            if(input[i] == ' '){
                jumlahKata ++;
            }
        }

        //mengecek apakah perintah diakhiri dengan titik koma
        if(input[strlen(input) - 1] != ';'){
            printf("Perintah Harus Diakhiri Dengan Titik Koma (;)\n");
        } 
        else{
            //menghapus titik di akhir input untuk memproses perintah
            input[strlen(input) - 1] = '\0';  

            //mulai mesin kata dengan input yang baru
            STARTKATA(input);

            //mengecek jika perintah sudah berakhir dengan titik koma
            if(EOPKATA(input)){
                RESETKATA();
            }

            //proses perintah berhenti
            if(strcmp(GETCKATA(), "SEMOGA") == 0 || strcmp(GETCKATA(), "semoga") == 0){
                INCKATA(input);
                if(strcmp(GETCKATA(), "HARIMU") == 0 || strcmp(GETCKATA(), "harimu") == 0){
                    INCKATA(input);
                    if(strcmp(GETCKATA(), "MENYENANGKAN") == 0 || strcmp(GETCKATA(), "menyenangkan") == 0){
                        printf("TERIMA KASIH, SELAMAT MENJALANI HARI\n");
                        lanjutin_Program = 0;
                    }
                }
            }
             //memproses perintah untuk insert
            else if(strcmp(GETCKATA(), "INSERT") == 0 || strcmp(GETCKATA(), "insert") == 0){
                INCKATA(input);
                if(strcmp(GETCKATA(), "DATA") == 0 || strcmp(GETCKATA(), "data") == 0){
                    //jika perintah adalah insert untuk data khusus
                    INCKATA(input);
                    if(strcmp(GETCKATA(), "KHUSUS") == 0 || strcmp(GETCKATA(), "khusus") == 0){
                        //memasukkan data khusus
                        if(jumlahKata == 6){
                            insertDataKhusus(input, &nKorban, list_Korban);
                        }
                        else if(jumlahKata < 6){
                            printf("Data Yang Dimasukkan Kurang Harus 6, Yang Dimasukkan %d\n", jumlahKata);
                        }
                        else if(jumlahKata > 6){
                            printf("Data Yang Dimasukkan Lebih Harus 6, Yang Dimasukkan %d\n", jumlahKata);
                        }
                    }
                }
                else{
                    //jika perintah adalah insert untuk data pelaku
                    if(strcmp(GETCKATA(), "PELAKU") == 0 || strcmp(GETCKATA(), "pelaku") == 0){
                        //memasukkan data pelaku
                        if(jumlahKata == 10){
                            insertDataPelaku(input, &nPelaku, list_Pelaku);
                        }
                        else if(jumlahKata < 10){
                            printf("Data Yang Dimasukkan Kurang Harus 10, Yang Dimasukkan %d\n", jumlahKata);
                        }
                        else if(jumlahKata > 10){
                            printf("Data Yang Dimasukkan Lebih Harus 10, Yang Dimasukkan %d\n", jumlahKata);
                        }
                    }
                }
                //menggabungkan data pelaku dan membaca file setelah insert
                dataGabunganPelaku(list_Pelaku, &nPelaku, list_Korban, nKorban, list_Kasus, nKasus, list_Tanggal, nTanggal);
                read_Pelaku(&nPelakuComplete, list_PelakuComplete, "PelakuComplete.txt");
                readKhusus_Pelaku(&nKorban, list_Korban, "Korban.txt");
                readKhusus_Pelaku(&nKasus, list_Kasus, "Kasus.txt");
                readKhusus_Pelaku(&nTanggal, list_Tanggal, "TanggalPenangkapan.txt");
            }
            //memproses perintah untuk update
            else if(strcmp(GETCKATA(), "UPDATE") == 0 || strcmp(GETCKATA(), "update") == 0){
                //jika perintah adalah update untuk data khsus
                INCKATA(input);
                if(strcmp(GETCKATA(), "DATA") == 0 || strcmp(GETCKATA(), "data") == 0){
                    INCKATA(input);
                    if(strcmp(GETCKATA(), "KHUSUS") == 0 || strcmp(GETCKATA(), "khusus") == 0){
                        //memasukkan data khusus
                        if(jumlahKata == 6){
                            updateDataKhusus(input, nKorban, list_Korban);
                        }
                        else if(jumlahKata < 6){
                            printf("Data Yang Dimasukkan Kurang Harus 6, Yang Dimasukkan %d\n", jumlahKata);
                        }
                        else if(jumlahKata > 6){
                            printf("Data Yang Dimasukkan Lebih Harus 6, Yang Dimasukkan %d\n", jumlahKata);
                        }
                    }
                }
                //jika perintah adalah update untuk data pelaku
                else if(strcmp(GETCKATA(), "PELAKU") == 0 || strcmp(GETCKATA(), "pelaku") == 0){
                    //memasukkan data pelaku
                    if(jumlahKata == 10){
                        updateDataPelaku(input, &nPelaku, list_Pelaku);
                    }
                    else if(jumlahKata < 10){
                        printf("Data Yang Dimasukkan Kurang Harus 10, Yang Dimasukkan %d\n", jumlahKata);
                    }
                    else if(jumlahKata > 10){
                        printf("Data Yang Dimasukkan Lebih Harus 10, Yang Dimasukkan %d\n", jumlahKata);
                    }
                }
                //menggabungkan data pelaku dan membaca file setelah update
                dataGabunganPelaku(list_Pelaku, &nPelaku, list_Korban, nKorban, list_Kasus, nKasus, list_Tanggal, nTanggal);
                read_Pelaku(&nPelakuComplete, list_PelakuComplete, "PelakuComplete.txt");
                readKhusus_Pelaku(&nKorban, list_Korban, "Korban.txt");
                readKhusus_Pelaku(&nKasus, list_Kasus, "Kasus.txt");
                readKhusus_Pelaku(&nTanggal, list_Tanggal, "TanggalPenangkapan.txt");
            }
            //memproses perintah untuk delete
            else if(strcmp(GETCKATA(), "DELETE") == 0 || strcmp(GETCKATA(), "delete") == 0){
                INCKATA(input);
                //jika perintah adalah delete untuk data khusus
                if(strcmp(GETCKATA(), "DATA") == 0 || strcmp(GETCKATA(), "data") == 0){
                    INCKATA(input);
                    if(strcmp(GETCKATA(), "KHUSUS") == 0 || strcmp(GETCKATA(), "khusus") == 0){
                        if(jumlahKata == 5){
                            deleteDataKhusus(input, &nKorban, list_Korban);
                        }
                        else if(jumlahKata < 5){
                            printf("Data Yang Dimasukkan Kurang Harus 4, Yang Dimasukkan %d\n", jumlahKata);
                        }
                        else if(jumlahKata > 5){
                            printf("Data Yang Dimasukkan Lebih Harus 4, Yang Dimasukkan %d\n", jumlahKata);
                        }
                    }
                }
                else{
                    //jika perintah adalah delete untuk data pelaku
                    if(strcmp(GETCKATA(), "PELAKU") == 0 || strcmp(GETCKATA(), "pelaku") == 0){
                        if(jumlahKata == 3){
                        deleteDataPelaku(input, &nPelaku, list_Pelaku);
                        }
                        else if(jumlahKata < 3){
                            printf("Data Yang Dimasukkan Kurang Harus 3,Yang Dimasukkan  %d\n", jumlahKata);
                        }
                        else if(jumlahKata > 3){
                            printf("Data Yang Dimasukkan Lebih Harus 3, Yang Dimasukkan %d\n", jumlahKata);
                        }   
                    }
                }
                //menggabungkan data pelaku dan membaca file setelah delete
                dataGabunganPelaku(list_Pelaku, &nPelaku, list_Korban, nKorban, list_Kasus, nKasus, list_Tanggal, nTanggal);
                read_Pelaku(&nPelakuComplete, list_PelakuComplete, "PelakuComplete.txt");
                readKhusus_Pelaku(&nKorban, list_Korban, "Korban.txt");
                readKhusus_Pelaku(&nKasus, list_Kasus, "Kasus.txt");
                readKhusus_Pelaku(&nTanggal, list_Tanggal, "TanggalPenangkapan.txt");
            }
            //memproses perintah untuk menampilkan data
            else if(strcmp(GETCKATA(), "TAMPILKAN") == 0 || strcmp(GETCKATA(), "tampilkan") == 0){
                INCKATA(input);
                if(strcmp(GETCKATA(), "DATA") == 0 || strcmp(GETCKATA(), "data") == 0){
                    INCKATA(input);
                    //jika data korban
                    if(strcmp(GETCKATA(), "KORBAN") == 0 || strcmp(GETCKATA(), "korban") == 0){
                        tabelKhusus(list_Korban, nKorban);
                    }
                    //jika data kasus
                    else if(strcmp(GETCKATA(), "KASUS") == 0 || strcmp(GETCKATA(), "KASUS") == 0){
                        tabelKhusus(list_Kasus, nKasus);
                    }
                    //jika data tanggal
                    else if(strcmp(GETCKATA(), "TANGGALPENANGKAPAN") == 0 || strcmp(GETCKATA(), "tanggalpenangkapan") == 0){
                        tabelKhusus(list_Tanggal, nTanggal);
                    }
                    //jika data pelaku
                    else{
                        tabelPelaku(list_PelakuComplete, nPelakuComplete);
                    }
                }
            }
            //jika perintah tidak sesuai
            else{
                printf("Tidak Ada Perintah Seperti itu\n");
            }
        }
    }

    //jika program selesai
    printf("Program Selesai\n");

    return 0;
}