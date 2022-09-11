# Ubuntu
Экспериментальная альтернатива – установить всё [через Docker](https://github.com/hse-spb-2022-cpp/hse-cpp-docker) и запускать компиляторы внутри контейнера.

Все действия ниже выполняются из консоли:

1. Проверьте, что у вас действительно Ubuntu 22.04: команда `cat /etc/lsb-release` должна вывести <code>Ubuntu 22.04.1 LTS</code>, цифра 1 может быть другой.
2. Обновите всю систему до последней версии: `sudo apt update && sudo apt upgrade`. Теперь версия должны быть `Ubuntu 22.04.1 LTS`.
3. Дальше установите необходимый набор пакетов (вы можете склеить эти команды в одну большую `sudo apt instal a b c d e ...`, чтобы сразу скачать все пакеты):
    ```bash
    sudo apt install g++-12  # Компилятор GCC 12 со стандартной библиотекой libstdc++
    sudo apt install valgrind  # Инструмент Valgrind
    # Среды разработки ставятся по-разному. Например, CLion можно поставить [https://www.jetbrains.com/ru-ru/clion/ с официального сайта]
    sudo apt install clang-format-14 clang-tidy-14  # Инструменты от LLVM
    sudo apt install cppcheck  # Cppcheck
    sudo apt install git  # Консольный клиент для git; bash уже стоит
    # Python уже стоит (команда python3)
    sudo apt install cmake make  # CMake и Make
    ```
4. При желании установите больше компиляторов и стандартных библиотек:

    ```bash
    sudo apt install clang-14  # Компилятор Clang 14
    sudo apt install libc++-14-dev libc++abi-14-dev  # Стандартная библиотека libc++
    ```
5. При желании также установите компилятор Intel C++ Compiler (не путать с Intel DPC++ Compiler).
   Он ставится как часть Intel oneAPI Base Toolkit:
   1. Добавьте новый репозиторий [вот так](https://www.intel.com/content/www/us/en/develop/documentation/installation-guide-for-intel-oneapi-toolkits-linux/top/installation/install-using-package-managers/apt.html) ("Pre-installation Steps").
      Если не грузится - это санкции, попробуйте через VPN.
   2. Установите командой `sudo apt update && sudo apt install intel-oneapi-compiler-dpcpp-cpp-and-cpp-classic`
   3. Для запуска настройте окружение в текущей консоли командой `. /opt/intel/oneapi/setvars.sh` и запускайте компилятор командой `icc`.
6. Для конкретных домашних заданий установите:
    ```
    sudo apt install libboost-all-dev  # Boost, скомпилированный для работы с libstdc++
    sudo apt install netcat-openbsd  # Утилита netcat, вызывается командой `nc`
    ```
7. При желании можете установите виртуальную машину, а потом установить внутрь неё Windows. Рекомендуется VirtualBox: <code>sudo apt install virtualbox</code>.
   Ссылка на образ Windows есть в общей инструкции, как и инструкции по её настройке.

При работе из консоли всегда используйте команды с суффиксом версии: `g++-12` вместо `g++`, `clang++-14`, `clang-format-14`, `clang-tidy-12`.
Пакеты и команды без суффикса, вроде `g++`, могут относиться к старым версиям.

В частности, вам нужно корректно настроить вашу среду разработки ([настройка Compilers в Toolchain в CLion](https://www.jetbrains.com/help/clion/how-to-switch-compilers-in-clion.html#custom-targets-toolchain))
и консольный CMake (при помощи параметра вроде `-DCMAKE_CXX_COMPILER=g++-12`).

# Другие дистрибутивы Linux
Вы можете либо поставить виртуальную машину с Ubuntu, либо сделать Docker-контейнер на основе образа Ubuntu 22.04.
