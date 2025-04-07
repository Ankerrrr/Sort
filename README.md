# sort 資料結構作業

測試各個 SORT 的執行時間，包含以下

> bouble, heap, insertion, merge, quick, selection

## 使用方式

執行 RunSort cpp 檔案

## 說明

RunCode 是一個主程式，他 include 了上列六種 Sort 的 cpp，並且執行後會在他的下方產生 `out.txt`，dat 則是 resource 資料夾裡面的 `dat.txt` 存放，會由**generateTestDat** 產生亂數至 dat.txt 供排序使用，再由`ReadFile` cpp 讀取 dat.txt 的亂數檔案到各個 sort method

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

```
---- Sorting Time Summary (ms) ----
Info : testCase = 1000, testRange = 10000, Loop = 50
Heap Sort: Avg = 1.24406, Max = 2.221
Bubble Sort: Avg = 6.48142, Max = 12.01
Insertion Sort: Avg = 2.6499, Max = 4.414
Merge Sort: Avg = 2.06748, Max = 3.289
Quick Sort: Avg = 1.2225, Max = 2.163
Selection Sort: Avg = 4.24264, Max = 5.878
```

## 分析

`testCase: 10` , `testRange: 10000` , `loop: 50`

```
---- Sorting Time Summary (ms) ----
Info : testCase = 10, testRange = 10000, Loop = 50
Heap Sort: Avg = 0.45564, Max = 0.744
Bubble Sort: Avg = 0.44216, Max = 0.912
Insertion Sort: Avg = 0.46874, Max = 1.028
Merge Sort: Avg = 0.55824, Max = 3.487
Quick Sort: Avg = 0.44638, Max = 0.75
Selection Sort: Avg = 0.4739, Max = 1.339
```

`testCase: 1000` , `testRange: 10000` , `loop: 50`

```
---- Sorting Time Summary (ms) ----
Info : testCase = 1000, testRange = 10000, Loop = 50
Heap Sort: Avg = 1.32066, Max = 2.036
Bubble Sort: Avg = 6.5614, Max = 8.738
Insertion Sort: Avg = 2.788, Max = 3.78
Merge Sort: Avg = 2.15274, Max = 3.652
Quick Sort: Avg = 1.25928, Max = 1.776
Selection Sort: Avg = 4.502, Max = 5.983
```

`testCase: 10000` , `testRange: 10000` , `loop: 50`

```
---- Sorting Time Summary (ms) ----
Info : testCase = 10000, testRange = 10000, Loop = 50
Heap Sort: Avg = 9.66864, Max = 21.304
Bubble Sort: Avg = 567.151, Max = 596.348
Insertion Sort: Avg = 154.494, Max = 201.926
Merge Sort: Avg = 18.2565, Max = 42.425
Quick Sort: Avg = 8.65134, Max = 21.692
Selection Sort: Avg = 358.903, Max = 375.06
```

`testCase: 100000` , `testRange: 10000` , `loop: 1`(跑超慢所以降低測試數)

```
---- Sorting Time Summary (ms) ----
Info : testCase = 100000, testRange = 10000, Loop = 1
Heap Sort: Avg = 178.919, Max = 178.919
Bubble Sort: Avg = 59537.8, Max = 59537.8
Insertion Sort: Avg = 14888.5, Max = 14888.5
Merge Sort: Avg = 420.454, Max = 420.454
Quick Sort: Avg = 162.761, Max = 162.761
Selection Sort: Avg = 18260.9, Max = 18260.9
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
