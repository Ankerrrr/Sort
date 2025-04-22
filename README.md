# sort 資料結構作業

測試各個 SORT 的執行時間，包含以下喔

> bouble, heap, insertion, merge, quick, selection

## 使用方式

執行 RunSort cpp 檔案

## 說明

主程式：RunCode

    包含六種排序法的 .cpp 檔案（例如：BubbleSort.cpp、QuickSort.cpp 等）。

    負責整體流程的執行與排序方法的呼叫。

    執行後會在主程式目錄下產生輸出檔案 out.txt。

資料來源：resource/dat.txt

    存放待排序的亂數資料。

    由 generateTestDat 自動產生亂數並寫入 dat.txt。

資料讀取：ReadFile.cpp

    負責讀取 dat.txt 中的資料。

    將亂數資料讀入記憶體，提供給各種排序方法使用。

> [!NOTE]
>
> - 程式模組化

## 程式架構

<p>
RunSort.cpp<br>
├── include BubbleSort.cpp<br>
├── include HeapSort.cpp<br>
├── include InsertionSort.cpp<br>
├── include MergeSort.cpp<br>
├── include QuickSort.cpp<br>
├── include SelectionSort.cpp<br>
├── include generateTestDat.cpp<br>
└── include sort/STL/STL_Sort.cpp
</p>

## 可調整參數

```
testCase 1000
testRange 10000
define loop 50
```

- testCase 用於修改 dat 要產生多少數組
- testRange 用於修改 dat 要產生的數值從 1 到多少
- loop 調整要測試幾次

## 輸出

這是一個 `testCase: 1000` , `testRange: 10000` , `loop: 50` 的範例

如下表即顯示各個 SORT 在 LOOP 次的 avg 及 Max (單位: ms)

以及在程式內 Swap 交換的次數 (SwapCountHiggest)最高

最下方則是使用 STL SORT 的排序

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 1000, testRange = 10000, Loop = 50
Heap Sort:      Avg =1.27098, Max = 3.243, SwapCountHiggest = 9090
Bubble Sort:    Avg =6.85076, Max = 14.831, SwapCountHiggest = 248536
Insertion Sort: Avg =2.69018, Max = 4.87, SwapCountHiggest = 248536
Merge Sort:     Avg =2.01478, Max = 3.059, SwapCountHiggest = 9976
Quick Sort:     Avg =1.23622, Max = 2.283, SwapCountHiggest = 6438
Selection Sort: Avg =4.49724, Max = 6.979, SwapCountHiggest = 238206
STL Sort:       Avg =1.24468, Max = 2.545
```

## 分析

### 測試環境

測試平台：

- CPU: Intel Core i7-12650H
- RAM: 16 GB
- Compiler: g++ 13.2.0
- OS: Windows 11

---

測試數據

`testCase: 10` , `testRange: 5000` , `loop: 50`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 10, testRange = 5000, Loop = 50
Heap Sort:      Avg =0.5563, Max = 6.042, SwapCountHiggest = 25
Bubble Sort:    Avg =0.3986, Max = 0.758, SwapCountHiggest = 23
Insertion Sort: Avg =0.43394, Max = 0.954, SwapCountHiggest = 23
Merge Sort:     Avg =0.42774, Max = 0.768, SwapCountHiggest = 34
Quick Sort:     Avg =0.39844, Max = 0.538, SwapCountHiggest = 18
Selection Sort: Avg =0.41796, Max = 0.657, SwapCountHiggest = 23
STL Sort:       Avg =0.41266, Max = 0.718
```

`testCase: 1000` , `testRange: 5000` , `loop: 50`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 1000, testRange = 5000, Loop = 50
Heap Sort:      Avg =1.24846, Max = 2.247, SwapCountHiggest = 9134
Bubble Sort:    Avg =6.74482, Max = 9.45, SwapCountHiggest = 261327
Insertion Sort: Avg =2.8325, Max = 7.007, SwapCountHiggest = 261327
Merge Sort:     Avg =1.97966, Max = 3.011, SwapCountHiggest = 9976
Quick Sort:     Avg =1.18906, Max = 1.594, SwapCountHiggest = 6489
Selection Sort: Avg =4.45702, Max = 6.533, SwapCountHiggest = 253188
STL Sort:       Avg =1.21592, Max = 1.97
```

`testCase: 10000` , `testRange: 5000` , `loop: 50`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 10000, testRange = 5000, Loop = 50
Heap Sort:      Avg =8.93592, Max = 16.62, SwapCountHiggest = 124308
Bubble Sort:    Avg =597.013, Max = 613.529, SwapCountHiggest = 25379343
Insertion Sort: Avg =153.084, Max = 174.375, SwapCountHiggest = 25379343
Merge Sort:     Avg =18.2174, Max = 40.059, SwapCountHiggest = 133616
Quick Sort:     Avg =8.38628, Max = 15.585, SwapCountHiggest = 99076
Selection Sort: Avg =368.23, Max = 386.652, SwapCountHiggest = 18974693
STL Sort:       Avg =8.2887, Max = 14.96
```

### 這邊開始跑太久了所以降低 LOOP 次數

`testCase: 50000` , `testRange: 5000` , `loop: 1`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 50000, testRange = 5000, Loop = 1
Heap Sort:      Avg =85.296, Max = 85.296, SwapCountHiggest = 737622
Bubble Sort:    Avg =14994.1, Max = 14994.1, SwapCountHiggest = 625516856
Insertion Sort: Avg =3708.43, Max = 3708.43, SwapCountHiggest = 625516856
Merge Sort:     Avg =193.477, Max = 193.477, SwapCountHiggest = 784464
Quick Sort:     Avg =72.361, Max = 72.361, SwapCountHiggest = 420997
Selection Sort: Avg =6087.38, Max = 6087.38, SwapCountHiggest = 209299692
STL Sort:       Avg =71.148, Max = 71.148
```

`testCase: 100000` , `testRange: 5000` , `loop: 1`

```cpp
---- Sorting Time Summary (ms) ----
Info : testCase = 100000, testRange = 5000, Loop = 1
Heap Sort:      Avg =175.199, Max = 175.199, SwapCountHiggest = 1574760
Bubble Sort:    Avg =58675.4, Max = 58675.4, SwapCountHiggest = 18446744071918634865
Insertion Sort: Avg =15218.5, Max = 15218.5, SwapCountHiggest = 18446744071918634865
Merge Sort:     Avg =393.943, Max = 393.943, SwapCountHiggest = 1668928
Quick Sort:     Avg =150.664, Max = 150.664, SwapCountHiggest = 1028860
Selection Sort: Avg =18950.3, Max = 18950.3, SwapCountHiggest = 473874715
STL Sort:       Avg =149.034, Max = 149.034
```

## 速度排序

測資夠大的話

quick 略優 Heap 優於 Merge 大優於 Inesrtion 優於 selection 大大優於 Bubble

| 排序方法       | 平均時間複雜度 |
| -------------- | -------------- |
| Quick Sort     | O(n log n)     |
| Heap Sort      | O(n log n)     |
| Merge Sort     | O(n log n)     |
| Insertion Sort | O(n²)          |
| Selection Sort | O(n²)          |
| Bubble Sort    | O(n²)          |

## 心得

這個作業很好玩，我們都學到了很多!!
