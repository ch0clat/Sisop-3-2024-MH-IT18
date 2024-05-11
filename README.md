# Sisop-3-2024-MH-IT18
## Anggota kelompok
   ### Callista Meyra Azizah 5027231060
   ### Abhirama Triadyatma Hermawan 5027231061
   ### Adi Satria Pangestu 5027231043


# Soal
## Soal 1
Pada zaman dahulu pada galaksi yang jauh-jauh sekali, hiduplah seorang Stelle. Stelle adalah seseorang yang sangat tertarik dengan Tempat Sampah dan Parkiran Luar Angkasa. Stelle memulai untuk mencari Tempat Sampah dan Parkiran yang terbaik di angkasa. Dia memerlukan program untuk bisa secara otomatis mengetahui Tempat Sampah dan Parkiran dengan rating terbaik di angkasa. Programnya berbentuk microservice sebagai berikut:
Dalam auth.c pastikan file yang masuk ke folder new-entry adalah file csv dan berakhiran trashcan dan parkinglot. Jika bukan, program akan secara langsung akan delete file tersebut. Contoh dari nama file yang akan diautentikasi: belobog_trashcan.csv osaka_parkinglot.csv
Format data (Kolom) yang berada dalam file csv adalah seperti berikut:

![Screenshot (504)](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/153620793/ccad326c-de19-47f2-afcd-e207c7887a85)

File csv yang lolos tahap autentikasi akan dikirim ke shared memory. Dalam rate.c, proses akan mengambil data csv dari shared memory dan akan
memberikan output Tempat Sampah dan Parkiran dengan Rating Terbaik dari data tersebut. 

![Screenshot (505)](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/153620793/5e24283a-8737-4a0f-93b0-ccc01488d930)

