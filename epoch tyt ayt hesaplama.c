#include <stdio.h>
#include <time.h>

struct TarihSaat {
    int yil, ay, gun;
};

// Tarihi epoch zamanına çeviren fonksiyon
double epochHesapla(struct TarihSaat ts) {
    struct tm zaman = {0}; // struct tm yapısını sıfırla
    zaman.tm_year = ts.yil - 1900; // Yıl 1900'den başladığı için 1900 çıkarıyoruz
    zaman.tm_mon  = ts.ay - 1;     // Ay 0-11 arasında olduğu için 1 çıkarıyoruz
    zaman.tm_mday = ts.gun;        // Gün olduğu gibi atanıyor
    
    return mktime(&zaman); // Tarihi epoch zamanına çevir ve döndür
}

int main() {
    struct TarihSaat bugun, tyt, ayt;
   double epochBugun, epochTYT, epochAYT;
    
    // Kullanıcıdan bugünün tarihini al
    printf("Bugunun tarihini girin (YYYY MM DD): ");
    scanf("%d %d %d", &bugun.yil, &bugun.ay, &bugun.gun);
    
    // TYT ve AYT sınav tarihleri 
    tyt.yil = 2025;
    tyt.ay = 6;
    tyt.gun = 21;
    
    ayt.yil = 2025;
    ayt.ay = 6;
    ayt.gun = 22;
    
    // Epoch zamanlarını hesapla
    epochBugun = epochHesapla(bugun);
    epochTYT  = epochHesapla(tyt);
    epochAYT  = epochHesapla(ayt);
    
    // Gün farklarını hesapla (saniye cinsinden farkı gün cinsine çeviriyoruz)
    int farkTYT = (epochTYT - epochBugun) / (60 * 60 * 24);
    int farkAYT = (epochAYT - epochBugun) / (60 * 60 * 24);
    
    // Sonucu ekrana yazdır
    printf("TYT'ye %ld gun kaldi.\n", farkTYT);
    printf("AYT'ye %ld gun kaldi.\n", farkAYT);
    
    return 0;
}
