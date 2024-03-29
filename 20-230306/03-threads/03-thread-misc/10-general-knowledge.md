* Процессоры с 2004 года не увеличивают принципиально частоту (Pentium 4 Prescott - 2.8 ГГц).
* С тех пор скорость работы повышается другими методами: размер кэша, скорость памяти, периферии.
* Уже уткнулись в ограничения размера процессора из-за скорости света.

Что делают для ускорения автоматически:

* Выполнять команды параллельно, если они независимы:
  ```
  int x = a * b;
  int y = a / b;
  ```
* В том числе команды, читающие из памяти.
* Многоканальная память.
* Переставить команды так, чтобы параллельности было побольше.

Что делают руками:

* Векторизация SIMD (Single-Instruction-Multiple-Data): обрабатываем 8 интов за раз.
  Можно жёстко эксплуатировать: https://habr.com/ru/company/ruvds/blog/551060/
* Учесть кэши и обращения к памяти.
* Несколько физических ядер процессора.
* Несколько процессоров.
* Несколько компьютеров.

Потоки можно применять не только для ускорения.
Можно для замедления, зато с упрощением кода (блокирующий ввод-вывод) или многозадачностью (много окон).

Параллельные алгоритмы:

* Параллелятся почти как угодно:
  ```
  int sum = 0;
  for (int x : values) sum += x;
  ```
* Не параллелятся вообще:
  ```
  int steps = 0;
  for (int x = 1; x != 0; x = f(x)) steps++;
  ```
* Параллелятся, но не очень: компиляция.
* Надо придумывать что-то хитрое, чтобы запустить на тысячах ядер:
  * Иногда выгоднее распараллелить перебор, потому что умный алгоритм не параллелится
  * Merge sort. https://compscicenter.ru/courses/video_cards_computation/2020-autumn/classes/