Pada db.c, proses bisa memindahkan file dari new-data ke folder microservices/database, WAJIB MENGGUNAKAN SHARED MEMORY. Log semua file yang masuk ke folder microservices/database ke dalam file
db.log dengan contoh format sebagai berikut: [DD/MM/YY hh:mm:ss] [type] [filename] ex : `[07/04/2024 08:34:50] [Trash Can] [belobog_trashcan.csv]
Contoh direktori awal:
.
├── auth.c
├── microservices
│ ├── database
│ │ └── db.log
│ ├── db.c
│ └── rate.c
└── new-data
 ├── belobog_trashcan.csv
 ├── ikn.csv
 └── osaka_parkinglot.csv
Contoh direktori akhir setelah dijalankan auth.c dan db.c:
.
├── auth.c
├── microservices
│ ├── database
│ │ ├── belobog_trashcan.csv
│ │ ├── db.log
│ │ └── osaka_parkinglot.csv
│ ├── db.c
│ └── rate.c
└── new-data

## Soal 2
Max Verstappen 🏎️ seorang pembalap F1 dan programer memiliki seorang adik bernama Min Verstappen (masih SD) sedang menghadapi tahap paling kelam dalam kehidupan yaitu perkalian matematika, Min meminta bantuan Max untuk membuat kalkulator perkalian sederhana (satu sampai sembilan). Sembari Max nguli dia menyuruh Min untuk belajar perkalian dari web (referensi) agar tidak bergantung pada kalkulator.
(Wajib menerapkan konsep pipes dan fork seperti yang dijelaskan di modul Sisop. Gunakan 2 pipes dengan diagram seperti di modul 3).
Sesuai request dari adiknya Max ingin nama programnya dudududu.c. Sebelum program parent process dan child process, ada input dari user berupa 2 string. Contoh input: tiga tujuh. 
Pada parent process, program akan mengubah input menjadi angka dan melakukan perkalian dari angka yang telah diubah. Contoh: tiga tujuh menjadi 21. 
Pada child process, program akan mengubah hasil angka yang telah diperoleh dari parent process menjadi kalimat. Contoh: 21 menjadi “dua puluh satu”.
Max ingin membuat program kalkulator dapat melakukan penjumlahan, pengurangan, dan pembagian, maka pada program buatlah argumen untuk menjalankan program : 
perkalian	: ./kalkulator -kali
penjumlahan	: ./kalkulator -tambah
pengurangan	: ./kalkulator -kurang
pembagian	: ./kalkulator -bagi
Beberapa hari kemudian karena Max terpaksa keluar dari Australian Grand Prix 2024 membuat Max tidak bersemangat untuk melanjutkan programnya sehingga kalkulator yang dibuatnya cuma menampilkan hasil positif jika bernilai negatif maka program akan print “ERROR” serta cuma menampilkan bilangan bulat jika ada bilangan desimal maka dibulatkan ke bawah.
Setelah diberi semangat, Max pun melanjutkan programnya dia ingin (pada child process) kalimat akan di print dengan contoh format : 
perkalian	: “hasil perkalian tiga dan tujuh adalah dua puluh satu.”
penjumlahan	: “hasil penjumlahan tiga dan tujuh adalah sepuluh.”
pengurangan	: “hasil pengurangan tujuh dan tiga adalah empat.”
pembagian	: “hasil pembagian tujuh dan tiga adalah dua.”
Max ingin hasil dari setiap perhitungan dicatat dalam sebuah log yang diberi nama histori.log. Pada parent process, lakukan pembuatan file log berdasarkan data yang dikirim dari child process. 
Format: [date] [type] [message]
Type: KALI, TAMBAH, KURANG, BAGI
Ex:
[10/03/24 00:29:47] [KALI] tujuh kali enam sama dengan empat puluh dua.
[10/03/24 00:30:00] [TAMBAH] sembilan tambah sepuluh sama dengan sembilan belas.
[10/03/24 00:30:12] [KURANG] ERROR pada pengurangan.


## Soal 3
Shall Leglerg🥶 dan Carloss Signs 😎 adalah seorang pembalap F1 untuk tim Ferrari 🥵. Mobil F1 memiliki banyak pengaturan, seperti penghematan ERS, Fuel, Tire Wear dan lainnya. Pada minggu ini ada race di sirkuit Silverstone. Malangnya, seluruh tim Ferrari diracun oleh Super Max Max pada hari sabtu sehingga seluruh kru tim Ferrari tidak bisa membantu Shall Leglerg🥶 dan Carloss Signs 😎 dalam race. Namun, kru Ferrari telah menyiapkan program yang bisa membantu mereka dalam menyelesaikan race secara optimal. Program yang dibuat bisa mengatur pengaturan - pengaturan dalam mobil F1 yang digunakan dalam balapan. Programnya ber ketentuan sebagai berikut:
Pada program actions.c, program akan berisi function function yang bisa di call oleh paddock.c
Action berisikan sebagai berikut:
Gap [Jarak dengan driver di depan (float)]: Jika Jarak antara Driver dengan Musuh di depan adalah < 3.5s maka return Gogogo, jika jarak > 3.5s dan 10s return Push, dan jika jarak > 10s maka return Stay out of trouble.
Fuel [Sisa Bensin% (string/int/float)]: Jika bensin lebih dari 80% maka return Push Push Push, jika bensin di antara 50% dan 80% maka return You can go, dan jika bensin kurang dari 50% return Conserve Fuel.
Tire [Sisa Ban (int)]: Jika pemakaian ban lebih dari 80 maka return Go Push Go Push, jika pemakaian ban diantara 50 dan 80 return Good Tire Wear, jika pemakaian di antara 30 dan 50 return Conserve Your Tire, dan jika pemakaian ban kurang dari 30 maka return Box Box Box.
Tire Change [Tipe ban saat ini (string)]: Jika tipe ban adalah Soft return Mediums Ready, dan jika tipe ban Medium return Box for Softs.

Contoh:
[Driver] : [Fuel] [55%]
[Paddock]: [You can go]

Pada paddock.c program berjalan secara daemon di background, bisa terhubung dengan driver.c melalui socket RPC.
Program paddock.c dapat call function yang berada di dalam actions.c.
Program paddock.c tidak keluar/terminate saat terjadi error dan akan log semua percakapan antara paddock.c dan driver.c di dalam file race.log

Format log:
[Source] [DD/MM/YY hh:mm:ss]: [Command] [Additional-info]
ex :
[Driver] [07/04/2024 08:34:50]: [Fuel] [55%]
[Paddock] [07/04/2024 08:34:51]: [Fuel] [You can go]

Program driver.c bisa terhubung dengan paddock.c dan bisa mengirimkan pesan dan menerima pesan serta menampilan pesan tersebut dari paddock.c sesuai dengan perintah atau function call yang diberikan.
Jika bisa digunakan antar device/os (non local) akan diberi nilai tambahan.
untuk mengaktifkan RPC call dari driver.c, bisa digunakan in-program CLI atau Argv (bebas) yang penting bisa send command seperti poin B dan menampilkan balasan dari paddock.c
		ex:
Argv: 
./driver -c Fuel -i 55% 
in-program CLI:
Command: Fuel
Info: 55%

Contoh direktori 😶‍🌫️:
.		.

	├── client
		
	│   └── driver.c
		
	└── server
	
	├── actions.c
		    
	├── paddock.c
		    
	└── race.log

## Soal 4
Lewis Hamilton 🏎 seorang wibu akut dan sering melewatkan beberapa episode yang karena sibuk menjadi asisten. Maka dari itu dia membuat list anime yang sedang ongoing (biar tidak lupa) dan yang completed (anime lama tapi pengen ditonton aja). Tapi setelah Lewis pikir-pikir malah kepikiran untuk membuat list anime. Jadi dia membuat file (harap diunduh) dan ingin menggunakan socket yang baru saja dipelajarinya untuk melakukan CRUD pada list animenya. 
Client dan server terhubung melalui socket. 
client.c di dalam folder client dan server.c di dalam folder server
Client berfungsi sebagai pengirim pesan dan dapat menerima pesan dari server.
Server berfungsi sebagai penerima pesan dari client dan hanya menampilkan pesan perintah client saja.  
Server digunakan untuk membaca myanimelist.csv. Dimana terjadi pengiriman data antara client ke server dan server ke client.
Menampilkan seluruh judul
Menampilkan judul berdasarkan genre
Menampilkan judul berdasarkan hari
Menampilkan status berdasarkan berdasarkan judul
Menambahkan anime ke dalam file myanimelist.csv
Melakukan edit anime berdasarkan judul
Melakukan delete berdasarkan judul
Selain command yang diberikan akan menampilkan tulisan “Invalid Command”
Karena Lewis juga ingin track anime yang ditambah, diubah, dan dihapus. Maka dia membuat server dapat mencatat anime yang dihapus dalam sebuah log yang diberi nama change.log.

Format: [date] [type] [massage]
Type: ADD, EDIT, DEL
Ex:
[29/03/24] [ADD] Kanokari ditambahkan.
[29/03/24] [EDIT] Kamis,Comedy,Kanokari,completed diubah menjadi Jumat,Action,Naruto,completed.
[29/03/24] [DEL] Naruto berhasil dihapus.

Koneksi antara client dan server tidak akan terputus jika ada kesalahan input dari client, cuma terputus jika user mengirim pesan “exit”. Program exit dilakukan pada sisi client.
Hasil akhir:

soal_4/

    ├── change.log
    
    ├── client/
    
    │   └── client.c
    
    ├── myanimelist.csv
    
    └── server/
    
        └── server.c
	
Log Perubahan:
5/3/2024 - 2:37 pm: Tambah keterangan soal 3 di poin H 
5/3/2024 - 6.18 pm: Ralat “dan” pada poin D soal 1
5/6/2024 - 7.42 am: Revisi pada Soal 4D poin 4, Menampilkan status berdasarkan berdasarkan status menjadi Menampilkan status berdasarkan berdasarkan judul

# Penyelesaian

## Soal 1
pengerjaan nomor 1 masih bermasalah. auth.c berfungsi berhasil membaca file. Rate.c tidak berhasil membaca data dari shared memory dengan benar
output Filename: kosong dan nilai Rating: 0.0
**auth.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define SHM_KEY 0x1234

int main() {
    char *shm;
    int shm_id, file_size;
    FILE *fp;
    char filename[1024], buffer[1024], output[1024], output_buffer[2048];
//    output[0] = '\0';

    // Membuat shared memory
    shm_id = shmget(SHM_KEY, 1024, IPC_CREAT | 0666);
    shm = shmat(shm_id, NULL, 0);
//    filename_shm = shm_addr;  // Menunjuk ke awal shared memory untuk menyimpan nama file

    // Membaca file dari new-data
    DIR *dir = opendir("new-data");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            snprintf(filename, sizeof(filename), "new-data/%s", entry->d_name);
            if (strstr(filename, "trashcan.csv") || strstr(filename, "parkinglot.csv")) {
//		printf("%s\n", entry->d_name);
//		strcpy(shm_addr, entry->d_name);
//		printf("%s\n", shm_addr);
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Gagal membuka file: %s\n", filename);
                    continue;
                }
		// Menyalin nama file ke shared memory
//                strcpy(filename_shm, entry->d_name);
//                filename_shm += strlen(entry->d_name) + 1;  // Memindahkan pointer ke lokasi selanjutnya
//		printf("%s\n", filename_shm);
                // Membaca isi file dan mengirim ke shared memory
//		strcpy(shm_addr, filename);
                file_size = fread(buffer, sizeof(char), 1024, fp);
                memcpy(output, buffer, file_size);
                output[file_size] = '\0';
		sprintf(output_buffer, "%s\n%s\n", entry->d_name, output);;
		strcat(shm, output_buffer);
//		printf("%s", shm);
                fclose(fp);
            } else {
                // Menghapus file yang tidak valid
                remove(filename);
            }
        }
    }
    closedir(dir);

    // Melepaskan shared memory
    printf("%s", shm);
    shmdt(shm);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}
```
auth.c memproses file-file yang dimasukkan ke dalam direktori new-data, memeriksa apakah mereka merupakan file CSV dengan nama yang sesuai, dan menyimpan data dari file-file yang valid ke dalam shared memory. Memeriksa apakah nama file sesuai dengan pola yang diinginkan (berakhiran "trashcan.csv" atau "parkinglot.csv"). Jika sesuai, membuka file tersebut, membaca isinya, dan mengirimkan isinya ke shared memory.

