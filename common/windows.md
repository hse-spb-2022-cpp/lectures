# Windows
Подойдёт как Windows 10, так и Windows 11.

Вам в любом случае потребуется поставить и настроить себе Ubuntu в виртуальной машине или WSL (по умолчанию используется версия 2, это ок).
В случае WSL вы можете либо работать целиком в консоли, либо [настроить виндовый CLion для работы с WSL 2](https://www.jetbrains.com/help/clion/how-to-use-wsl-development-environment-in-product.html).

Но вы также можете установить себе компиляторы, работающие целиком под Windows.
Принципиально вы можете себе поставить либо экосистему Microsoft Visual Studio (компиляторы Visual C++ и Clang), либо экосистему msys2 (компиляторы GCC и Clang, плюс куча инструментов как под Linux).
Будьте осторожны: есть много других версий GCC и Clang (в том числе в комплекте с Code::Blocks, Qt Creator, CLion), их может быть сложно поставить, настроить или запустить.

## Компиляторы, среда разработки инструменты LLVM
### Вариант 1: Установка Visual Studio
Занимает уйму места, долго ставится и требует подключение к интернету при установке, зато сразу идёт со средой разработки и отладчиком.

Используется компилятор Visual C++ и стандартная библиотека Microsoft STL.

1. Скачайте и запустите установщик [с официального сайта](https://visualstudio.microsoft.com/ru/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false).
2. При установке выберите:
    * Workload ("Рабочая нагрузка") "Desktop development with C++" ("Разработка классических приложений на C++").
    * Внутри этой Workload оставьте только компоненты:
        * "MSVC v143 ... x86/64 build tools" ("MSVC версии 142 ... x86/64 Build Tools (последняя версия)")
        * "Windows 10 SDK" ("Пакет SDK для Windows 10 ") или "Windows 11 SDK" ("Пакет SDK для Windows 11") в зависимости от вашей версии Windows
        * "C++ Address Sanitizer"
        * При желании добавьте "C++ profiling tools" ("Средства профилирования C++"), может помочь при поиске тормозов в программе
        * При желании добавьте "IntelliCode", это какие-то экспериментальные подсказки при наборе кода
    * На вкладке "Language packs" ("Языковые пакеты") добавьте английский язык, а вот русский лучше удалить.
3. Поставьте компилятор Clang и инструменты из проекта LLVM [отсюда](https://github.com/llvm/llvm-project/releases/download/llvmorg-14.0.6/LLVM-14.0.6-win64.exe).
   Обратите внимание, что эта сборка использует стандартную библиотеку Visual C++ и не будет работать без установленной Visual Studio.
   Но запускать этот Clang умеют и Visual Studio, и в CLion.

С компилятором Visual Studio проще работать из Visual Studio, но можно и настроить для этого CLion.
При большом желании можно запускать компилятор руками из командной строки: откройте "x64 Native Tools Command Prompt for VS 2022" из меню "Пуск", компилятор станет называться `cl`.

### Вариант 2: установка экосистемы msys2
Есть много разных сборок GCC, я рекомендую ставить из проекта msys2. Так вы бесплатно получите кучу библиотек для C++ и полезных инструментов из Linux.

По умолчанию будет использоваться компилятор GCC и стандартная библиотека GNU libstdc++.

1. Установите msys2 [по инструкции](https://www.msys2.org/).
   Если Microsoft Defender будет ругаться, ничего страшного.
2. Из консоли msys2 запустите команду для установки компилятора, системы Make и инструментов LLVM:
   ```bash
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-clang mingw-w64-x86_64-clang-tools-extra
   ```
3. При желании установите больше компиляторов и стандартных библиотек (Visual Studio не требуется):
   ```bash
   pacman -S mingw-w64-x86_64-clang
   pacman -S mingw-w64-x86_64-libc++
   ```

Проще всего использовать либо редактор кода, либо установить CLion.
Осторожно: CLion идёт в комплекте со своей версией gcc, надо использовать не её.

## Установка Ubuntu
Требуется Windows 10 или Windows 11.
После этого [установите Ubuntu 22.04.1 из Microsoft Store](https://www.microsoft.com/p/ubuntu/9PN20MSR04DW) и запустите.
Важно: **не** используйте команду `wsl --install`, она [пока не умеет устанавливать Ubuntu 22.04](https://github.com/microsoft/WSL/issues/8402).

После установки запустите WSL и настройте как будто это обычная Ubuntu.
Обязательно проверьте версию.

## Прочие инструменты
1. Cppcheck 2.7 ставится [по ссылкам с официального сайта](https://github.com/danmar/cppcheck/releases/download/2.7/cppcheck-2.7-x64-Setup.msi).
2. Консольный клиент git ставится [с официального сайта](https://git-scm.com/download/win), в комплекте также включён git bash (он подойдёт).
   В качестве редактора рекомендуется оставить блокнот или Nano. Не выбирайте Vim, если не знаете, что это.
3. Интерпретатор языка Python (для запуска некоторых автоматических тестов).
4. Система сборки CMake ставится [с официального сайта](https://cmake.org/download).
   Для Visual Studio система make не нужна, а для msys2 она уже была поставлена по инструкции выше (надо выбирать правильный генератор ключом `-G "MSYS Makefiles"`).

### Дополнительно: установка Intel C++ Compiler Classic
TODO: ставится как часть [Intel openAPI Base Toolkit](https://www.intel.com/content/www/us/en/developer/tools/oneapi/base-toolkit-download.html)
Если не грузится - это санкции, попробуйте через VPN.

### Дополнительно: установка Boost
TODO

### Дополнительно: установка Netcat
TODO

### После установки
Если какой-то инструмент не запускается из консоли, добавьте его [в переменную среды `PATH`](https://nicothin.pro/page/windows-path).
Например, для msys2 наверняка будет нужна папка вроде `C:\msys239\mingw64\bin\` — именно в ней лежит `g++.exe` (проверьте!).
Также может потребоваться `C:\msys239\usr\bin`, в ней может лежать `nc.exe`.
После этого перезапустите консоль/CLion, чтобы они прочитали новую версию `PATH`.

Осторожно: [не пишите `main` в PowerShell](https://stackoverflow.com/questions/46460771/why-does-running-main-in-powershell-open-my-mouse-properties).
