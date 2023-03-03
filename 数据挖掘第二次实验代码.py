import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
import random as ra
rd = pd.read_excel("height_weight.xlsx")
rd.head()
rd.info()
rd.describe()

nd=ra.sample(range(20, 30), 9)
rd.insert(2, '年龄', nd, allow_duplicates=False)
# rd["时间"]=np.linsapce(1,10,10)
rd["时间"] = np.linspace(1,10,9)
print(rd)
rd= rd.drop('时间',axis=1)
print(rd)
rd= rd.drop(columns='年龄')
print(rd)
rd.loc[10] = [155,53,30]
print(rd)
rd.loc[10] = [160,53,30]
print(rd)

rd=rd.drop(index=[10])
print(rd)

print(rd.info())
print(rd.describe())
print(rd.isnull())
print(np.any(rd.isnull()))

z= rd.dropna()
z.head()
z.isin("nul")
y=z.replace(to_replace="nul", value=np.nan)
print(y)
y.dropna()

ra=pd.read_excel("height_weight2.xlsx")
rd.head(8)
a=rd.fillna(100)
print(a)
b=rd.fillna(method="ffill",axis=0)
print(b)
c=rd.fillna(method="bfill",axis=1)
print(c)
d=rd.fillna(rd.mean())
print(d)






import pandas as pd
import numpy as np

rd=pd.read_excel('height_weight_outlier.xlsx')
rd.head()
a=np.array(rd)
print(a)

def three_sigma(x):
    mu, std=np.mean(x, axis=0), np.std(x,axis=0)
    lower,upper=mu-2*std, mu+2*std
    return lower, upper

lower, upper = three_sigma(a)
lower, upper
index=[]
for i in range(0, len(a)):
    if np.array(a[i]<lower).any() | np.array(a[i]>upper).any():
        index.append(i)
index
import matplotlib.pyplot as plt
s1=np.delete(range(0, len(a)), index)
plt.scatter(a[s1,0], a[s1,1], color='g', label="normal")
plt.scatter(a[index,0], a[index, 1], color='r', label='outliers')
plt.xlabel('身高')
plt.ylabel('体重')
plt.legend()
plt.show()


# 最大最小规范化
ahat=(a-np.min(a, axis=0))/(np.max(a, axis=0)-np.min(a, axis=0))
print(ahat)
azscore=(a-np.mean(a,axis=0))/np.std(a,axis=0)
print(azscore)
import matplotlib.pyplot as plt
plt.scatter(a[:,0], a[:1], color='b')