![Screenshot (507)](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/153620793/cccbfa01-c214-4363-9889-969d6027ccde)

**rate.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234

int main() {
    char *shm_addr;
    int shm_id;
    float highest_trash = 0.0, highest_parking = 0.0;
    char trash_name[100], parking_name[100], current_file[100];

    shm_id = shmget(SHM_KEY, 1024, IPC_CREAT | 0666);
    shm_addr = shmat(shm_id, NULL, 0);

    char *line = strtok(shm_addr, "\n");
    while (line != NULL) {
    
        if (strstr(line, ".csv") != NULL) {
            strcpy(current_file, line);
        } else {
            
            char name[100];
            float rating;
            sscanf(line, "%[^,], %f", name, &rating);

            if (strstr(current_file, "trashcan.csv") != NULL && rating > highest_trash) {
                highest_trash = rating;
                strcpy(trash_name, name);
            } else if (strstr(current_file, "parkinglot.csv") != NULL && rating > highest_parking) {
                highest_parking = rating;
                strcpy(parking_name, name);
            }
        }

        line = strtok(NULL, "\n");
    }

    printf("Output:\n\n");
    printf("Type: Trash Can\nFilename: %s\nName: %s\nRating: %.1f\n\n", current_file, trash_name, highest_trash);
    printf("Type: Parking Lot\nFilename: %s\nName: %s\nRating: %.1f\n", current_file, parking_name, highest_parking);

    shmdt(shm_addr);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}
```
rate.c menganalisis data dari shared memory dan menentukan tempat sampah dan parkiran dengan rating tertinggi. Membandingkan rating dari setiap tempat sampah dan parkiran. Memilih tempat sampah dan parkiran dengan rating tertinggi. Mencetak hasil pemilihan tempat sampah dan parkiran ke layar.
![Screenshot (506)](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/153620793/4b938057-b275-4638-87c8-bcd1f82c102e)

**db.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define SHM_KEY 0x1234

int main() {
    char *shm_addr;
    int shm_id;
    FILE *fp, *logfile;
    char filename[100], logline[200];
    time_t rawtime;
    struct tm *timeinfo;

    // Membuat folder database jika belum ada
    mkdir("microservices/database", 0755);

    // Membuka file log
    logfile = fopen("microservices/database/db.log", "a");
    if (logfile == NULL) {
        printf("Gagal membuka file log\n");
        return 1;
    }

    // Mengakses shared memory
    shm_id = shmget(SHM_KEY, 1024, 0666);
    shm_addr = shmat(shm_id, NULL, 0);

    char *line = strtok(shm_addr, "\n");
    while (line != NULL) {
        char name[100], type[20];
        sscanf(line, "%[^,],%s", name, type);

        sprintf(filename, "microservices/database/%s.csv", name);
        fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("Gagal membuat file: %s\n", filename);
            line = strtok(NULL, "\n");
            continue;
        }

        fprintf(fp, "%s\n", line);
        fclose(fp);

        // Mencatat log
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(logline, sizeof(logline), "[%d/%m/%Y %H:%M:%S] [%s] [%s.csv]", timeinfo, type, name);
        fprintf(logfile, "%s\n", logline);

        line = strtok(NULL, "\n");
    }

    fclose(logfile);

    // Melepaskan shared memory
    shmdt(shm_addr);
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}
```
db.c memindahkan file-file yang valid dari direktori new-data ke dalam direktori microservices/database dan mencatatnya di file log.

