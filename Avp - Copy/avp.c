#include <stdio.h>
#include <math.h> 
#include <string.h>

#define PI 3.14159265
#define PLANET_COUNT 8

// Gezegen isimleri (Global sabit)
const char *gezegenler[] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};

// Fonksiyon Prototipleri
void serbest_dusme(double *g_ptr);
void yukari_atis(double *g_ptr);
void agirlik_deneyi(double *g_ptr);
void potansiyel_enerji(double *g_ptr);
void hidrostatik_basinc(double *g_ptr);
void arsimet_kaldirma(double *g_ptr);
void basit_sarkac(double *g_ptr);
void ip_gerilmesi(double *g_ptr);
void asansor_deneyi(double *g_ptr);
void sonuclari_yazdir(char *deney_adi, double sonuc, char *birim, int gezegen_index);

int main() {
    // Gezegenlerin Yerçekimi İvmeleri (m/s^2) 
    // Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs, Neptün
    double g_ivmeleri[PLANET_COUNT] = {3.70, 8.87, 9.80, 3.71, 24.79, 10.44, 8.69, 11.15};
    
    char bilim_insani[50];
    int secim = 0;

    // 1. Bilim insanı adı alma
    printf("Lutfen bilim insaninin adini giriniz: ");
    scanf("%[^\n]s", bilim_insani); // Boşluklu isim alabilmek için

    while (secim != -1) {
        printf("\n==========================================\n");
        printf("Bilim Insani: %s\n", bilim_insani);
        printf("UZAY SIMULASYONU DENEY MENU\n");
        printf("==========================================\n");
        printf("1. Serbest Dusme Deneyi\n");
        printf("2. Yukari Atis Deneyi\n");
        printf("3. Agirlik Deneyi\n");
        printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
        printf("5. Hidrostatik Basinc Deneyi\n");
        printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
        printf("7. Basit Sarkac Periyodu Deneyi\n");
        printf("8. Sabit Ip Gerilmesi Deneyi\n");
        printf("9. Asansor Deneyi\n");
        printf("Cikis icin -1 giriniz.\n"); 
        printf("Seciminiz: ");
        scanf("%d", &secim);

        // Menü yönlendirmesi
        switch (secim) {
            case 1: serbest_dusme(g_ivmeleri); break;
            case 2: yukari_atis(g_ivmeleri); break;
            case 3: agirlik_deneyi(g_ivmeleri); break;
            case 4: potansiyel_enerji(g_ivmeleri); break;
            case 5: hidrostatik_basinc(g_ivmeleri); break;
            case 6: arsimet_kaldirma(g_ivmeleri); break;
            case 7: basit_sarkac(g_ivmeleri); break;
            case 8: ip_gerilmesi(g_ivmeleri); break;
            case 9: asansor_deneyi(g_ivmeleri); break;
            case -1: printf("Simulasyondan cikiliyor...\n"); break;
            default: printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }

    return 0;
}

// 1. Serbest Düşme Deneyi 
// h = 1/2 * g * t^2
void serbest_dusme(double *g_ptr) {
    double t, h;
    printf("\n--- Serbest Dusme Deneyi ---\n");
    printf("Sureyi (t) saniye cinsinden giriniz: ");
    scanf("%lf", &t);
    
    //Negatif değer ternary ile düzeltilir 
    t = (t < 0) ? -t : t;

    printf("\nSonuclar (Giris t: %.2f s):\n", t);
    for (int i = 0; i < PLANET_COUNT; i++) {
        // Pointer aritmetiği ile g değerine ulaşım: *(g_ptr + i)
        double g = *(g_ptr + i);
        h = 0.5 * g * t * t;
        sonuclari_yazdir("Kat Edilen Yol (h)", h, "m", i);
    }
}

// 2. Yukarı Atış Deneyi
// h_max = v0^2 / (2*g)
void yukari_atis(double *g_ptr) {
    double v0, h_max;
    printf("\n--- Yukari Atis Deneyi ---\n");
    printf("Firlatma hizini (v0) m/s cinsinden giriniz: ");
    scanf("%lf", &v0);

    //Mutlak değer 
    v0 = (v0 < 0) ? -v0 : v0;

    printf("\nSonuclar (Giris v0: %.2f m/s):\n", v0);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        h_max = (v0 * v0) / (2 * g);
        sonuclari_yazdir("Maksimum Yukseklik (h_max)", h_max, "m", i);
    }
}

// 3. Ağırlık Deneyi
// G = m * g
void agirlik_deneyi(double *g_ptr) {
    double m, G;
    printf("\n--- Agirlik Deneyi ---\n");
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);

    // Negatif kütle olamaz
    m = (m < 0) ? -m : m;

    printf("\nSonuclar (Giris m: %.2f kg):\n", m);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        G = m * g;
        sonuclari_yazdir("Agirlik (G)", G, "N", i);
    }
}

