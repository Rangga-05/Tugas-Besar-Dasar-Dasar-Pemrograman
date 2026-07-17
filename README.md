# DBMS "Swiper Jangan Mencuri" - Sistem Pendataan Penangkapan Kriminal 🕵️‍♂️🚓

Aplikasi Database Management System (DBMS) sederhana berbasis Command Line Interface (CLI) yang dibangun menggunakan bahasa pemrograman C. Proyek ini merupakan Tugas Masa Depan (TMD) untuk mata kuliah Dasar-Dasar Pemrograman[cite: 2].

Sesuai dengan instruksi tema utama "Swiper Jangan Mencuri" yang mewajibkan pembuatan desain tabel unik untuk penanganan kasus kejahatan[cite: 2], sistem ini secara spesifik didesain untuk **mendata kasus kriminalitas, korban, identitas pelaku, hingga pencatatan riwayat tanggal penangkapan pelaku**.

## 🚀 Fitur Utama

Proyek ini dibangun tanpa menggunakan database modern, melainkan mengimplementasikan algoritma mentah dari **Mesin Kata** dan **Sequential File**[cite: 2].

*   **Custom Query Processing:** Memproses dan menerjemahkan perintah (*query*) dari pengguna per kata dengan memanfaatkan pita karakter/Mesin Kata[cite: 2].
*   **Operasi Basis Data Terpusat:** Mendukung eksekusi perintah `ISI`, `UBAH`, `HAPUS`, dan `TAMPIL` yang datanya akan langsung ditulis/dibaca pada file persisten[cite: 2].
*   **Sequential File Management:** Manipulasi penyimpanan data secara berurutan menggunakan ekstensif file teks (`.txt`)[cite: 2].
*   **Relational Table JOIN (Bonus Task):** Memiliki kapabilitas tingkat lanjut untuk membaca dan menggabungkan data antar tabel menggunakan konsep relasi *Primary Key* dan *Foreign Key* (misalnya menghubungkan ID Kasus dengan entitas Pelaku dan Korban)[cite: 2].

## 📂 Struktur Proyek

Untuk menjaga kode tetap bersih (Clean Code) dan modular, *source code* dibagi menjadi 3 bagian utama[cite: 2]:

*   `header.h`: File berekstensi *header* yang menyimpan seluruh deklarasi pustaka, tipe bentukan (struct), variabel global, dan prototipe fungsi/prosedur[cite: 2].
*   `mesin.c`: File yang menyimpan implementasi dan logika utama dari fungsi dan prosedur, termasuk alur pergerakan pita Mesin Kata[cite: 2].
*   `main.c`: File utama (*driver*) yang mengatur siklus program berjalan (termasuk *greeting* awal dan iterasi masukan *query*)[cite: 2].
*   `*.txt` (Kasus, Korban, Pelaku, TanggalPenangkapan): Bertindak sebagai arsip beruntun (*sequential file*) yang menyimpan basis data sistem[cite: 2].

## 🎥 Demo & Presentasi Kode

Penjelasan mendetail mengenai alur kerja program, pembedahan kode (*code walkthrough*), desain arsitektur fungsi, dan pengujian program (termasuk pengujian fitur *Join*) dapat disaksikan pada video presentasi berikut:

[![Presentasi Proyek](https://img.youtube.com/vi/P2IYrqSYufY/0.jpg)](https://youtu.be/P2IYrqSYufY?si=Y_siJyF8M51szz99)

> **Klik gambar di atas atau akses tautan berikut:** [Tonton Presentasi di YouTube](https://youtu.be/P2IYrqSYufY?si=Y_siJyF8M51szz99)
