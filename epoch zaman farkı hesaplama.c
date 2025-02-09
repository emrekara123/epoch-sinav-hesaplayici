
#include <stdio.h>
#include <time.h>

struct TarihSaat {
    int yil;
    int ay;
    int gun;
    int saat;
    int dakika;
    int saniye;
};

// Epoch zamanını hesaplayan fonksiyon
time_t epochHesapla(struct TarihSaat ts) {
    struct tm zaman; // Tarih ve saat bilgilerini tutan yapı

    // Kullanıcının girdiği değerleri 'tm' yapısına aktarıyoruz
    zaman.tm_year = ts.yil - 1900; // Yıl, 1900'den başladığı için 1900 çıkarıyoruz
    zaman.tm_mon  = ts.ay - 1;     // Ay 0-11 arasında olduğu için 1 çıkarıyoruz
    zaman.tm_mday = ts.gun;        
    zaman.tm_hour = ts.saat;       
    zaman.tm_min  = ts.dakika;    
    zaman.tm_sec  = ts.saniye;     
   
    return mktime(&zaman); // Tarihi epoch zamanına çevir ve döndür
}

int main() {
    struct TarihSaat t1, t2; // İki farklı tarih ve saat tutan değişkenler
    time_t epoch1, epoch2;   // Epoch zamanlarını tutan değişkenler

    // Kullanıcıdan birinci tarihi al
    printf("Birinci tarih ve saat girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &t1.yil, &t1.ay, &t1.gun, &t1.saat, &t1.dakika, &t1.saniye);

    // Kullanıcıdan ikinci tarihi al
    printf("ikinci tarih ve saat girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &t2.yil, &t2.ay, &t2.gun, &t2.saat, &t2.dakika, &t2.saniye);

    // Epoch zamanlarını hesapla
    epoch1 = epochHesapla(t1);
    epoch2 = epochHesapla(t2);

    // Sonuçları ekrana yazdır
    printf("\nBirinci tarihin Epoch zamani: %ld\n", epoch1);
    printf("ikinci tarihin Epoch zamani: %ld\n", epoch2);
    printf("iki tarih arasindaki fark: %ld saniye\n", epoch2 - epoch1);

    return 0;
}  