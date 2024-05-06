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
