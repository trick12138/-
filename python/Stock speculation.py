#股票价格预测程序
import tushare as ts
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
#取得数据
pro = ts.pro_api('f5ac16fe59a0bbc684d5623f539e85345e6789f40d8ad4b68d5b4574')
df = pro.daily(ts_code='000001.SZ', start_date='20100701', end_date='20180718')
df.to_csv('E:\\c-learning\\python\\1.csv')
print(df.head(10))
#可以看到转去了上证指数的各类价格   qQ 数据以及最后turnover的换手率。但是有一个问题就是数据的date的降序的，即日起从2018年3月往2017年1月排列的，需要排序。
sz=df.sort_index(axis=0, ascending=True) #对index进行升序排列
sz_return=sz[['pct_chg']] #选取涨跌幅数据
train=sz_return[0:400] #划分训练集
test=sz_return[401:]   #测试集
#对训练集与测试集分别做趋势图
plt.figure(figsize=(10,5))
train['pct_chg'].plot()
plt.legend(loc='best')
plt.show()
plt.figure(figsize=(10,5))
test['pct_chg'].plot(c='r')
plt.legend(loc='best')
plt.show()
#蓝色为训练集序列波动图，红色为测试集序列波动图。对上证指数收益率做初步时间序列分析,直接用最后一个值作为测试集的预测值
#蓝色为训练集序列波动图，红色为测试集序列波动图。对上证指数收益率做初步时间序列分析,直接用最后一个值作为测试集的预测值
train.index =pd.to_datetime(train.index)#转换时间字符格式以方便作图
test.index =pd.to_datetime(test.index)
dd= np.asarray(train.pct_chg)  #z转换成向量，以便加入y_hat中
y_hat = test.copy()
y_hat['naive'] = dd[len(dd)-1]
plt.figure(figsize=(12,8))
plt.plot(train.index, train['pct_chg'], label='Train')
plt.plot(test.index,test['pct_chg'], label='Test')
plt.plot(y_hat.index,y_hat['naive'], label='Naive Forecast')
plt.legend(loc='best')
plt.title("Naive Forecast")
plt.show()
#计算RMSE
from sklearn.metrics import mean_squared_error
from math import sqrt
rms = sqrt(mean_squared_error(test.pct_chg, y_hat.naive))
print(rms)

#蓝色为训练集序列，绿色为测试集序列，红色为预测值序列，得到RMSE为2.7924。（2）直接用训练集平均值作为测试集的预测值得到RMSE为2.4192。
#Simple Average
y_hat_avg = test.copy() #copy test列表
y_hat_avg['avg_forecast'] = train['pct_chg'].mean() #求平均值
plt.figure(figsize=(12,8))
plt.plot(train['pct_chg'], label='Train')
plt.plot(test['pct_chg'], label='Test')
plt.plot(y_hat_avg['avg_forecast'], label='Average Forecast')
plt.legend(loc='best')
plt.show()
rms = sqrt(mean_squared_error(test.pct_chg, y_hat_avg.avg_forecast))
print(rms)
#（3）直接用移动平均法最后一个值作为测试集的预测值得到RMSE为2.3849。可以看到，最后移动平均法的均方误差最低，预测效果最好。
#Moving Average
y_hat_avg = test.copy()
y_hat_avg['moving_avg_forecast'] = train['pct_chg'].rolling(30).mean().iloc[-1]
#30期的移动平均，最后一个数作为test的预测值
plt.figure(figsize=(12,8))
plt.plot(train['pct_chg'], label='Train')
plt.plot(test['pct_chg'], label='Test')
plt.plot(y_hat_avg['moving_avg_forecast'], label='Moving Average Forecast')
plt.legend(loc='best')
plt.show()
rms = sqrt(mean_squared_error(test.pct_chg, y_hat_avg.moving_avg_forecast))
print(rms)

#蓝色为训练集序列，绿色为测试集序列，红色为预测值序列，得到RMSE为2.7924。（2）直接用训练集平均值作为测试集的预测值得到RMSE为2.4192。
#Simple Average
y_hat_avg = test.copy() #copy test列表
y_hat_avg['avg_forecast'] = train['pct_chg'].mean() #求平均值
plt.figure(figsize=(12,8))
plt.plot(train['pct_chg'], label='Train')
plt.plot(test['pct_chg'], label='Test')
plt.plot(y_hat_avg['avg_forecast'], label='Average Forecast')
plt.legend(loc='best')
plt.show()
rms = sqrt(mean_squared_error(test.pct_chg, y_hat_avg.avg_forecast))
print(rms)
#（3）直接用移动平均法最后一个值作为测试集的预测值得到RMSE为2.3849。可以看到，最后移动平均法的均方误差最低，预测效果最好。
#Moving Average
y_hat_avg = test.copy()
y_hat_avg['moving_avg_forecast'] = train['pct_chg'].rolling(30).mean().iloc[-1]
#30期的移动平均，最后一个数作为test的预测值
plt.figure(figsize=(12,8))
plt.plot(train['pct_chg'], label='Train')
plt.plot(test['pct_chg'], label='Test')
plt.plot(y_hat_avg['moving_avg_forecast'], label='Moving Average Forecast')
plt.legend(loc='best')
plt.show()
rms = sqrt(mean_squared_error(test.pct_chg, y_hat_avg.moving_avg_forecast))
print(rms)