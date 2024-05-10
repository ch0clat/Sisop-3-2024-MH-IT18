# Sisop-3-2024-MH-IT18
## Anggota kelompok
   ### Callista Meyra Azizah 5027231060
   ### Abhirama Triadyatma Hermawan 5027231061
   ### Adi Satria Pangestu 5027231043


# Soal
## Soal 1

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



## soal 2
Kita masukkan beberapa header sebagai library yang dipakai. Untuk penjelasan kegunaan tiap library, ada pada komentar.

```sh
#include <stdio.h> // Input-Output standar
#include <string.h> // Manipulasi string
#include <math.h> // Fungsi matematika
#include <time.h> // Mengelola date and time
#include <stdlib.h> // Alokasi memori, konversi string menjadi angka
#include <unistd.h> // pengelolaan proses, direktori, dan akses ke sistem
#include <sys/wait.h> // menunggu child process selesai
```

Selanjutnya, kita buat Array 'Kata', yang digunakan untuk menyimpan representasi string angka dari 0 hingga 9 dalam bahasa Indonesia.

```sh
// Deklarasi angka2 di Array 
char Kata[10][10] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"}; // Data2nya (nol sampai sembilan)
```

Setelah kita deklarasi Array 'Kata', kita deklarasi variabel-variabel lainnya. Variabel yang dideklarasikan mencakup: variabel untuk menyimpan hasil operasi matematika, file descriptor untuk pipe, process id untuk child process, dan buffer untuk menyimpan data yang dikirim melalui pipe.

```sh
int hasil;
char hasilchar[10];


    int pipefd1[2],pipefd2[2]; // File descriptors for the pipes
    pid_t child_pid;
    char buffer1[20],buffer2[20],buffer3[20],buffer4[1000];
    char argu[20];
    char maudicatat[1000];
```

Selesai mendeklarasikan variabel, kita gunakan fungsi Cari Angka, yang akan mencari angka dalam array Kata berdasarkan input yang diberikan. Jika angka ditemukan, fungsi akan mengembalikan indeksnya dalam array Kata.

```sh
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

```sh
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

```sh
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

```sh
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
```sh
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

```sh
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
```sh
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

## Soal 4
