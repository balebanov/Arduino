int indataPin = 11;  // Вывод чтения данных из 74HC165 (9).
int LOCKPin = 12; // Вывод CLK для 74HC165 (2).
int inloadPin = 13;  // Вывод выбора Параллельный ввод/последовательный вывод. Для 74HC165 (1).
int temp = 0;        // Переменная хранения приятых данных из 74HC165.

void setup(){ // Инициализация контролера.
Serial.begin(9600);          // Выбираем скорость обмена по UART.
pinMode(indataPin, INPUT);   // Настраиваем на Ввод для приёма данных из 74HC165.
pinMode(LOCKPin, OUTPUT); // Настраиваем на Вывод CLK на 74HC165.
pinMode(inloadPin, OUTPUT);  // Настраиваем на Вывод load на 74HC165.
}

void loop(){ // Главный програмный цикл
digitalWrite(inloadPin, 0);     // считываем все данные со входов 74HC165 в регистр.
digitalWrite(inloadPin, 1);     // выводим данные на последовательный вывод "Q7" 74HC165.
for(int i=0; i<=7; i++){       // В цикле считываем каждый из 8 входов (D0-D7) 74HC165.
 digitalWrite(LOCKPin, 0);   // Устанавливаем CLK в лог "0".
 temp = digitalRead(indataPin); // Читаем текущее состояние выхода данных "Q7" 74HC165. 
 digitalWrite(LOCKPin, 1);   // Устанавливаем CLK в лог "1" и этем завершаем вывод данных.
 Serial.print (temp);           // Отправляем данные из TEMP по UART
} 
Serial.println (""); 
Serial.println ("--------");
delay(500);
}
