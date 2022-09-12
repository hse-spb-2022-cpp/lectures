# macOS
Будьте осторожны: обычно на macOS используется Apple Clang (не LLVM Clang), который скрывается за командой `gcc` и ставится вместе с Apple-специфичной средой разработки Xcode
или её консольной версией.
Скорее всего, будет не та версия, что надо. Проверьте, запустив `g++ --version`.

При этом библиотеки для C++ (вроде Boost) надо либо собирать из исходников (долго и нудно), либо поставить уже собранные, но тогда они будут работать только с Apple Clang.
Так что для ежедневной работы рекомендуется именно Apple Clang.

1. Откройте терминал и установите консольный компилятор командой
   ```bash
   xcode-select --install
   ```
2. В качестве виртуальной машины, если у вас процессор Intel, проще всего поставить [Oracle VirtualBox](https://www.virtualbox.org/) и скачать в него [готовый образ с Ubuntu 22.04 от проекта OSboxes](https://www.osboxes.org/ubuntu/). Дальше следуйте шагам по настройке Ubuntu.
   Для процессора M1 Ubuntu можно поставить через [виртуальную машину UTM](https://mac.getutm.app/gallery/ubuntu-20-04), только используйте [Ubuntu 22.04](https://mirror.yandex.ru/ubuntu-cdimage/releases/22.04.1/release/ubuntu-22.04.1-live-server-arm64.iso) вместо Ubuntu 20.04.
   Экспериментальная альтернатива – установить всё [через Docker](https://github.com/hse-spb-2022-cpp/hse-cpp-docker).
3. Установите пакетный менеджер [Homebrew](https://brew.sh/): запустите команду с домашней страницы и внимательно прочитайте, когда оно скажет Run these two commands in your terminal, эти команды необходимо выполнить. 
4. Выполните команды:
   ```bash
   brew update  # Обновление списка доступных пакетов
   brew install llvm@14 cppcheck git cmake make  # Установка инструментов LLVM, cppcheck не той версии, git, cmake, make
   ```
   Интерпретаторы bash и Python уже стоят.
5. Теперь у вас должны появиться команды `cmake` и `cppcheck`.
   Если они не появились — у вас не добавлен в переменную `PATH` путь до папки с программами, поставленными через Homwbrew.
   Вам нужно дописать в файл `$HOME/.bash_profile` (для Bash) или `$HOME/.zprofile` (для Zsh) строчки, которые выводит команда `brew shellenv`.
   После этого переоткройте консоль/CLion, чтобы они увидели изменения.
6. Чтобы появились команды `clang++`, `g++` (которые конфликтуют со стандартными командами Xcode) и команды вроде `clang-format` (они связаны с первыми),
   надо добавить в этот же файл в конце строчку `export PATH="$(brew --prefix llvm)/bin":$PATH`.
   После этого переоткройте консоль/CLion, чтобы они увидели изменения. 
7. Если хотите установить Windows на процессор Intel, то **TODO**.
   На процессоре M1 можно поставить [виртуальную машину UTM и Windows for ARM](https://mac.getutm.app/gallery/windows-10), после чего поставить в неё Visual Studio по инструкции для Windows.
   Но это будет дико тормозить, так как Visual Studio есть только для x86, а на ARM будет эмуляция.
8. Для конкретных домашних заданий установите:
   ```bash
   brew install boost # Установка Boost для Apple Clang. С gcc/llvm clang из Homebrew будет странно не компилироваться и/или странно падать!
                      # Библиотека Boost может оказаться более новой версии, чем требуется.
   # Утилита Netcat уже стоит по умолчанию и запускается командой nc.
   ```

По умолчанию будет использоваться компилятор Apple Clang и стандартная библиотека Apple libc++.
Не libstdc++, как на Linux, и даже не совсем LLVM libc++.
Из-за этого и говорят, что "на маках компилируется, а под другими ОС нет", виновата другая стандартная библиотека.

## Возможные проблемы
* [Ошибка при установке Homebrew: `"Failed during: git fetch origin master:refs/remotes/origin/master -n --depth=1"`](https://stackoverflow.com/questions/39836190/homebrew-install-failed-during-git-fetch-origin-masterrefs-remotes-origin-mas)
    * Может помочь команда `git config --global user.email <здесь-ваш-email-с-GitHub>`, вроде `git config --global user.email noreply@example.com`.
      На самом деле можно написать любой email (даже несуществующий), но тогда на GitHub могут быть трудности, если забудете поменять.
