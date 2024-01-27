# Seri Port Verisi ile Fare Hareketi Projesi

Bu proje, bir Arduino kartı ve bir ultrasonik sensör kullanarak alınan seri port verilerine göre fareyi hareket ettiren bir Python scriptini içerir.

## Gereksinimler

- Arduino kartı (Örneğin: Arduino Uno)
- Bir ultrasonik sensör
- Bilgisayar (Python yüklü olmalıdır)
- USB kablosu ile Arduino'nun bilgisayara bağlanması

## Durum

Bu proje henüz tamamlanmamıştır ve geliştirmeye devam edilmektedir. Eksik veya geliştirilecek olan özellikler şunlar olabilir:

- [ ] Detaylı devre şemasının eklenmesi
- [ ] Projede kullanılan kütüphanelerin açıklanması
- [ ] Performans ve hata kontrolü iyileştirmeleri

## Devre Şeması

[Devre Şeması Burada Olabilir]

## Bağlantılar

- Arduino Kartı:
  - Veri Gönderim Pini: Belirtilen port üzerinden
  - Toprak ve Güç Bağlantıları: Standart bağlantılara göre

## Python Kodu

Python kodu `fare_hareketi.py` adlı dosyada bulunmaktadır.

```python
import serial
import pyautogui

ser = serial.Serial('/dev/cu.usbserial-10', 9600)  # Port adını ve baud rate'i ayarlayın

while True:
    try:
        line = ser.readline().decode('utf-8').strip()
        if line:
            print(line)

            # Gelen veriyi integer'a çevir
            value = int(line)

            # Gelen veriye göre fareyi hareket ettir
            if value == 21:
                pyautogui.move(0, -50)  # 5 birim yukarı
            elif value == 20:
                pyautogui.move(0, 50)   # 5 birim aşağı
            elif value == 11:
                pyautogui.move(-50, 0)  # 5 birim sola
            elif value == 10:
                pyautogui.move(50, 0)   # 5 birim sağa

    except ValueError:
        print("Geçersiz veri! Sayıya çevrilemiyor.")

    except KeyboardInterrupt:
        break

ser.close()


## Kullanım

1. Arduino kartınızı bilgisayarınıza bağlayın.
2. Python scriptini çalıştırarak seri port üzerinden gelen verileri okuyun ve fareyi hareket ettirin.

## Proje Amacı

Bu proje, ultrasonik sensörler ve Arduino kullanılarak yapılmış bir prototiptir. Amacı, fiziksel bir cisme yaklaşma veya uzaklaşma durumlarına bağlı olarak bilgisayar fare hareketini kontrol etmektir. Projenin geliştirilmesi ve iyileştirilmesi için geri bildirimler ve katkılar her zaman hoş karşılanmaktadır.

