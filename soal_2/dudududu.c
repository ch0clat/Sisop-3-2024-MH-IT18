#include <stdio.h> // Input-Output standar
#include <string.h> // Manipulasi string
#include <math.h> // Fungsi matematika
#include <time.h> // Mengelola date and time
#include <stdlib.h> // Alokasi memori, konversi string menjadi angka
#include <unistd.h> // pengelolaan proses, direktori, dan akses ke sistem
#include <sys/wait.h> // menunggu child process selesai

// Deklarasi angka2 di Array 
char Kata[10][10] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"}; // Data2nya (nol sampai sembilan)

int hasil;
char hasilchar[10];


    int pipefd1[2],pipefd2[2]; // File descriptors for the pipes
    pid_t child_pid;
    char buffer1[20],buffer2[20],buffer3[20],buffer4[1000];
    char argu[20];
    char maudicatat[1000];

// Mencari angka dari array "Kata"
int CariAngka(const char * KataYangDicari){
        for (int i = 0; i < 10; i++){
            if (strcmp(KataYangDicari, Kata[i]) == 0){  
                return i;
                break;
                }
            }
    }
    
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




int main(int argc, char* argv[])
{
    char KataPertama[50], KataKedua[50], FinalOutput[10];
    int AngkaPertama, AngkaKedua;
    char str1[50], str2[10];



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
