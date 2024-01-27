# Seri Port Verisi ile Fare Hareketi Projesi

Bu proje, bir Arduino kartı ve bir ultrasonik sensör kullanarak alınan seri port verilerine göre fareyi hareket ettiren bir Python scriptini içerir.

## Version v2.3

## Gereksinimler

- Arduino kartı (Örneğin: Arduino Uno)
- 1 yada (isteğe bağlı) 2 ultrasonik sensör
- Python 3.x

## Durum

Bu proje henüz tamamlanmamıştır ve geliştirmeye devam edilmektedir. Eksik veya geliştirilecek olan özellikler:

- [ ] Detaylı devre şemasının eklenmesi
- [ ] Performans ve hata kontrolü iyileştirmeleri

## Devre Şeması

[Devre Şeması Yakın Zamanda Eklenecektir]

## Bağlantılar

- Arduino Kartı:
  - Veri Gönderim Pini: Belirtilen port üzerinden
  - Toprak ve Güç Bağlantıları: Standart bağlantılara göre

## Python Kodu

Python kodu `main.py` adlı dosyada bulunmaktadır.

```python
pip install serial
pip install pyautogui
```


## Kullanım

1. Arduino kartınızı bilgisayarınıza bağlayın.
2. Python scriptini çalıştırarak seri port üzerinden gelen verileri okuyun ve fareyi hareket ettirin.

## Proje Amacı

Bu proje, ultrasonik sensörler ve Arduino kullanılarak yapılmış bir prototiptir. Amacı, fiziksel bir cisme yaklaşma veya uzaklaşma durumlarına bağlı olarak bilgisayar fare hareketini kontrol etmektir. Projenin geliştirilmesi ve iyileştirilmesi için geri bildirimler ve katkılar her zaman hoş karşılanmaktadır.

## Uyarı

Proje unix ortamı üzerinde geliştirilmiştir, Windows ile uyumluluk göstermeyebilir, python kodunun içerisindeki pyautogui komutlarında değişiklik yapmanız gerekebilir.

