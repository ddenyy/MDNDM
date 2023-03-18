# CMakeList.txt: проект CMake для CMakeProject1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("MDMDN")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeProject1 "main.cpp" "main.h" "Board/board.cpp"  "cell/Cell.cpp" "Artifact/Artifact.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