## soal 2
Kita masukkan beberapa header sebagai library yang dipakai. Untuk penjelasan kegunaan tiap library, ada pada komentar.

```c
#include <stdio.h> // Input-Output standar
#include <string.h> // Manipulasi string
#include <math.h> // Fungsi matematika
#include <time.h> // Mengelola date and time
#include <stdlib.h> // Alokasi memori, konversi string menjadi angka
#include <unistd.h> // pengelolaan proses, direktori, dan akses ke sistem
#include <sys/wait.h> // menunggu child process selesai
```

Selanjutnya, kita buat Array 'Kata', yang digunakan untuk menyimpan representasi string angka dari 0 hingga 9 dalam bahasa Indonesia.

```c
// Deklarasi angka2 di Array 
char Kata[10][10] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"}; // Data2nya (nol sampai sembilan)
```

Setelah kita deklarasi Array 'Kata', kita deklarasi variabel-variabel lainnya. Variabel yang dideklarasikan mencakup: variabel untuk menyimpan hasil operasi matematika, file descriptor untuk pipe, process id untuk child process, dan buffer untuk menyimpan data yang dikirim melalui pipe.

```c
int hasil;
char hasilchar[10];


    int pipefd1[2],pipefd2[2]; // File descriptors for the pipes
    pid_t child_pid;
    char buffer1[20],buffer2[20],buffer3[20],buffer4[1000];
    char argu[20];
    char maudicatat[1000];
```

Selesai mendeklarasikan variabel, kita gunakan fungsi Cari Angka, yang akan mencari angka dalam array Kata berdasarkan input yang diberikan. Jika angka ditemukan, fungsi akan mengembalikan indeksnya dalam array Kata.

```c
// Mencari angka dari array "Kata"
int CariAngka(const char * KataYangDicari){
        for (int i = 0; i < 10; i++){
            if (strcmp(KataYangDicari, Kata[i]) == 0){  
                return i;
                break;
                }
            }
    }
```

Dibawah ini adalah fungsi-fungsi operasi matematika, yaitu Perkalian, Penjumlahan, Pembagian dan Pengurangan.

```c
  //==========================================//
 // FUNGSI OPERASI KALI BAGI TAMBAH KURANG   //
//==========================================//

int perkalian(int AngkaPertama, int AngkaKedua){  // Fungsi PERKALIAN
        hasil = AngkaPertama * AngkaKedua;
        return  hasil;
    }   

int penjumlahan(int AngkaPertama, int AngkaKedua){  // Fungsi PENJUMLAHAN
        hasil = AngkaPertama + AngkaKedua;
        return  hasil;
    }   

int pembagian(int AngkaPertama, int AngkaKedua){ // Fungsi PEMBAGIAN
        hasil = AngkaPertama / AngkaKedua;
        return  hasil;
    }   

int pengurangan(int AngkaPertama, int AngkaKedua){  // Fungsi PENGURANGAN
        hasil = AngkaPertama - AngkaKedua;
        return  hasil;
    }   
//=======================================================================//
```
Nah, fungsi dibawah ini akan meng-convert hasil operasi matematika tadi menjadi string bahasa Indonesia. Misal program mendapat "21", angka tersebut akan menjadi "dua puluh satu". 

