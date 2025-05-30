#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct kdm{
    char khodam[5][30]; // urutan dimensi array
    char keku[5][30];   // urutan dimensi array
};

// Inisialisasi data khodam
void initKhodam(struct kdm *k){
    strcpy(k->khodam[0], "Maung galak");
    strcpy(k->khodam[1], "Prabu sindangsari");
    strcpy(k->khodam[2], "Lauk patin");
    strcpy(k->khodam[3], "Boneca ambalabu");
    strcpy(k->khodam[4], "Monyet karangkamulyan");

    strcpy(k->keku[0], "Aura emas");
    strcpy(k->keku[1], "Auman ganas");
    strcpy(k->keku[2], "Patilan maut");
    strcpy(k->keku[3], "Penghitaman massal");
    strcpy(k->keku[4], "Raja hutan");
}

void tampilkanKhodam(struct kdm *k, char *nama){
    // Menghitung hash sederhana dari nama untuk memilih khodam
    int hash = 0;
    for(int i = 0; nama[i] != '\0'; i++){
        hash += nama[i];
    }
    int index = hash % 5; // Pilih index 0-4

    printf("\nHalo %s!\n", nama);
    printf("Khodam kamu adalah: %s\n", k->khodam[index]);
    printf("Kekuatan nya: %s\n", k->keku[index]);
}

int validasiNama(char *nama){
    // Cek apakah nama hanya berisi huruf dan spasi
    for(int i = 0; nama[i] != '\0'; i++){
        if(!isalpha(nama[i]) && nama[i] != ' '){
            return 0; // Tidak valid
        }
    }
    return 1; // Valid
}

int main(void){
    struct kdm khodam_data;
    char nama[20];

    // Menginisialisasi data khodam
    initKhodam(&khodam_data);

    do {
        printf("Input nama mu: ");
        fgets(nama, sizeof(nama), stdin);

        // Menghapus newline dari fgets
        nama[strcspn(nama, "\n")] = '\0';

        if(strlen(nama) == 0 || !validasiNama(nama)){
            printf("Nama tidak valid! Masukkan nama yang hanya berisi huruf.\n\n");
        } else {
            tampilkanKhodam(&khodam_data, nama);
            break;
        }
    } while(1);

    printf("\nTekan tombol apa saja untuk keluar...");
    getch();
    return 0;
}
