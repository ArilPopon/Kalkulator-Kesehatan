#include <stdio.h>

// Fungsi untuk menghitung IMT
void hitungIMT() {
    float berat, tinggi, imt;
    
    printf("Masukkan berat badan (kg): ");
    scanf("%f", &berat);
    
    printf("Masukkan tinggi badan (cm): ");
    scanf("%f", &tinggi);
    
    tinggi = tinggi / 100; // konversi tinggi dari cm ke meter
    imt = berat / (tinggi * tinggi);
    
    printf("Indeks Massa Tubuh (IMT) Anda adalah: %.2f\n", imt);
    // Menentukan kategori IMT
    if (imt < 18.5) {
        printf("Anda kekurangan berat badan.\n");
    } else if (imt >= 18.5 && imt < 24.9) {
            printf("Berat badan Anda normal.\n");
    } else if (imt >= 24.9 && imt < 29.9) {
            printf("Anda kelebihan berat badan.\n");
    } else {
            printf("Anda mengalami obesitas.\n");
    }
    
    // Menampilkan rentang IMT
    printf("\nKategori IMT:\n");
    printf("Kekurangan berat badan: IMT < 18.5\n");
    printf("Normal: 18.5 <= IMT < 24.9\n");
    printf("Kelebihan berat badan: 24.9 <= IMT < 29.9\n");
    printf("Obesitas: IMT >= 30\n");
}

// Fungsi untuk menghitung jumlah hari dalam bulan tertentu
int jumlahHariDalamBulan(int bulan, int tahun) {
    switch (bulan) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // Memeriksa apakah tahun adalah tahun kabisat
            if ((tahun % 4 == 0 && tahun % 100 != 0) || (tahun % 400 == 0))
                return 29;
            else
                return 28;
        default:
            return 0; // Bulan tidak valid
    }
}

// Fungsi untuk menghitung masa subur
void hitungMasaSubur() {
    int hari_pertama_haid, bulan, tahun, siklus;
    printf("Masukkan hari pertama haid terakhir (format: hari-bulan-tahun, misal 12-05-2024): ");
    scanf("%d-%d-%d", &hari_pertama_haid, &bulan, &tahun);
    
    printf("Masukkan panjang siklus haid (dalam hari): ");
    scanf("%d", &siklus);

    int masa_subur_awal = hari_pertama_haid + siklus - 19;
    int masa_subur_akhir = hari_pertama_haid + siklus - 9;

    // Menyesuaikan hari, bulan, dan tahun untuk masa subur awal
    while (masa_subur_awal > jumlahHariDalamBulan(bulan, tahun)) {
        masa_subur_awal -= jumlahHariDalamBulan(bulan, tahun);
        bulan++;
        if (bulan > 12) {
            bulan = 1;
            tahun++;
        }
    }

    // Menyesuaikan hari, bulan, dan tahun untuk masa subur akhir
    while (masa_subur_akhir > jumlahHariDalamBulan(bulan, tahun)) {
        masa_subur_akhir -= jumlahHariDalamBulan(bulan, tahun);
        bulan++;
        if (bulan > 12) {
            bulan = 1;
            tahun++;
        }
    }

    printf("Perkiraan masa subur Anda adalah antara tanggal %02d-%02d-%d dan %02d-%02d-%d\n",
           masa_subur_awal, bulan, tahun,
           masa_subur_akhir, bulan, tahun);
}

// Fungsi untuk menghitung perkiraan tanggal kelahiran
void hitungKehamilan() {
    int hari_pertama_haid, bulan, tahun;
    printf("Masukkan hari pertama haid terakhir (dalam format dd mm yyyy, misal 12 5 2024): ");
    scanf("%d %d %d", &hari_pertama_haid, &bulan, &tahun);

    hari_pertama_haid += 280;
    while (hari_pertama_haid > jumlahHariDalamBulan(bulan, tahun)) {
        hari_pertama_haid -= jumlahHariDalamBulan(bulan, tahun);
        bulan++;
        if (bulan > 12) {
            bulan = 1;
            tahun++;
        }
    }
    printf("Perkiraan tanggal kelahiran adalah: %02d-%02d-%d\n", hari_pertama_haid, bulan, tahun);
}

int main() {
    int pilihan;
    
    printf("Selamat datang di Program Kalkulator Kesehatan!\n");
    printf("Silakan pilih kalkulator yang ingin Anda gunakan:\n");
    printf("1. Kalkulator IMT\n");
    printf("2. Kalkulator Masa Subur\n");
    printf("3. Kalkulator Kehamilan\n");
    printf("Pilihan Anda: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            hitungIMT();
            break;
        case 2:
            hitungMasaSubur();
            break;
        case 3:
            hitungKehamilan();
            break;
        default:
            printf("Pilihan tidak valid.\n");
            break;
    }
    
    return 0;
}