```s
// Dari hasil angka (misal 21) menjadi dua puluh satu
char* NumberToBahasa(char FinalOutput[], char StrOp[], char KataPertama[], char KataKedua[]){
        char ch1[50];
        char ch2[50];
        char ch3[50];
        char strResult[200];
        char AbjadPertama = FinalOutput[0];
        char AbjadKedua = FinalOutput[1];
        int x = atoi(FinalOutput); 
        int firstdigit = x/10; 
        int lastdigit = x%10; 

        if (strlen(FinalOutput) == 1){
            strcpy(ch1, Kata[lastdigit]);
            // printf("%s\n", Kata[lastdigit]);
            // printf("%s\n",ch1);
            
        }

        if (strlen(FinalOutput) > 1 && firstdigit==1){
            if(lastdigit == 0){
                    strcpy(ch1, "sepuluh");
                    // printf("sepuluh\n");
                }
            if(lastdigit ==1){
                    strcpy(ch1, "sebelas");
                    // printf("sebelas\n");
                }
            if(lastdigit > 1){
                strcpy(ch1, Kata[lastdigit]);
                strcpy(ch2, " belas");

                strcat(ch1, ch2);
                // printf("%s", Kata[lastdigit]);
                // printf(" belas\n");
            }
        }
        
        if (strlen(FinalOutput) > 1 && firstdigit>1){
            strcpy(ch1, Kata[firstdigit]);
            // printf("%s", Kata[firstdigit]);
            if(lastdigit == 0){
                strcpy(ch2, " puluh");
                strcat(ch1, ch2);
                // printf(" puluh");
                }
            if(lastdigit > 0){
                strcpy(ch2, " puluh ");
                strcpy(ch3, Kata[lastdigit]);
                strcat(ch1, ch2);
                strcat(ch1, ch3);
                // printf(" puluh %s", Kata[lastdigit]);
            }
            printf("\n");
        }
        
        strcpy(strResult, "");
        strcat(strResult, "hasil dari ");
        strcat(strResult, StrOp);
        strcat(strResult, " ");
        strcat(strResult, KataPertama);
        strcat(strResult, " dan ");
        strcat(strResult, KataKedua);
        strcat(strResult, " adalah ");
        strcat(strResult, ch1);

        // printf("%s", strResult);
        // printf("\n");

        // catat(strResult,StrOp);
        
        char StrOpLog[50];
        char TimeLog[1000];
        strcpy(TimeLog, "");
        strcpy(StrOpLog, "");

        if (strcmp(StrOp, "perkalian")==0)
            {strcpy(StrOpLog, "[KALI]  ");}
        if (strcmp(StrOp, "pembagian")==0)
            {strcpy(StrOpLog, "[BAGI]  ");}
        if (strcmp(StrOp, "penjumlahan")==0)
            {strcpy(StrOpLog, "[JUMLAH]  ");}
        if (strcmp(StrOp, "pengurangan")==0)
            {strcpy(StrOpLog, "[KURANG]  ");}

        // WAKTU //        
        char s[100];
        int rc;
        time_t temp;
        struct tm *timeptr;

        temp = time(NULL);
        timeptr = localtime(&temp);

        rc = strftime(s,sizeof(s),"%A, %b %d. %r", timeptr);
        // printf("[%s]",s);
        // ----- //        

        strcpy(TimeLog, "");
        strcat(TimeLog, "[");
        strcat(TimeLog, s);
        strcat(TimeLog, "] ");
        strcat(TimeLog, StrOpLog);
        strcat(TimeLog, strResult);
        strcat(TimeLog, "\n\n");

        // PENTING!!!!!

        // FILE *fp; 
        // fp = fopen ("histori.log", "a"); 
        // fprintf(fp, TimeLog);    
        // fclose(fp);
        
        // printf("%s", TimeLog);

        strcpy(buffer4, "");
        strcpy(buffer4, TimeLog);
        write(pipefd2[1], &buffer4, sizeof(buffer4));
        close(pipefd1[0]); // tutup read-end  pipa 1 dari parent 
        close(pipefd2[1]); // tutup write-end pipa 2 dari parent 
        exit(EXIT_SUCCESS);

        return TimeLog;
    }
```

Fungsi selanjutnya, ValidasiOutput, akanmemvalidasi hasil operasi matematika. Jika hasilnya non-negatif, hasil tersebut dikonversi menjadi string. Jika hasilnya negatif, string "ERROR" akan dikembalikan.

```c
// Misal hasilnya malah negatif (error)
char* ValidasiOutput(int hasil){
        if (hasil >= 0){
            sprintf(hasilchar, "%d", hasil); 
        //     // printf("Hasil: %s\n", hasilchar);
        }
        if (hasil < 0){
            strcpy(hasilchar, "ERROR");
            printf("Hasil: %s\n", hasilchar);
        }
        return hasilchar;
    }
```
Fungsi selanjutnya adalah fungsi main dalam program Di sini dilakukan proses input dari pengguna, pembuatan pipe, pembuatan child process, pengiriman data melalui pipe, penanganan operasi matematika, pembuatan log, dan lain-lain.
```c
int main(int argc, char* argv[])
{
    char KataPertama[50], KataKedua[50], FinalOutput[10];
    int AngkaPertama, AngkaKedua;
    char str1[50], str2[10];
```

Fungsi dibawah ini berjalan dengan alur sebagai berikut (lanjut dari fungsi main yang diatas):
   `main` memisahkan proses parent dan child menggunakan fork().
   `Parent` mengirim inputan ke child melalui pipe.
   `Child` menerima inputan, melakukan operasi matematika, mengonversi hasilnya ke bahasa Indonesia, dan mengirim hasil tersebut serta waktu ke parent melalui pipe.
   `Parent` menerima hasil dari child, menuliskannya ke dalam file histori.log, dan menunggu child selesai.

