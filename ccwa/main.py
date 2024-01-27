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
