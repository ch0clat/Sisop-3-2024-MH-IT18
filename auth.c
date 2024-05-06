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