```c
    // printf("arg = %s", argv[1]);

    //=================================================================================//
    //                                   TERIMA INPUT                                  //
    //=================================================================================//
    printf("Input: ");
    scanf("%49s %49s", KataPertama, KataKedua);
    //=================================================================================//
    
    // Create the first pipe
    if (pipe(pipefd1) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create the second pipe 
    if (pipe(pipefd2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    // Create a child process
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if (child_pid == 0) { // Child process
        close(pipefd1[1]); 
        read(pipefd1[0], buffer1, sizeof(buffer1)); 
        read(pipefd1[0], buffer2, sizeof(buffer2)); 
        read(pipefd1[0], buffer3, sizeof(buffer3)); 
        // printf("Child received: %s \n", buffer1);
        // printf("Child received: %s \n", buffer2);
        // printf("Child received: %s \n", buffer3);

        // AngkaKedua="0"
        AngkaPertama = CariAngka(buffer1);
        AngkaKedua = CariAngka(buffer2);

        // printf("AngkaPertama: %d\n", AngkaPertama);        
        // printf("AngkaKedua: %d\n", AngkaKedua);    
        // printf("\n");
        
        // printf("hasil compare: %d\n",strcmp(buffer3, "-kali"));
        
        if (strcmp(buffer3, "-kali") == 0) {
            // printf("COBA");
            char StrOp[20] = "perkalian";
            hasil = perkalian(AngkaPertama, AngkaKedua);
            // printf("Hasil: %d\n", hasil);
            ValidasiOutput(hasil);
            strcpy(FinalOutput, ValidasiOutput(hasil));
            // printf("FinalOutput: %s\n", FinalOutput);
            if(hasil>=0){
                    NumberToBahasa(FinalOutput, StrOp, KataPertama, KataKedua);
                    // strcpy(buffer4, "");
                    // strcpy(buffer4, maudicatat);
                    // printf("buffer4: %s",buffer4);
                    // write(pipefd2[1], &buffer4, sizeof(buffer4));
                    // close(pipefd1[0]); // tutup read-end  pipa 1 dari parent 
                    // close(pipefd2[1]); // tutup write-end pipa 2 dari parent 
                    // exit(EXIT_SUCCESS);

                }
            }
            
      //=================================================================================//
     //                   FUNGSI -bagi -tambah -kali -kurang                            //      
    //=================================================================================//
    
        if (strcmp(buffer3, "-bagi") == 0) {
                char StrOp[20] = "pembagian";
                hasil = pembagian(AngkaPertama, AngkaKedua);
                // printf("Hasil: %d\n", hasil);
                ValidasiOutput(hasil);
                strcpy(FinalOutput, ValidasiOutput(hasil));
                // printf("%s\n", FinalOutput);
                if(hasil>=0){
                    NumberToBahasa(FinalOutput, StrOp, KataPertama, KataKedua);
                }
            }

        if (strcmp(buffer3, "-tambah") == 0) {
                char StrOp[20] = "penjumlahan";
                hasil = penjumlahan(AngkaPertama, AngkaKedua);
                // printf("Hasil: %d\n", hasil);
                ValidasiOutput(hasil);
                strcpy(FinalOutput, ValidasiOutput(hasil));
                // printf("%s\n", FinalOutput);
                if(hasil>=0){
                    NumberToBahasa(FinalOutput, StrOp, KataPertama, KataKedua);
                }
            }

        if (strcmp(buffer3, "-kurang") == 0) {
                char StrOp[20] = "pengurangan";
                hasil = pengurangan(AngkaPertama, AngkaKedua);
                // printf("Hasil: %d\n", hasil);
                ValidasiOutput(hasil);
                strcpy(FinalOutput, ValidasiOutput(hasil));
                // printf("%s\n", FinalOutput);
                if(hasil>=0){
                    NumberToBahasa(FinalOutput, StrOp, KataPertama, KataKedua);
                }
            }

        close(pipefd1[0]); 
        exit(EXIT_SUCCESS);
    } else { // Parent process 
        
        close(pipefd1[0]); // tutup read  pipa 1 dari parent
        close(pipefd2[1]); // tutup write pipa 2 dari parent
        strcpy(buffer1, KataPertama);
        strcpy(buffer2, KataKedua);
        strcpy(buffer3, argv[1]);
        // printf("%s", buffer3);
        write(pipefd1[1], buffer1, sizeof(buffer1)); 
        write(pipefd1[1], buffer2, sizeof(buffer2)); 
        write(pipefd1[1], buffer3, sizeof(buffer3)); 
        
        wait(NULL);
        
        read(pipefd2[0], &buffer4, sizeof(buffer4));
        printf("\nreceive: %s\n", buffer4);
```
Terakhir, kita masukkan hasil pada histori.log
```c
         //==================//
        //   L O G G I N G  //  
       //==================//
        FILE *fp; 
        fp = fopen ("histori.log", "a"); // Membuka file log dan membuat file tsb kalo belum ada dengan "a" (appendix)
        fprintf(fp, buffer4);    
        fclose(fp);

        close(pipefd1[1]); // tutup write-end pipa 1 dari parent
        close(pipefd2[0]); // tutup read-end  pipa 2 dari parent
        wait(NULL); // Wait for the child to terminate
        exit(EXIT_SUCCESS);
    }

}

// Kegunaan Parent sama Child Process disini
// Parent Process: Membaca input, menulis ke dalam pipe untuk diteruskan ke child, menunggu child selesai, dan kemudian membaca hasil dari child dan menuliskannya ke file histori.log. (ya intinya baca input terus masukin data ke log)
// Child Process: Membaca input dari pipe yang diberikan oleh parent, melakukan operasi matematika, mengonversi hasil operasi menjadi teks bahasa Indonesia menggunakan fungsi NumberToBahasa, menuliskan hasil ke dalam pipe yang diberikan ke parent, dan kemudian keluar dari proses. (misal 32 jadi tiga puluh dua)
```

Berikut adalah contoh peng-inputan pada terminal, serta hasil output-nya:
![Screenshot from 2024-05-09 19-30-00](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/151893499/c707740d-4409-49f4-9344-b4c493ae1b0c)

Dan ini adalah hasil didalam log-nya:
![Screenshot from 2024-05-09 19-30-20](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/151893499/0f9730d4-1f25-49f9-8d0f-a8542737f608)

   
## Soal 3
**actions.c**
```c
#include <stdio.h>
#include <string.h>
#include "action.h"

char* handle_gap(float distance) {
    if (distance < 3.5) {
        return "Gogogo";
    } else if (distance >= 3.5 && distance <= 10) {
        return "Push";
    } else if (distance > 10){
        return "Stay out of trouble";
    } else {
        return "Invalid info";
    }
}

char* handle_fuel(float fuel_percent) {
    if (fuel_percent > 80) {
        return "Push Push Push";
    } else if (fuel_percent >= 50 && fuel_percent <= 80) {
        return "You can go";
    } else if (fuel_percent < 50){
        return "Conserve Fuel";
    } else {
        return "Invalid info";
    }
}

char* handle_tire(int tire_wear) {
    if (tire_wear > 80) {
        return "Go Push Go Push";
    } else if (tire_wear >= 50 && tire_wear <= 80) {
        return "Good Tire Wear";
    } else if (tire_wear >= 30 && tire_wear < 50) {
        return "Conserve Your Tire";
    } else if (tire_wear < 30){
        return "Box Box Box";
    } else {
        return "Invalid info";
    }
}

char* handle_tire_change(char* current_tire) {
    if (strcmp(current_tire, "Soft") == 0) {
        return "Mediums Ready";
    } else if (strcmp(current_tire, "Medium") == 0) {
        return "Box for Softs";
    } else {
        return "Invalid tire type";
    }
}
```

