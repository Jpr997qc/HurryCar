# HurryCar
## 材料列表
1.Node32s 1個 2.1:48的TT馬達 4個 3.MP1584降壓模塊 1個 5.HC-SR04超音波 1個
6.YS-IRTM紅外邊解碼器 1個 7.LCD1602A 1個

# 架構說明
把大部分功能都拆分成獨立文件跟函式了，並且函式盡量寫成可由輸入的變數來配合不同情況了。
Module.h的功能為宣告所有變數並前置宣告所有函式。
Module.h完成後只要在入口跟模組內包含Module.h就可以調用任何有包含Module.h的ino和cpp檔內的變數跟函式了(一個專案只能有一個ino)。

# 目前功能
1.FreeRTOS演示
2.WiFi自動連接並在未連接時轉為AP模式
3.電池剩餘電量檢測功能
4.LCD1602A顯示範例