import tushare as ts
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
pro = ts.pro_api('f5ac16fe59a0bbc684d5623f539e85345e6789f40d8ad4b68d5b4574')
ts.pro_api('f5ac16fe59a0bbc684d5623f539e85345e6789f40d8ad4b68d5b4574')
df = pro.daily(ts_code='000001.SZ', start_date='20100701', end_date='20180718')
df.to_csv('d:\\1.csv')
print(df.head(100))
sz=df.sort_index(axis=0,ascending=True)
sz_return=sz[['pct_chg']]
train=sz_return[0:400]
test=sz_return[401:]
plt.figure(figsize=(10,5))
train['pct_chg'].plot()
plt.legend(loc='best')
plt.show()