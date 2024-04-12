#print(10);
from datetime import *#非常推荐学会使用datetime库
dt1=datetime(1901,1,1)
dt2=datetime(2000,12,31)
print(dt1.weekday())
td=dt2-dt1
#print(td.days//7)#我滴妈直接无敌了啊，运行相当快
print(12/7)#/是直接除，结果是小数；//是整除，结果是整数。