// 4. Kütleçekimsel Potansiyel Enerji Deneyi 
// Ep = m * g * h
void potansiyel_enerji(double *g_ptr) {
    double m, h, Ep;
    printf("\n--- Potansiyel Enerji Deneyi ---\n");
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);
    printf("Yuksekligi (h) metre cinsinden giriniz: ");
    scanf("%lf", &h);

    //Negatif değer kontrolü
    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    printf("\nSonuclar (m: %.2f kg, h: %.2f m):\n", m, h);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        Ep = m * g * h;
        sonuclari_yazdir("Potansiyel Enerji (Ep)", Ep, "Joule", i);
    }
}

// 5. Hidrostatik Basınç Deneyi
// P = rho * g * h
void hidrostatik_basinc(double *g_ptr) {
    double rho, h, P;
    printf("\n--- Hidrostatik Basinc Deneyi ---\n");
    printf("Sivinin yogunlugunu (rho) kg/m3 cinsinden giriniz: ");
    scanf("%lf", &rho);
    printf("Derinligi (h) metre cinsinden giriniz: ");
    scanf("%lf", &h);

    //Negatif değer kontrolü
    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;

    printf("\nSonuclar (rho: %.2f kg/m3, h: %.2f m):\n", rho, h);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        P = rho * g * h;
        sonuclari_yazdir("Hidrostatik Basinc (P)", P, "Pa", i);
    }
}

// 6. Arşimet Kaldırma Kuvveti Deneyi 
// Fk = rho * g * V
void arsimet_kaldirma(double *g_ptr) {
    double rho, V, Fk;
    printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    printf("Sivinin yogunlugunu (rho) kg/m3 cinsinden giriniz: ");
    scanf("%lf", &rho);
    printf("Batan hacmi (V) m3 cinsinden giriniz: ");
    scanf("%lf", &V);

    //Negatif değer kontrolü
    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;

    printf("\nSonuclar (rho: %.2f kg/m3, V: %.4f m3):\n", rho, V);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        Fk = rho * g * V;
        sonuclari_yazdir("Kaldirma Kuvveti (Fk)", Fk, "N", i);
    }
}

// 7. Basit Sarkaç Periyodu Deneyi 
// T = 2 * pi * sqrt(L / g)
void basit_sarkac(double *g_ptr) {
    double L, T;
    printf("\n--- Basit Sarkac Deneyi ---\n");
    printf("Sarkac uzunlugunu (L) metre cinsinden giriniz: ");
    scanf("%lf", &L);

    //Negatif değer kontrolü
    L = (L < 0) ? -L : L;

    printf("\nSonuclar (L: %.2f m):\n", L);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        T = 2 * PI * sqrt(L / g);
        sonuclari_yazdir("Periyot (T)", T, "s", i);
    }
}

// 8. Sabit İp Gerilmesi Deneyi 
// T = m * g
void ip_gerilmesi(double *g_ptr) {
    double m, T;
    printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);

    //Negatif değer kontrolü
    m = (m < 0) ? -m : m;

    printf("\nSonuclar (m: %.2f kg):\n", m);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        T = m * g;
        sonuclari_yazdir("Ip Gerilmesi (T)", T, "N", i);
    }
}

// 9. Asansör Deneyi 
// Duruma göre N = m(g + a) veya N = m(g - a)
void asansor_deneyi(double *g_ptr) {
    double m, a, N;
    int durum;
    
    printf("\n--- Asansor Deneyi ---\n");
    printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
    scanf("%lf", &m);
    printf("Asansor ivmesini (a) m/s2 cinsinden giriniz: ");
    scanf("%lf", &a);
    
    printf("Asansorun durumu nedir?\n");
    printf("1. Yukari Hizlanan veya Asagi Yavaslayan (Agirlik Artar)\n");
    printf("2. Asagi Hizlanan veya Yukari Yavaslayan (Agirlik Azalir)\n");
    printf("Seciminiz (1 veya 2): ");
    scanf("%d", &durum);

    // Negatif değer kontrolü
    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    printf("\nSonuclar (m: %.2f kg, a: %.2f m/s2):\n", m, a);
    for (int i = 0; i < PLANET_COUNT; i++) {
        double g = *(g_ptr + i);
        
        // Ternary ile formül seçimi (if yerine)
        // Eğer durum 1 ise (g+a), değilse (g-a)
        N = (durum == 1) ? m * (g + a) : m * (g - a);
        
        // Asansör aşağı g'den hızlı düşerse ip gerilmesi negatif çıkabilir, 
        // fiziksel olarak ip gevşer (0 olur) ama formül gereği direkt sonucu yazıyoruz.
        sonuclari_yazdir("Hissedilen Agirlik (N)", N, "N", i);
    }
}

//Sonuçları yazdırmak için
void sonuclari_yazdir(char *deney_adi, double sonuc, char *birim, int gezegen_index) {
    // Gezegen ismine dizi notasyonu yerine pointer aritmetiği ile erişiyoruz:
    // gezegenler dizisi string pointerları tutar. 
    // *(gezegenler + gezegen_index) bize ilgili stringi verir.
    printf("%-10s -> %s: %.2f %s\n", *(gezegenler + gezegen_index), deney_adi, sonuc, birim);
}