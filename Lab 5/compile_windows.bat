@echo off
echo Compiling DAA LAB-5 programs with MinGW GCC...
gcc -std=c11 -O2 -Wall -Wextra 01_median_without_sorting.c -o 01_median_without_sorting.exe
gcc -std=c11 -O2 -Wall -Wextra 02_kth_smallest_without_sorting.c -o 02_kth_smallest_without_sorting.exe
gcc -std=c11 -O2 -Wall -Wextra 03_quick_sort_file.c -o 03_quick_sort_file.exe
gcc -std=c11 -O2 -Wall -Wextra 04_heap_sort_file.c -o 04_heap_sort_file.exe
if errorlevel 1 (
  echo Compilation failed. Install MinGW-w64 GCC and make sure gcc is in PATH.
  pause
  exit /b 1
)
echo.
echo Compilation successful. Four .exe files have been created.
pause
