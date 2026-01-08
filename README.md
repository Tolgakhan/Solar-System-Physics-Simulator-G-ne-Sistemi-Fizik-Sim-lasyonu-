# Solar System Physics Simulator (Güneş Sistemi Fizik Simülasyonu)

Bu proje, **C programlama dili** kullanılarak geliştirilmiş, Güneş Sistemi'ndeki 8 farklı gezegenin yerçekimi ivmelerine ($g$) dayalı fiziksel olayları hesaplayan interaktif bir simülasyon aracıdır.

Proje, temel fizik formüllerini **işaretçi aritmetiği (pointer arithmetic)** ve **modüler programlama** teknikleri ile birleştirerek, kullanıcının girdiği verileri tüm gezegenler için aynı anda işler.

##  Özellikler

Bu simülasyon, aşağıdaki **9 farklı fiziksel deneyi** 8 gezegen (Merkür, Venüs, Dünya, Mars, Jüpiter, Satürn, Uranüs, Neptün) için gerçekleştirebilir:

1.  **Serbest Düşme:** Belirli bir sürede düşülen mesafenin hesaplanması.
2.  **Yukarı Atış:** Fırlatılan cismin çıkabileceği maksimum yükseklik.
3.  **Ağırlık Hesabı:** Kütlenin farklı yerçekimi ortamlarındaki ağırlık karşılığı.
4.  **Potansiyel Enerji:** Kütleçekimsel potansiyel enerji değişimi.
5.  **Hidrostatik Basınç:** Sıvı basıncının yerçekimine bağlı değişimi.
6.  **Arşimet Prensibi:** Sıvıların kaldırma kuvveti hesaplamaları.
7.  **Basit Sarkaç:** Salınım periyodunun ($T$) gezegenlere göre değişimi.
8.  **İp Gerilmesi:** Sabit asılı cisimlerdeki gerilme kuvveti.
9.  **Asansör Problemi:** İvmeli sistemlerde hissedilen ağırlık (Eylemsizlik).

## Teknik Detaylar

Bu proje sadece fizik formüllerini değil, aynı zamanda C dilinin önemli konseptlerini de içerir:

* **Pointer Aritmetiği:** Dizilere indeks (`arr[i]`) yerine bellek adresleri (`*(ptr + i)`) üzerinden erişim sağlanmıştır.
* **Modüler Yapı:** Her deney ayrı bir fonksiyon olarak tasarlanmış, kod okunabilirliği artırılmıştır.
* **Girdi Doğrulama (Input Validation):** Kullanıcı hatalarına karşı (örn: negatif zaman girişi) `Ternary Operator` kullanılarak koruma mekanizmaları geliştirilmiştir.
* **Matematik Kütüphanesi:** `<math.h>` kütüphanesi aktif olarak kullanılmıştır.

## Kurulum ve Çalıştırma

Projeyi kendi bilgisayarınızda çalıştırmak için aşağıdaki adımları izleyebilirsiniz:

1.  **Repo'yu klonlayın:**
    ```bash
    git clone [https://github.com/Tolgakhan/solar-system-physics.git](https://github.com/Tolgakhan/solar-system-physics.git)
    ```
2.  **Dizine gidin:**
    ```bash
    cd solar-system-physics
    ```
3.  **Derleyin (GCC ile):**
    ```bash
    gcc main.c -o physics_sim -lm
    ```
    *(Not: `-lm` bayrağı Linux/macOS sistemlerde matematik kütüphanesini bağlamak için gereklidir.)*

4.  **Çalıştırın:**
    * Windows: `physics_sim.exe`
    * Linux/Mac: `./physics_sim`

##  Gezegen Verileri

Simülasyonda kullanılan yerçekimi ivmesi ($m/s^2$) değerleri:

| Gezegen | Yerçekimi ($g$) |
| :--- | :--- |
| Merkür | 3.70 |
| Venüs | 8.87 |
| Dünya | 9.80 |
| Mars | 3.71 |
| Jüpiter | 24.79 |
| Satürn | 10.44 |
| Uranüs | 8.69 |
| Neptün | 11.15 |

##  Lisans

Bu proje eğitim amaçlı geliştirilmiştir. Kaynak gösterilerek serbestçe kullanılabilir.

---

**Geliştirici:** [Senin Adın]
**Tarih:** Ocak 2026
