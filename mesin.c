/*"Saya Muhammad Rangga Nur Praditha dengan NIM 2400297 mengerjakan Tugas Masa Depan dalam mata kuliah Dasar-Dasar Pemrograman untuk 
keberkahan-Nya maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan"*/

//memanggil header.h
#include "header.h"

//variabel global untuk mesin kata
int indeks, panjangKata;
//indeks untuk mencari posisi karakter dalam pita(input)
//panjang kata untuk menyimpan panjang kata
char ckata[1000];
//ckata untuk menyimpan kata yang sedang diproses

//fungsi untuk mendapatkan kata yang sedang diproses
char* GETCKATA(){
    return ckata;
}

//fungsi untuk mendapatkan panjang kata saat ini
int GETPANJANGKATA(){
    return panjangKata;
}

//mengecek EOP pada input
int EOPKATA(char pita[]){
    if(pita[indeks] == ';'){
        return 1;
    }
    else{
        return 0;
    }
}

//fungsi untuk memulai mesin kata
void STARTKATA(char pita[]){
    indeks = 0;
    panjangKata = 0;
    //lewati spasi awal
    while(pita[indeks] == ' ' || pita[indeks] == '\n'){
        indeks++;
    }
    //ambil karakter hingga spasi atau eop
    while(pita[indeks] != ' ' && pita[indeks] != ';' && pita[indeks] != '\0'){
        ckata[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }
    ckata[panjangKata] = '\0'; //akhiri string
}

//fungsi untuk mereset kata saat ini
void RESETKATA(){
    panjangKata = 0;
    ckata[panjangKata] = '\0';
}

//fungsi untuk berpindah ke kata berikutnya
void INCKATA(char pita[]){
    panjangKata = 0;
    //lewati spasi
    while(pita[indeks] == ' ' || pita[indeks] == '\n'){
        indeks++;
    }
    //ambil karakter hingga spasi atau tanda EOP
    while(pita[indeks] != ' ' && pita[indeks] != ';' && pita[indeks] != '\0'){
        ckata[panjangKata] = pita[indeks];
        indeks++;
        panjangKata++;
    }
    ckata[panjangKata] = '\0';//akhiri string
}

//fungsi untuk membaca file data khusus pelaku
void readKhusus_Pelaku(int *n, data_Khusus listKhusus_Pelaku[], char khususPelaku[]){
    FILE *fTemp;//deklarasi pointer file
    fTemp = fopen(khususPelaku, "r");//membuka file mode baca

    if(fTemp == 0){//cek file berhasil dibuka
        printf("File Gagal Dibuka: %s\n", khususPelaku);
        return;
    }

    //reset jumlah data
    *n = 0;//inisialisasi jumlah data ke nol

    //membaca data
    int selesai = 0;//indikator untuk menyelesaikan pembacaan
    while(selesai == 0){//loop pembacaan file
        int returnVal = fscanf(fTemp, "%s %s", listKhusus_Pelaku[*n].kode_Data, listKhusus_Pelaku[*n].nama_Data);//membaca string dari file

        //cek jika data tidak valid atau dummy ditemukan
        if(returnVal != 2 || strcmp(listKhusus_Pelaku[*n].kode_Data, "####") == 0){//jika data kurang dari dua string atau sampai tanda dummy
            selesai = 1;//mengakhiri loop jika data tidak valid atau dummy ditemukan
        } 
        else{
            *n = *n + 1;//tambah jumlah data saat data valid
        }
    }

    fclose(fTemp);//tutup file
}

//fungsi untuk membaca file data pelaku seluruhnya
void read_Pelaku(int *n, data_Pelaku list_Pelaku[], char pelaku[]){
    FILE *fTemp;//deklarasi pointer file
    fTemp = fopen(pelaku, "r");//membuka file dengan mode baca

    if(fTemp == 0){//cek file berhasil dibuka
        printf("File Gagal Dibuka: %s\n", pelaku);
        return;
    }

    //reset jumlah data
    *n = 0;//inisialisasi jumlah data ke nol

    //membaca data
    int selesai = 0;//indikator untuk menyelesaikan pembacaan
    while(selesai == 0){//loop pembacaan file
        //membaca string dari file
        int returnVal = fscanf(fTemp, "%s %s %s %s %s %s %s %s", list_Pelaku[*n].noID_Pelaku, list_Pelaku[*n].nama_Pelaku, list_Pelaku[*n].korban_Pelaku, list_Pelaku[*n].kasus_Pelaku, list_Pelaku[*n].tanggalPenangkapan_Pelaku, list_Pelaku[*n].tempat_Pelaku, list_Pelaku[*n].jenisHukuman_Pelaku, list_Pelaku[*n].masaHukuman_Pelaku);

        //cek jika data tidak valid atau dummy ditemukan
        if(returnVal != 8 || strcmp(list_Pelaku[*n].noID_Pelaku, "####") == 0){//jika data kurang dari delapan string atau sampai tanda dummy
            selesai = 1;//mengakhiri loop jika data tidak valid atau dummy ditemukan
        } 
        else{
            *n = *n + 1;//tambah jumlah data saat data valid
        }
    }

    fclose(fTemp);//tutup file
}

//fungsi untuk mengurutkan data khusus
void sortDataKhusus(int nData, data_Khusus listKhusus[]){
    //implementasi pengurutan berdasarkan kode_Data
    for(int i = 0; i < nData - 1; i++){//loop pertama untuk elemen pertama
        for(int j = i + 1; j < nData; j++){//loop kedua untuk membandingkan elemen saat ini
            if(strcmp(listKhusus[i].kode_Data, listKhusus[j].kode_Data) > 0){//bandingkan kode data secara urut
                //tukar posisi jika urutam tidak sesuai
                data_Khusus temp = listKhusus[i];//simpan elemen sementara
                listKhusus[i] = listKhusus[j];//tukar posisi elemen
                listKhusus[j] = temp;//kembalikan elemen sementara
            }
        }
    }
}

//fungsi untuk menambahkan data khusus
void insertDataKhusus(char *pita, int *nData, data_Khusus listKhusus[]){
    data_Khusus dataBaru;//variabel untuk menyimpan data baru
    char fileKeinginan[50];//variabel untuk menyimpan nama file tujuan
    int adaID = 0;//menandakan apakah ID duplikat ditemukan

    STARTKATA(pita);//mulai mesin kata

    if(strcmp(GETCKATA(), "INSERT") == 0 || strcmp(GETCKATA(), "insert") == 0){
        INCKATA(pita);//maju ke kata berikutnya
        if(strcmp(GETCKATA(), "DATA") == 0 || strcmp(GETCKATA(), "data") == 0){
            INCKATA(pita);//maju ke kata berikutnya
            if(strcmp(GETCKATA(), "KHUSUS") == 0 || strcmp(GETCKATA(), "khusus") == 0){
                INCKATA(pita);//maju ke kata berikutnya

                if(strcmp(GETCKATA(), "KORBAN") == 0 || strcmp(GETCKATA(), "korban") == 0){
                    strcpy(fileKeinginan, "Korban.txt");
                }
                else if(strcmp(GETCKATA(), "KASUS") == 0 || strcmp(GETCKATA(), "kasus") == 0){
                    strcpy(fileKeinginan, "Kasus.txt");
                }
                else if(strcmp(GETCKATA(), "TANGGALPENANGKAPAN") == 0 || strcmp(GETCKATA(), "tanggalpenangkapan") == 0){
                    strcpy(fileKeinginan, "TanggalPenangkapan.txt");
                }
                else{
                    printf("File Tidak Valid, Silahkan Masukkan Dengan Benar\n");
                    return;
                }

                //baca data yang ada di file
                readKhusus_Pelaku(nData, listKhusus, fileKeinginan);

                INCKATA(pita);//maju ke kata berikutnya(kode data)
                if(GETCKATA() != 0){//cek jika ada kode data
                    strcpy(dataBaru.kode_Data, GETCKATA());//salin kode data

                    //mengecek apakah kode data sudah ada
                    for(int i = 0; i < *nData; i++){
                        if(strcmp(listKhusus[i].kode_Data, dataBaru.kode_Data) == 0){
                            adaID = 1;//Kode ditemukan
                        }
                    }

                    if(adaID == 1){//jika kode ditemukan
                        printf("Kode data %s Sudah Digunakan, Silahkan Gunakan Kode Lain\n", dataBaru.kode_Data);
                        return;//hentikan proses
                    }

                    INCKATA(pita);//maju ke kata berikutnya(nama data)
                    if(GETCKATA() != 0){//cek jika nama data ditemukan
                        strcpy(dataBaru.nama_Data, GETCKATA());//salin nama data

                        //menambahkan data baru ke dalam list
                        strcpy(listKhusus[*nData].kode_Data, dataBaru.kode_Data);
                        strcpy(listKhusus[*nData].nama_Data, dataBaru.nama_Data);
                        (*nData)++;//tambahkan jumlah data

                        //mengurutkan data setelah penambahan
                        sortDataKhusus(*nData, listKhusus);

                        //menyimpan data ke file
                        FILE *fTemp = fopen(fileKeinginan, "w");//buka file mode write
                        if(fTemp){//file berhasil dibuka
                            for(int i = 0; i < *nData; i++){//loop untuk menulis data ke file
                                fprintf(fTemp, "%s %s\n", listKhusus[i].kode_Data, listKhusus[i].nama_Data);
                            }
                            fprintf(fTemp, "#### #### #### #### #### #### #### ####");//menulis dummy
                            fclose(fTemp);//tutup file
                            printf("Data Berhasil Ditambahkan Ke File %s\n", fileKeinginan);
                        }
                        else{//file gagal dibuka
                            printf("Gagal Menambahkan Data Ke File\n");
                        }
                    }
                    else{//jika nama data tidak ditemukan
                        printf("Nama Data Tidak Ditemukan Dalam Input\n");
                    }
                }
                else{//jika kode data tidak ditemukan
                    printf("Kode Data Tidak Ditemukan Dalam Input\n");
                }
            }
            else{//jika format salah
                printf("Perintah Tidak Valid, Harus Menggunakan 'DATA KHUSUS'\n");
                return;
            }
        }
        else{//jika perintah salah
            printf("Perintah Tidak Valid, Harus Menggunakan 'DATA KHUSUS'\n");
            return;
        }
    }
    else{//jika perintah salah
        printf("Perintah Tidak Valid, Harus Memulai Dengan 'INSERT'\n");
    }
}

//fungsi untuk mengupdate data khusus
void updateDataKhusus(char *pita, int nData, data_Khusus listKhusus[]){
    //deklarasi variabel untuk menyimpan file, data yang diupdate, dan pencarian
    char fileKeinginan[50];
    int ditemukan = 0;
    data_Khusus dataBaru;
    int i, j;

    //memulai mesin kata dengan input pita
    STARTKATA(pita);

    //memeriksa perintah pertama apakah "UPDATE"
    if(strcmp(GETCKATA(), "UPDATE") == 0 || strcmp(GETCKATA(), "update") == 0){
        INCKATA(pita);  // Maju ke kata berikutnya

        //memeriksa apakah perintah kedua adalah "DATA KHUSUS"
        if(strcmp(GETCKATA(), "DATA") == 0 || strcmp(GETCKATA(), "data") == 0){
            INCKATA(pita);//maju ke kata berikutnya
            if(strcmp(GETCKATA(), "KHUSUS") == 0 || strcmp(GETCKATA(), "khusus") == 0){
                INCKATA(pita);//maju ke kata berikutnya

                //memeriksa tipe data untuk dimasukkan ke file yang sesuai
                if(strcmp(GETCKATA(), "KORBAN") == 0 || strcmp(GETCKATA(), "korban") == 0){
                    strcpy(fileKeinginan, "Korban.txt");
                }
                else if(strcmp(GETCKATA(), "KASUS") == 0 || strcmp(GETCKATA(), "kasus") == 0){
                    strcpy(fileKeinginan, "Kasus.txt");
                }
                else if(strcmp(GETCKATA(), "TANGGALPENANGKAPAN") == 0 || strcmp(GETCKATA(), "tanggalpenangkapan") == 0){
                    strcpy(fileKeinginan, "TanggalPenangkapan.txt");
                }
                else{
                    printf("File Tidak Valid, Silahkan Masukkan Dengan Benar\n");
                    return;
                }

                //membaca data yang ada di file terlebih dahulu
                readKhusus_Pelaku(&nData, listKhusus, fileKeinginan);

                //membaca kode data
                INCKATA(pita);//maju ke kata berikutnya
                if(GETCKATA() != 0){
                    strcpy(dataBaru.kode_Data, GETCKATA());
                }
                else{
                    printf("Kode Data Tidak Ditemukan Dalam Input\n");
                    return;
                }

                //membaca nama data baru
                INCKATA(pita);//maju ke kata berikutnya
                if(GETCKATA() != 0){
                    strcpy(dataBaru.nama_Data, GETCKATA());
                }
                else{
                    printf("Nama Data Baru Tidak Ditemukan Dalam Input\n");
                    return;
                }

                //mencari data berdasarkan kode
                i = 0;
                while(i < nData){
                    if(strcmp(listKhusus[i].kode_Data, dataBaru.kode_Data) == 0){
                        ditemukan = 1;//menandakan data ketemu
                        printf("Data Ditemukan: %s %s\n", listKhusus[i].kode_Data, listKhusus[i].nama_Data);
                        //update nama data
                        strcpy(listKhusus[i].nama_Data, dataBaru.nama_Data); 
                    }
                    i++;
                }

                //jika data tidak ditemukan
                if(ditemukan == 0){
                    printf("Data Dengan Kode %s Tidak Ditemukan\n", dataBaru.kode_Data);
                    return;
                }

                //menyimpan data yang telah diupdate dan menambahkan string ####
                FILE *fTemp = fopen(fileKeinginan, "w");//buka file mode write
                if(fTemp){
                    //menulis ulang data ke file
                    j = 0;
                    while(j < nData){
                        fprintf(fTemp, "%s %s\n", listKhusus[j].kode_Data, listKhusus[j].nama_Data);
                        j++;
                    }
                    //menambahkan string #### di akhir file
                    fprintf(fTemp, "#### #### #### #### #### #### #### ####");
                    fclose(fTemp);
                    printf("Data Berhasil Diupdate Ke File %s\n", fileKeinginan);
                }
                else{
                    printf("Gagal Mengupdate Data Ke File\n");
                }
            }
            else{
                printf("Perintah Tidak Valid, Harus Menggunakan 'DATA KHUSUS'\n");
            }
        }
        else{
            printf("Perintah Tidak Valid, Harus Menggunakan 'DATA KHUSUS'\n");
        }
    }
    else{
        printf("Perintah Tidak Valid, Harus Memulai Dengan 'UPDATE'\n");
    }
}

//fungsi untuk mengecek apakah kode korban, kasus, atau tanggal penangkapan sedang digunakan di Pelaku.txt
int cekKodeTerpakai(char *kode){
    FILE *fTemp = fopen("Pelaku.txt", "r");//membuka file mode read
    data_Pelaku dataBaru;

    if(fTemp == 0){//jika file tidak bisa dibuka
        printf("Gagal Membuka File Pelaku.txt\n");
        return 0;
    }

    //cek apakah kode sedang digunakan di Pelaku.txt
    while(fscanf(fTemp, "%s %s %s %s %s %s %s %s", dataBaru.noID_Pelaku, dataBaru.nama_Pelaku, dataBaru.korban_Pelaku, dataBaru.kasus_Pelaku, dataBaru.tanggalPenangkapan_Pelaku, dataBaru.tempat_Pelaku, dataBaru.jenisHukuman_Pelaku, dataBaru.masaHukuman_Pelaku) != EOF){
        if(strcmp(dataBaru.korban_Pelaku, kode) == 0 || strcmp(dataBaru.kasus_Pelaku, kode) == 0 || strcmp(dataBaru.tanggalPenangkapan_Pelaku, kode) == 0){
            fclose(fTemp);
            return 1;//kode ditemukan, berarti sedang digunakan
        }
    }

    fclose(fTemp);
    return 0;//kode tidak ditemukan
}

//fungsi untuk menghapus data khusus
void deleteDataKhusus(char *pita, int *nData, data_Khusus listKhusus[]){
    char fileKeinginan[50];//untuk menyimpan nama file tujuan
    int ditemukan = 0;//flag data ditemukan
    int i = 0;//indeks iterasi array

    STARTKATA(pita);//memulai mesin kata

    if(strcmp(GETCKATA(), "DELETE") == 0 || strcmp(GETCKATA(), "delete") == 0){
        INCKATA(pita);//maju ke kata berikutnya
        if(strcmp(GETCKATA(), "DATA") == 0 || strcmp(GETCKATA(), "data") == 0){
            INCKATA(pita);//maju ke kata berikutnya
            if(strcmp(GETCKATA(), "KHUSUS") == 0 || strcmp(GETCKATA(), "khusus") == 0){
                INCKATA(pita);//maju ke kata berikutnya

                if(strcmp(GETCKATA(), "KORBAN") == 0 || strcmp(GETCKATA(), "korban") == 0){
                    strcpy(fileKeinginan, "Korban.txt");
                } 
                else if(strcmp(GETCKATA(), "KASUS") == 0 || strcmp(GETCKATA(), "kasus") == 0){
                    strcpy(fileKeinginan, "Kasus.txt");
                } 
                else if(strcmp(GETCKATA(), "TANGGALPENANGKAPAN") == 0 || strcmp(GETCKATA(), "tanggalpenangkapan") == 0){
                    strcpy(fileKeinginan, "TanggalPenangkapan.txt");
                } 
                else{
                    printf("File Tidak Valid, Silahkan Masukkan Dengan Benar\n");
                    return;
                }

                //membaca data yang ada di file
                readKhusus_Pelaku(nData, listKhusus, fileKeinginan);

                INCKATA(pita);//maju ke kata berikutnya
                char kodeData[20];//variabel untuk menyimpan kode data
                if(GETCKATA() != 0){
                    strcpy(kodeData, GETCKATA());//menyimpan kode dari input
                } 
                else{
                    printf("Kode Data Tidak Ditemukan Dalam Input\n");
                    return;
                }

                //cek apakah kode data sedang digunakan di Pelaku.txt
                if(cekKodeTerpakai(kodeData)){
                    printf("Data Dengan Kode %s Sedang Digunakan Di Pelaku.txt, Tidak Bisa Dihapus\n", kodeData);
                    return;//tidak dihapus jika sedang digunakan
                }

                //mencari dan menghapus data yang sesuai dengan kode
                while(i < *nData && ditemukan == 0){//iterasi mencari data
                    if(strcmp(listKhusus[i].kode_Data, kodeData) == 0){
                        ditemukan = 1;//data ditemukan
                        printf("Data Ditemukan: %s %s\n", listKhusus[i].kode_Data, listKhusus[i].nama_Data);

                        //menggeser data ke kiri untuk menghapus data yang ditemukan
                        for(int j = i; j < *nData - 1; j++){
                            listKhusus[j] = listKhusus[j + 1];
                        }
                        (*nData)--;//mengurangi jumlah data
                    }
                    i++;//lanjutkan indeks
                }

                if(ditemukan == 0){//jika data tidak ketemu
                    printf("Data Dengan Kode %s Tidak Ditemukan\n", kodeData);
                    return;
                }

                //menulis ulang data yang tersisa ke file
                FILE *fTemp = fopen(fileKeinginan, "w");//membuka file mode write
                if(fTemp){
                    for(i = 0; i < *nData; i++){
                        fprintf(fTemp, "%s %s\n", listKhusus[i].kode_Data, listKhusus[i].nama_Data);//menulis data ke file
                    }
                    fprintf(fTemp, "#### #### #### #### #### #### #### ####");//menambahkan dummy
                    fclose(fTemp);
                    printf("Data Berhasil Dihapus\n");
                } 
                else{
                    printf("Gagal Menghapus Data\n");
                }
            }
        }
    }
}

//fungsi untuk memeriksa apakah kode terdapat dalam file khusus
int cekKodeValid(char *fileName, char *kode){
    FILE *fTemp = fopen(fileName, "r");//membuka file mode read
    char kodeFile[50], namaFile[200];//variabel untuk menyimpan kode dan nama

    if(fTemp == 0){
        printf("Gagal membuka file %s\n", fileName);
        return 0;//gagal membuka file
    }

    //membaca file per baris dan cari kode
    while(fscanf(fTemp, "%s %s", kodeFile, namaFile) != EOF){//membaca dua kata
        if(strcmp(kodeFile, kode) == 0){
            fclose(fTemp);
            return 1;//kode ditemukan
        }
    }

    fclose(fTemp);
    return 0;//kode tidak ditemukan
}

//fungsi untuk mengurutkan data pelaku
void sortDataPelaku(int nData, data_Pelaku listPelaku[]){
    //pengurutan berdasarkan kode_Data
    for(int i = 0; i < nData - 1; i++){//loop untuk data pertama
        for(int j = i + 1; j < nData; j++){//loop untuk data kedua
            //membandingkan kode
            if(strcmp(listPelaku[i].noID_Pelaku, listPelaku[j].noID_Pelaku) > 0){
                //tukar posisi
                data_Pelaku temp = listPelaku[i];//menyimpan data pertama sementara
                listPelaku[i] = listPelaku[j];//memindahkan data pelaku kedua ke pertama
                listPelaku[j] = temp;//memindahkan data sementara ke posisi kedua
            }
        }
    }
}

//fungsi untuk menambahkan data pelaku
void insertDataPelaku(char *pita, int *nData, data_Pelaku listPelaku[]){
    data_Pelaku dataBaru;//variabel untuk menampung data baru
    char fileKeinginan[] = "Pelaku.txt"; //nama file data akan disimpan
    int adaID = 0;//menandakan apakah ID duplikat ditemukan

    STARTKATA(pita);//memulai mesin kata

    if(strcmp(GETCKATA(), "INSERT") == 0 || strcmp(GETCKATA(), "insert") == 0){
        INCKATA(pita);//maju ke kata berikutnya

        //memeriksa apakah perintah kedua adalah "PELAKU"
        if(strcmp(GETCKATA(), "PELAKU") == 0 || strcmp(GETCKATA(), "pelaku") == 0){
            INCKATA(pita);  // Maju ke kata berikutnya

            //membaca data yang ada di file terlebih dahulu
            read_Pelaku(nData, listPelaku, fileKeinginan);

            //memasukkan kode pelaku
            strcpy(dataBaru.noID_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            //mengecek apakah kode pelaku sudah ada
            for(int i = 0; i < *nData; i++){
                if(strcmp(listPelaku[i].noID_Pelaku, dataBaru.noID_Pelaku) == 0){
                    adaID = 1;//menandakan ID ditemukan
                }
            }

            if(adaID == 1){
                printf("Kode Pelaku %s Sudah Digunakan, Silahkan Gunakan Kode Lain\n", dataBaru.noID_Pelaku);
                return;//menghentikan proses jika ID ada
            }

            //memasukkan nama pelaku
            strcpy(dataBaru.nama_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            //memasukkan kode korban dan memeriksa di Korban.txt
            strcpy(dataBaru.korban_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya
            //mengecek kode
            if(cekKodeValid("Korban.txt", dataBaru.korban_Pelaku) == 0){
                printf("Kode Korban %s Tidak Valid, Tidak Ditemukan Di File Korban.txt\n", dataBaru.korban_Pelaku);
                return;//menghentikan proses jika kode korban tidak valid
            }

            //memasukkan kode kasus dan memeriksa keberadaannya di Kasus.txt
            strcpy(dataBaru.kasus_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya
            if(cekKodeValid("Kasus.txt", dataBaru.kasus_Pelaku) == 0){
                printf("Kode Kasus %s Tidak Valid, Tidak Ditemukan Di File Kasus.txt\n", dataBaru.kasus_Pelaku);
                return;//menghentikan proses jika kode kasus tidak valid
            }

            //memasukkan kode tanggal penangkapan dan memeriksa keberadaannya di TanggalPenangkapan.txt
            strcpy(dataBaru.tanggalPenangkapan_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya
            if(cekKodeValid("TanggalPenangkapan.txt", dataBaru.tanggalPenangkapan_Pelaku) == 0){
                printf("Kode Tanggal Penangkapan %s Tidak Valid, Tidak Ditemukan Di File TanggalPenangkapan.txt\n", dataBaru.tanggalPenangkapan_Pelaku);
                return;//menghentikan proses jika kode tanggal penangkapan tidak valid
            }

            //memasukkan tempat penangkapan
            strcpy(dataBaru.tempat_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            //memasukkan jenis hukuman
            strcpy(dataBaru.jenisHukuman_Pelaku, GETCKATA());
            INCKATA(pita);

            //memasukkan masa hukuman
            strcpy(dataBaru.masaHukuman_Pelaku, GETCKATA());

            //menambahkan data pelaku baru
            listPelaku[*nData] = dataBaru;
            (*nData)++;//menambah jumlah data pelaku

            //mengurutkan data berdasarkan ID
            sortDataPelaku(*nData, listPelaku);

            //menyimpan data ke file
            FILE *fTemp = fopen(fileKeinginan, "w");//membuka file mode write
            if(fTemp){//berhasil membuka file
                //menulis seluruh data pelaku ke dalam file
                for(int i = 0; i < *nData; i++){
                    fprintf(fTemp, "%s %s %s %s %s %s %s %s\n", listPelaku[i].noID_Pelaku, listPelaku[i].nama_Pelaku, listPelaku[i].korban_Pelaku, listPelaku[i].kasus_Pelaku, listPelaku[i].tanggalPenangkapan_Pelaku, listPelaku[i].tempat_Pelaku, listPelaku[i].jenisHukuman_Pelaku, listPelaku[i].masaHukuman_Pelaku);
                }
                fprintf(fTemp, "#### #### #### #### #### #### #### ####");
                fclose(fTemp);
                printf("Data Pelaku Berhasil Ditambahkan Ke File %s\n", fileKeinginan);
            }
            else{
                printf("Gagal Menambahkan Data Ke File\n");
            }
        }
        else{
            printf("Perintah Tidak Valid, Harus Menggunakan 'PELAKU' Atau 'pelaku'\n");
        }
    }
    else{
        printf("Perintah Tidak Valid, Harus Dimulai Dengan 'INSERT' Atau 'insert\n");
    }
}

//fungsi untuk mengupdate data pelaku
void updateDataPelaku(char *pita, int *nData, data_Pelaku listPelaku[]){
    //variabel untuk menyimpan data
    data_Pelaku dataBaru;
    int ditemukan = 0;

    //memulai mesin kata dengan input pita
    STARTKATA(pita);

    //memeriksa perintah pertama apakah "UPDATE"
    if(strcmp(GETCKATA(), "UPDATE") == 0 || strcmp(GETCKATA(), "update") == 0){
        INCKATA(pita);//maju ke kata berikutnya

        //memeriksa apakah perintah kedua adalah "PELAGU"
        if(strcmp(GETCKATA(), "PELAKU") == 0 || strcmp(GETCKATA(), "pelaku") == 0){
            INCKATA(pita); //maju ke kata berikutnya

            //memasukkan kode pelaku yang akan diupdate
            strcpy(dataBaru.noID_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            //memasukkan data lainnya untuk update
            strcpy(dataBaru.nama_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            strcpy(dataBaru.korban_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            strcpy(dataBaru.kasus_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            strcpy(dataBaru.tanggalPenangkapan_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            strcpy(dataBaru.tempat_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            strcpy(dataBaru.jenisHukuman_Pelaku, GETCKATA());
            INCKATA(pita);//maju ke kata berikutnya

            strcpy(dataBaru.masaHukuman_Pelaku, GETCKATA());

            //memanggil fungsi untuk membaca data pelaku dari file
            read_Pelaku(nData, listPelaku, "Pelaku.txt");

            //mencari pelaku berdasarkan kode pelaku
            for(int i = 0; i < *nData; i++){
                if(strcmp(listPelaku[i].noID_Pelaku, dataBaru.noID_Pelaku) == 0){//mencari pelaku berdasarkan kode
                    //pelaku ditemukan, update data
                    printf("Data pelaku ditemukan: %s %s\n", listPelaku[i].noID_Pelaku, listPelaku[i].nama_Pelaku);

                    //update data pelaku
                    strcpy(listPelaku[i].nama_Pelaku, dataBaru.nama_Pelaku);
                    strcpy(listPelaku[i].korban_Pelaku, dataBaru.korban_Pelaku);
                    strcpy(listPelaku[i].kasus_Pelaku, dataBaru.kasus_Pelaku);
                    strcpy(listPelaku[i].tanggalPenangkapan_Pelaku, dataBaru.tanggalPenangkapan_Pelaku);
                    strcpy(listPelaku[i].tempat_Pelaku, dataBaru.tempat_Pelaku);
                    strcpy(listPelaku[i].jenisHukuman_Pelaku, dataBaru.jenisHukuman_Pelaku);
                    strcpy(listPelaku[i].masaHukuman_Pelaku, dataBaru.masaHukuman_Pelaku);

                    ditemukan = 1;
                }
            }

            //jika pelaku tidak ditemukan
            if(ditemukan == 0){
                printf("Pelaku Dengan Kode %s Tidak Ditemukan\n", dataBaru.noID_Pelaku);
                return;
            }

            //menyimpan data yang sudah diupdate ke file
            FILE *fTemp = fopen("Pelaku.txt", "w");//buka file mode write
            if(fTemp){
                for(int i = 0; i < *nData; i++){
                    //menulis data pelaku ke file
                    fprintf(fTemp, "%s %s %s %s %s %s %s %s\n", listPelaku[i].noID_Pelaku, listPelaku[i].nama_Pelaku, listPelaku[i].korban_Pelaku, listPelaku[i].kasus_Pelaku, listPelaku[i].tanggalPenangkapan_Pelaku, listPelaku[i].tempat_Pelaku, listPelaku[i].jenisHukuman_Pelaku, listPelaku[i].masaHukuman_Pelaku);
                }
                fprintf(fTemp, "#### #### #### #### #### #### #### ####");
                fclose(fTemp);
                printf("Data Pelaku Berhasil Diupdate\n");
            } 
            else{
                printf("Gagal Mengupdate Data Ke File\n");
            }
        } 
        else{
            printf("Perintah Tidak Valid, Harus Menggunakan 'PELAKU'\n");
        }
    } 
    else{
        printf("Perintah Tidak Valid, Harus Dimulai Dengan 'UPDATE'\n");
    }
}

//fungsi untuk menghapus data pelaku berdasarkan ID dan mengupdate file
void deleteDataPelaku(char *pita, int *nData, data_Pelaku listPelaku[]){
    char fileKeinginan[50];//variabel menyimpan nama file
    int ditemukan = 0;//flag menandakan ketemu
    int i = 0;//indeks pencarian di array listPelaku

    STARTKATA(pita);//memulai mesin kata

    //memeriksa apakah perintah dimulai dengan "DELETE"
    if(strcmp(GETCKATA(), "DELETE") == 0 || strcmp(GETCKATA(), "delete") == 0){
        INCKATA(pita); // Maju ke kata berikutnya

        //memeriksa apakah perintah kedua adalah "PELAKU"
        if(strcmp(GETCKATA(), "PELAKU") == 0 || strcmp(GETCKATA(), "pelaku") == 0){
            INCKATA(pita); //maju ke kata berikutnya

            //mengambil kode pelaku yang akan dihapus
            char idHapus[50];
            if(GETCKATA() != 0){
                strcpy(idHapus, GETCKATA());//menyimpan ID pelaku
            } 
            else{
                printf("ID Pelaku Tidak Ditemukan Dalam Input\n");
                return;
            }

            //mencari ID pelaku dalam daftar pelaku
            while(i < *nData && ditemukan == 0){
                if(strcmp(listPelaku[i].noID_Pelaku, idHapus) == 0){
                    ditemukan = 1;
                    printf("Pelaku ditemukan: %s %s\n", listPelaku[i].noID_Pelaku, listPelaku[i].nama_Pelaku);

                    //menggeser data pelaku ke kiri untuk menghapus data yang ditemukan
                    for(int j = i; j < *nData - 1; j++){
                        listPelaku[j] = listPelaku[j + 1];//menggeser elemen ke kiri menghapus data pelaku
                    }
                    (*nData)--;//mengurangi jumlah data pelaku
                }
                i++;
            }

            //jika ID pelaku tidak ditemukan
            if(ditemukan == 0){
                printf("Data Pelaku Dengan ID %s Tidak Ditemukan\n", idHapus);
                return;
            }

            //menulis ulang data pelaku yang tersisa ke file
            FILE *fTemp = fopen("Pelaku.txt", "w");//membuka file mode write
            if(fTemp){
                for(i = 0; i < *nData; i++){
                    //menulis data pelaku yang tersisa ke file
                    fprintf(fTemp, "%s %s %s %s %s %s %s %s\n", listPelaku[i].noID_Pelaku, listPelaku[i].nama_Pelaku, listPelaku[i].korban_Pelaku, listPelaku[i].kasus_Pelaku, listPelaku[i].tanggalPenangkapan_Pelaku, listPelaku[i].tempat_Pelaku, listPelaku[i].jenisHukuman_Pelaku, listPelaku[i].masaHukuman_Pelaku);
                }
                fprintf(fTemp, "#### #### #### #### #### #### #### ####");
                fclose(fTemp);
                printf("Data Pelaku Dengan ID %s Berhasil Dihapus\n", idHapus);
            } 
            else{
                printf("Gagal Membuka File Pelaku.txt Untuk Menulis Ulang Data\n");
            }
        } 
        else{
            printf("Perintah Tidak Valid, Harus Menggunakan 'PELAKU'\n");
        }
    } 
    else{
        printf("Perintah Tidak Valid, Harus Dimulai Dengan 'DELETE'\n");
    }
}

//fungsi untuk menggabungkan data korban, kasus, dan tanggal penangkapan ke dalam data pelaku
void dataGabunganPelaku(data_Pelaku dataPelaku[], int *nPelaku, data_Khusus dataKorban[], int nKorban, data_Khusus dataKasus[], int nKasus, data_Khusus dataTanggalPenangkapan[], int nTanggalPenangkapan){
    //menggabungkan data korban ke data pelaku
    for(int i = 0; i < *nPelaku; i++){//loop untuk setiap pelaku
        for(int j = 0; j < nKorban; j++){//loop untuk setiap korban
            if(strcmp(dataPelaku[i].korban_Pelaku, dataKorban[j].kode_Data) == 0){//jika kode cocok
                strcpy(dataPelaku[i].korban_Pelaku, dataKorban[j].nama_Data);//mengganti kode dengan nama korban
            }
        }
    }

    //menggabungkan data kasus ke data pelaku
    for(int i = 0; i < *nPelaku; i++){//loop untuk setiap pelaku
        for(int j = 0; j < nKasus; j++){//loop untuk setiap kasus
            if(strcmp(dataPelaku[i].kasus_Pelaku, dataKasus[j].kode_Data) == 0){//jika kode cocok
                strcpy(dataPelaku[i].kasus_Pelaku, dataKasus[j].nama_Data);//mengganti kode dengan nama kasus
            }
        }
    }

    //menggabungkan data tanggal penangkapan ke data pelaku
    for(int i = 0; i < *nPelaku; i++){//loop untuk setiap pelaku
        for(int j = 0; j < nTanggalPenangkapan; j++){//loop untuk setiap tanggal penangkapan
            if(strcmp(dataPelaku[i].tanggalPenangkapan_Pelaku, dataTanggalPenangkapan[j].kode_Data) == 0){//jika kode cocok
                strcpy(dataPelaku[i].tanggalPenangkapan_Pelaku, dataTanggalPenangkapan[j].nama_Data);//mengganti kode dengan nama tanggal penangkapan
            }
        }
    }

    //menulis data gabungan ke dalam file PelakuComplete.txt
    FILE *fTemp = fopen("PelakuComplete.txt", "w");//membuka file mode write
    if(fTemp){//file berhasil dibuka
        for(int i = 0; i < *nPelaku; i++){//loop untuk setiap pelaku
            if(strcmp(dataPelaku[i].noID_Pelaku, "####") != 0){//jika ID bukan dummy
                //menulis data pelaku ke file 
                fprintf(fTemp, "%s %s %s %s %s %s %s %s\n", dataPelaku[i].noID_Pelaku, dataPelaku[i].nama_Pelaku, dataPelaku[i].korban_Pelaku, dataPelaku[i].kasus_Pelaku, dataPelaku[i].tanggalPenangkapan_Pelaku, dataPelaku[i].tempat_Pelaku, dataPelaku[i].jenisHukuman_Pelaku, dataPelaku[i].masaHukuman_Pelaku);
            }
        }
        fprintf(fTemp, "#### #### #### #### #### #### #### ####\n");
        fclose(fTemp);
        printf("Data pelaku berhasil digabungkan dan disimpan ke PelakuComplete.txt\n");
    } 
    else{
        printf("Gagal membuka file PelakuComplete.txt\n");
    }
    return;
}

//fungsi untuk menampilkan tabel data khusus
void tabelKhusus(data_Khusus listData[], int nData){
    int panjangKode = 4;//menginisialisasi panjang kode
    for(int i = 0; i < nData; i++){//iterasi untuk hitung panjang kode data maksimal
        if(panjangKode < strlen(listData[i].kode_Data)){//jika panjang kode data lebih besar dari panjangKode
            panjangKode = strlen(listData[i].kode_Data);//update panjangKode
        }
    }
    int panjangData = 4;//menginisialisasi panjang nama
    for(int i = 0; i < nData; i++){//iterasi untuk hitung panjang data nama maksimal
        if(panjangData < strlen(listData[i].nama_Data)){//jika panjang data lebih besar dari panjangData
            panjangData = strlen(listData[i].nama_Data);//update panjangData
        }
    }

    //cetak garis atas tabel
    printf("\n");
    printf("+-");
    for(int i = 0; i < panjangKode; i++){//cetak tanda '-' sepanjang panjangKode
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangData; i++){//cetak tanda '-' sepanjang panjangData
        printf("-");
    }
    printf("-+\n");

    //cetak header tabel
    printf("| Kode");
    for(int i = 0; i < panjangKode - 4; i++){//tambah spasi agar header 'Kode' berada di tengah
        printf(" ");
    }
    printf(" | Data");
    for(int i = 0; i < panjangData - 4; i++){//tambah spasi agar header 'Data' berada di tengah
        printf(" ");
    }
    printf(" |\n");

    //cetak garis tengah tabel
    printf("+-");
    for(int i = 0; i < panjangKode; i++){//mencetak tanda '-' sepanjang panjangKode
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangData; i++){//mencetak tanda '-' sepanjang panjangData
        printf("-");
    }
    printf("-+\n");

    //cetak baris data
    for(int i = 0; i < nData; i++){//iterasi untuk mencetak data setiap baris
        printf("| %s", listData[i].kode_Data);//cetak kode
        for(int j = 0; j < panjangKode - strlen(listData[i].kode_Data); j++){//menambah spasi untuk meratakan kolom
            printf(" ");
        }
        printf(" | %s", listData[i].nama_Data);//cetak nama
        for(int j = 0; j < panjangData - strlen(listData[i].nama_Data); j++){//menambah spasi untuk meratakan kolom
            printf(" ");
        }
         printf(" |\n");
    }

    //cetak garis bawah tabel
    printf("+-");
    for(int i = 0; i < panjangKode; i++){//mencetak tanda "-" sepanjang panjangKode
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangData; i++){//mencetak tanda "-" sepanjang panjangData
        printf("-");
    }
    printf("-+\n");
}

//fungsi untuk menampilkan tabel ddata pelaku
void tabelPelaku(data_Pelaku listPelakuComplete[], int nPelakuComplete){
    //menghitung panjang kolom ID
    int panjangID = 4;
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangID < strlen(listPelakuComplete[i].noID_Pelaku)){//jika panjang ID lebih besar dari panjangID
            panjangID = strlen(listPelakuComplete[i].noID_Pelaku);//update panjangID
        }
    }
    //menghitung panjang kolom nama pelaku
    int panjangName = 13;
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangName < strlen(listPelakuComplete[i].nama_Pelaku)){//jika panjang nama lebih besar dari panjangName
            panjangName = strlen(listPelakuComplete[i].nama_Pelaku);//update panjangName
        }
    }
    //menghitung panjang kolom korban
    int panjangVictim = 5;
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangVictim < strlen(listPelakuComplete[i].korban_Pelaku)){//jika panjang korban lebih besar dari panjangVictim
            panjangVictim = strlen(listPelakuComplete[i].korban_Pelaku);//update panjangVictim
        }
    }
    //menghitung panjang kolom kasus
    int panjangCase = 4;
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangCase < strlen(listPelakuComplete[i].kasus_Pelaku)){//jika panjang kasus lebih besar dari panjangCase
            panjangCase = strlen(listPelakuComplete[i].kasus_Pelaku);//update panjangCase
        }
    }
    //menghitung panjang kolom tanggal penangkapan
    int panjangArrestDate = 19;
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangArrestDate < strlen(listPelakuComplete[i].tanggalPenangkapan_Pelaku)){//jika panjang tanggal penangkapan lebih besar dari panjangArrestDate
            panjangArrestDate = strlen(listPelakuComplete[i].tanggalPenangkapan_Pelaku);//update panjangArrestDate
        }
    }
    //menghitung panjang kolom tempat penangkapan
    int panjangArrestPlace = 18;
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangArrestPlace < strlen(listPelakuComplete[i].tempat_Pelaku)){//jika panjang tempat penangkapan lebih besar dari panjangArrestPlace
            panjangArrestPlace = strlen(listPelakuComplete[i].tempat_Pelaku);//update panjangArrestPlace
        }
    }
    //menghitung panjang kolom hukuman
    int panjangPunishment = 11;
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangPunishment < strlen(listPelakuComplete[i].jenisHukuman_Pelaku)){//jika panjang hukuman lebih besar dari panjangPunishment
            panjangPunishment = strlen(listPelakuComplete[i].jenisHukuman_Pelaku);//update panjangPunishment
        }
    }
    //menghitung panjang kolom masa hukuman
    int panjangPunishmentPeriod = 12;
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangPunishmentPeriod < strlen(listPelakuComplete[i].masaHukuman_Pelaku)){//jika panjang masa hukuman lebih besar dari panjangPunishmentPeriod
            panjangPunishmentPeriod = strlen(listPelakuComplete[i].masaHukuman_Pelaku);//update panjangPunishmentPeriod
        }
    }

    //hitung panjang maksimal untuk setiap kolom
    for(int i = 0; i < nPelakuComplete; i++){
        if(panjangID < strlen(listPelakuComplete[i].noID_Pelaku)){
            panjangID = strlen(listPelakuComplete[i].noID_Pelaku);
        }
        if(panjangName < strlen(listPelakuComplete[i].nama_Pelaku)){
            panjangName = strlen(listPelakuComplete[i].nama_Pelaku);
        }
        if(panjangVictim < strlen(listPelakuComplete[i].korban_Pelaku)){
            panjangVictim = strlen(listPelakuComplete[i].korban_Pelaku);
        }
        if(panjangCase < strlen(listPelakuComplete[i].kasus_Pelaku)){
            panjangCase = strlen(listPelakuComplete[i].kasus_Pelaku);
        }
        if(panjangArrestDate < strlen(listPelakuComplete[i].tanggalPenangkapan_Pelaku)){
            panjangArrestDate = strlen(listPelakuComplete[i].tanggalPenangkapan_Pelaku);
        }
        if(panjangArrestPlace < strlen(listPelakuComplete[i].tempat_Pelaku)){
            panjangArrestPlace = strlen(listPelakuComplete[i].tempat_Pelaku);
        }
        if(panjangPunishment < strlen(listPelakuComplete[i].jenisHukuman_Pelaku)){
            panjangPunishment = strlen(listPelakuComplete[i].jenisHukuman_Pelaku);
        }
        if(panjangPunishmentPeriod < strlen(listPelakuComplete[i].masaHukuman_Pelaku)){
            panjangPunishmentPeriod = strlen(listPelakuComplete[i].masaHukuman_Pelaku);
        }
    }

    //cetak garis atas tabel
    printf("\n");
    printf("+-");
    for(int i = 0; i < panjangID; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangName; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangVictim; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangCase; i++){
        printf("-");   
    }
    printf("-+-");
    for(int i = 0; i < panjangArrestDate; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangArrestPlace; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangPunishment; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangPunishmentPeriod; i++){
        printf("-");
    }
    printf("-+\n");

    //cetak header tabel
    printf("| ID");
    for(int i = 0; i < panjangID - 2; i++){
        printf(" ");
    }
    printf(" | Nama");
    for(int i = 0; i < panjangName - 4; i++){
        printf(" ");   
    }
    printf(" | Korban");
    for(int i = 0; i < panjangVictim - 6; i++){
        printf(" ");
    }
    printf(" | Kasus");
    for(int i = 0; i < panjangCase - 5; i++){
        printf(" ");
    }
    printf(" | Tanggal Penangkapan");
    for(int i = 0; i < panjangArrestDate - 20; i++){
        printf(" ");
    }
    printf(" | Tempat Penangkapan");
    for(int i = 0; i < panjangArrestPlace - 18; i++){
        printf(" ");
    }
    printf(" | Hukuman");
    for(int i = 0; i < panjangPunishment - 7; i++){
        printf(" ");
    }
    printf(" | Masa Hukuman");
    for(int i = 0; i < panjangPunishmentPeriod - 12; i++){
        printf(" ");
    }
    printf(" |\n");

    //cetak garis tengah tabel
    printf("+-");
    for(int i = 0; i < panjangID; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangName; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangVictim; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangCase; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangArrestDate; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangArrestPlace; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangPunishment; i++){
        printf("-");   
    }
    printf("-+-");
    for(int i = 0; i < panjangPunishmentPeriod; i++){
        printf("-");
    }
    printf("-+\n");

    //cetak baris data
    for(int i = 0; i < nPelakuComplete; i++){
        printf("| %s", listPelakuComplete[i].noID_Pelaku);
        for(int j = 0; j < panjangID - strlen(listPelakuComplete[i].noID_Pelaku); j++){
            printf(" ");
        }
        printf(" | %s", listPelakuComplete[i].nama_Pelaku);
        for(int j = 0; j < panjangName - strlen(listPelakuComplete[i].nama_Pelaku); j++){
            printf(" ");
        }
        printf(" | %s", listPelakuComplete[i].korban_Pelaku);
        for(int j = 0; j < panjangVictim - strlen(listPelakuComplete[i].korban_Pelaku); j++){
            printf(" ");
        }
        printf(" | %s", listPelakuComplete[i].kasus_Pelaku);
        for(int j = 0; j < panjangCase - strlen(listPelakuComplete[i].kasus_Pelaku); j++){
            printf(" ");
        }
        printf(" | %s", listPelakuComplete[i].tanggalPenangkapan_Pelaku);
        for(int j = 0; j < panjangArrestDate - strlen(listPelakuComplete[i].tanggalPenangkapan_Pelaku); j++){
            printf(" ");
        }
        printf(" | %s", listPelakuComplete[i].tempat_Pelaku);
        for(int j = 0; j < panjangArrestPlace - strlen(listPelakuComplete[i].tempat_Pelaku); j++){
            printf(" ");
        }
        printf(" | %s", listPelakuComplete[i].jenisHukuman_Pelaku);
        for(int j = 0; j < panjangPunishment - strlen(listPelakuComplete[i].jenisHukuman_Pelaku); j++){
            printf(" ");
        }
        printf(" | %s", listPelakuComplete[i].masaHukuman_Pelaku);
        for(int j = 0; j < panjangPunishmentPeriod - strlen(listPelakuComplete[i].masaHukuman_Pelaku); j++){
            printf(" ");
        }
        printf(" |\n");
    }

    //cetak garis bawah tabel
    printf("+-");
    for(int i = 0; i < panjangID; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangName; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangVictim; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangCase; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangArrestDate; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangArrestPlace; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangPunishment; i++){
        printf("-");
    }
    printf("-+-");
    for(int i = 0; i < panjangPunishmentPeriod; i++){
        printf("-");
    }
    printf("-+\n");
}