actions.c berisi function yang bisa di panggil oleh paddock.c. ``#include "action.h"`` digunakan sebagai header file agar paddock dapat memanggil function pada action.c.
<ul>
<li> handle_gap akan di panggil jika driver menggunakan command Gap
<li> handle_fuel akan di panggil jika driver menggunakan command Fuel
<li> handle_tire akan di panggil jika driver menggunakan command Tire
<li> handle_tire_change akan di panggil jika driver menggunakan command TireChange
</ul>


**driver.c **
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_LEN 20


int establish_connection() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void send_rpc_call(int sockfd, const char* command, const char* info) {
    char buffer[1024] = {0};
    snprintf(buffer, sizeof(buffer), "%s %s\n", command, info);
    send(sockfd, buffer, strlen(buffer), 0);
}

void receive_response(int sockfd) {
    char buffer[1024] = {0};
    read(sockfd, buffer, 1024);
    printf("Response from paddock: %s\n", buffer);
}

int main(int argc, char const *argv[]) {
    char command[MAX_LEN];
    char info[MAX_LEN];

    while (1){
    int sockfd = establish_connection();

    printf("Command: ");
    fgets(command, sizeof(command), stdin);

    printf("Info : ");
    fgets(info, sizeof(info), stdin);

    send_rpc_call(sockfd, command, info);
    receive_response(sockfd);
    }

    return 0;
}
```
driver.c bertanggung jawab untuk mengirim permintaan ke paddock melalui koneksi RPC. Setelah mengirim permintaan, program akan menunggu dan mencetak balasan dari paddock.

```c
void send_rpc_call(int sockfd, const char* command, const char* info) {
    char buffer[1024] = {0};
    snprintf(buffer, sizeof(buffer), "%s %s\n", command, info);
    send(sockfd, buffer, strlen(buffer), 0);
}
```
function send_rpc_call digunakan untuk mengirim pesan ke paddock. sprints akan menyimpan char command dan info menjadi satu di char buffer. 

**paddock.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include "action.h"

#define PORT 8080

void log_message(const char* source, const char* command, const char* additional_info) {
    time_t rawtime;
    struct tm *info;
    char timestamp[80];

    time(&rawtime);
    info = localtime(&rawtime);

    strftime(timestamp, 80, "%d/%m/%Y %H:%M:%S", info);

    FILE *fp = fopen("/home/kali/sisoptest/modul3/race.log", "a");
    if (fp == NULL) {
        perror("Failed to open log file");
        return;
    }

    fprintf(fp, "[%s] [%s]: [%s] [%s]\n", source, timestamp, command, additional_info);
    fclose(fp);
}

void handle_rpc_call(int new_socket) {
    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);

    char command[50];
    char info[50];

    sscanf(buffer, "%s %s", command, info);
    log_message("Driver", command, info);

    char response[1024] = {0};

    if (strcmp(command, "Gap") == 0) {
        float distance = atof(info);
        strcpy(response, handle_gap(distance));
    } else if (strcmp(command, "Fuel") == 0) {
        int fuel = atoi(info);
       strcpy(response, handle_fuel(fuel));
    } else if (strcmp(command, "Tire") == 0) {
        int tire_wear = atoi(info);
        strcpy(response, handle_tire(tire_wear));
    } else if (strcmp(command, "TireChange") == 0) {
        strcpy(response, handle_tire_change(info));
    } else {
        strcpy(response, "Invalid command");
    }

    send(new_socket, response, strlen(response), 0);
    log_message("Paddock", command, response);

    close(new_socket);
}

static void skeleton_daemon()
{
    pid_t pid, sid;
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return;
    }

    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0)
    {
        perror("SID failed");
        return;
    }

    if ((chdir("/")) < 0)
    {
        perror("Chdir failed");
        return;
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    openlog("paddock", LOG_PID, LOG_DAEMON);
    syslog(LOG_NOTICE, "paddock started");
}

int main() {
    skeleton_daemon();

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        return 1;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
    }

    while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept failed");
        continue;
    }

        handle_rpc_call(new_socket);
    }

    syslog (LOG_NOTICE, "Paddock terminated.");
    closelog();
    
    return EXIT_SUCCESS;
}
```
paddock.c menerima permintaan dari pengemudi, memprosesnya, dan mengirimkan respons kembali kepada pengemudi. Program ini juga berfungsi sebagai daemon, berarti ia berjalan sebagai layanan latar belakang yang berkelanjutan.

<ul>
<li>#include "action.h" juga digunakan sebagai header file agar paddock bisa memanggil function dari actions.c. 

<li>void log_message digunakan untuk melakukan log percakapan ke race.log. log_message akan melakukan log command dari driver dengan log_message("Driver", command, info);. Kemudian setelah responces telah terisi log_message dipanggil kembali untuk melakukan log command dan response yang diberikan paddock log_message("Paddock", command, response);
</ul>

