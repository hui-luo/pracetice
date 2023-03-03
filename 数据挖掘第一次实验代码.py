n = 0
for i in range(7):
    result = input("今天你学习了吗？")
    if result == "是的":
        n+=1
    elif result == "一般":
        continue
    else:
        break
print(n)
    
import pandas as pd
import numpy as np

hw=pd.read_excel("height_weight.xlsx")
hw.head()
hwt = np.array(hw)
print(hwt)

index = np.argsort(hwt[:,0])
print(index)
hwts=hwt[index]
print(hwts)
print("身高和体重最大为",np.max(hwt))
print("身高和体重最小为",np.min(hwt,axis=0))
print("身高和体重均值为",np.mean(hwt,axis=0))
print("身高和体重标准差为",np.std(hwt,axis=0))
print("身高和体重方差为",np.var(hwt,axis=0))
