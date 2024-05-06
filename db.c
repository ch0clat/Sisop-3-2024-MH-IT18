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