>Screenshots:
>
>![image](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/128571877/a2f4d1e4-2afa-414f-8bdc-6a98adda023a)
>
>COMMANDS
>
>![image](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/128571877/c7a05290-6105-4732-9493-0807423e1db3)
>
>![image](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/128571877/0372965b-ccf2-4e03-8247-8108aa75776e)
>
>![image](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/128571877/d512e10a-674b-4d29-b608-ee6de4219b2a)
>
>![image](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/128571877/ae4afdcb-da97-46bd-b872-bd169e110e86)
>
>![image](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/128571877/7b863528-3fcf-4ea1-b3d6-cc4e0533789b)
>
>ERROR HANDLING
>
>![image](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/128571877/b2849f88-0c88-447f-8a3d-d89294b64676)
>
>RACE.LOG
>
>![image](https://github.com/ch0clat/Sisop-3-2024-MH-IT18/assets/128571877/31d03428-2c11-469f-bb44-c31bf18c9864)

### Revisi Soal 3

<ul>
<li>Menambahkan header #include "action.h" dari actions.c agar paddock dapat mengakses functions di dalam actions.c.
</ul>

## Soal 4

Pengerjaan soal 4 masih terkendala dan belum berhasil pada kebanyakan fungsinya. client dan server berhasil terhubung namun server belum bisa melakukan response.

**client.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    send(sock, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    while (1) {
        printf("Enter a command: ");
        fgets(buffer, sizeof(buffer), stdin);

        send(sock, buffer, strlen(buffer), 0);

        valread = read(sock, buffer, 1024);
        printf("Server response: %s\n", buffer);
    }

    return 0;
}
```

**server.c**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_LINE_LENGTH 255
#define PORT 8080

void send_message(int sockfd, const char *message) {
    send(sockfd, message, strlen(message), 0);
}

void show(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "r");
    char line[MAX_LINE_LENGTH];

    if (list == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    while (fgets(line, sizeof(line), list) != NULL) {
        send_message(sockfd, line);
    }

    fclose(list);
}

void add_row(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "a");
    char type [5] = "ADD";
    if (list == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    fprintf(list, "%s\n", options);
    change_log(type, options);
    fclose(list);
    send_message(sockfd, "Row added successfully.\n");
}

void search_row(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "r");
    char line[MAX_LINE_LENGTH];
    int found = 0;
    int row_number = 0;
    char *token;

    if (list == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    char title[MAX_LINE_LENGTH];
    sscanf(options, "%[^\n]", title);

    while (fgets(line, sizeof(line), list) != NULL) {
        row_number++;
        int column_number = 0;
        char *field[MAX_LINE_LENGTH];

        token = strtok(line, ",");
        while (token != NULL && column_number <= 4){
            field[column_number++] = token;
            token = strtok(NULL, ",");
        }

        if (column_number == 2 && strcmp(field[2], title) == 0){
            found = 1;
            send_message(sockfd, line);
        }
        
    }

    fclose(list);

    if (!found) {
        send_message(sockfd, "Row not found.\n");
    }
}

void status_search(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "r");
    char line[MAX_LINE_LENGTH];
    int found = 0;

    if (list == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    char title[MAX_LINE_LENGTH];
    sscanf(options, "%[^\n]", title);

    while (fgets(line, sizeof(line), list) != NULL) {
        if (strstr(line, title) != NULL) {
            found = 1;
            send_message(sockfd, line);
        }
    }

    fclose(list);

    if (!found) {
        send_message(sockfd, "Row not found.\n");
    }
}

void delete_row(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "r");
    FILE *temp = fopen("temp.csv", "w");
    char line[MAX_LINE_LENGTH];
    char type[5] = "DEL";

    if (list == NULL || temp == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    int found = 0;
    while (fgets(line, sizeof(line), list) != NULL) {
        if (strstr(line, options) != NULL) {
            found = 1;
            continue;
        }
        fprintf(temp, "%s", line);
    }

    fclose(list);
    fclose(temp);

    if (found) {
        remove("myanimelist.csv");
        rename("temp.csv", "myanimelist.csv");
        change_log(type, options);
        send_message(sockfd, "Row deleted successfully.\n");
    } else {
        remove("temp.csv");
        send_message(sockfd, "Row not found.\n");
    }
}

void change_log(char *type, char *changes){
    FILE *log = fopen("change.log", "a");
    time_t currentDate;
    struct tm *localTime;

    time(&currentDate);
    localTime = localtime(&currentDate);

    char dateFormat[9];
    strftime(dateFormat, sizeof(dateFormat), "%d,%m,%y", localtime);
    

    fprinf(log, "[%s] [%s] [%s]", dateFormat, type, changes);

    fclose(log);
}

void handle_command(char *command, int sockfd) {
    char input[MAX_LINE_LENGTH];
    strcpy(input, command);
    int i;

    char options[MAX_LINE_LENGTH];
    char cmd[MAX_LINE_LENGTH];
    sscanf(input, "%s %[^\n]", cmd, options);

    // char *cmd = strtok(input, " ");
    // int len = strlen(input);

    // for (i = 0; i < len; i++){
    //     if (input[i] == ' '){
    //         break;
    //     }
    // }

    // for (int j = 0; j < len - i; j++){
    //     input[j] = input[j + i + 1];
    // }
    
    // input[len - i] = '\0';
    // strcpy(options, input);

    if (strcmp(cmd, "show") == 0) {
        show(options, sockfd);
    } else if (strcmp(cmd, "exit") == 0) {
        send_message(sockfd, "Exiting\n");
        exit(EXIT_SUCCESS);
    } else if (strcmp(cmd, "add") == 0) {
        add_row(options, sockfd);
    } else if (strcmp(cmd, "search") == 0) {
        search_row(options, sockfd);
    } else if (strcmp(cmd, "delete") == 0) {
        delete_row(options, sockfd);
    } else if (strcmp(cmd, "status") == 0) {
        status_search(options, sockfd);
    }
    else {
        send_message(sockfd, "Invalid command\n");
    }
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    char buffer[1024] = {0};
    char *hello = "Connection established\n";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    send(new_socket, hello, strlen(hello), 0);

    while (1) {
        valread = read(new_socket, buffer, 1024);
        printf("Client: %s\n", buffer);
        handle_command(buffer, new_socket);
    }

    return 0;
}
```
