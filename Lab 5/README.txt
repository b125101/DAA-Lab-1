DAA LAB-5 - COMPLETE C PROGRAMS
================================

1. 01_median_without_sorting.c
   Finds median using Quickselect without sorting the complete list.
   Average: O(N), Worst: O(N^2).

2. 02_kth_smallest_without_sorting.c
   Finds K-th smallest element using Quickselect without sorting.
   Average: O(N), Worst: O(N^2).

3. 03_quick_sort_file.c
   Generates N random integers, stores them in quick_input.txt,
   sorts them using Quick Sort, and writes quick_sorted.txt.
   Average: O(N log N), Worst: O(N^2).

4. 04_heap_sort_file.c
   Generates N random integers, stores them in heap_input.txt,
   sorts them using Heap Sort, and writes heap_sorted.txt.
   Best/Average/Worst: O(N log N).

COMPILATION ON WINDOWS (MinGW GCC)
-----------------------------------
gcc 01_median_without_sorting.c -o 01_median_without_sorting.exe
gcc 02_kth_smallest_without_sorting.c -o 02_kth_smallest_without_sorting.exe
gcc 03_quick_sort_file.c -o 03_quick_sort_file.exe
gcc 04_heap_sort_file.c -o 04_heap_sort_file.exe

COMPILATION ON LINUX
--------------------
gcc 01_median_without_sorting.c -o 01_median_without_sorting
gcc 02_kth_smallest_without_sorting.c -o 02_kth_smallest_without_sorting
gcc 03_quick_sort_file.c -o 03_quick_sort_file
gcc 04_heap_sort_file.c -o 04_heap_sort_file

Note: The current execution environment has GCC for Linux but does not
have a Windows MinGW cross-compiler. Therefore the included binaries
are Linux executables. The C source files are ready to compile into
Windows .exe files using MinGW GCC with the commands above.
