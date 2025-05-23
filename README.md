import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_california_housing

from pandas.plotting import scatter_matrix

cal_housing= fetch_california_housing()
df =pd.DataFrame(cal_housing.data,columns=cal_housing.feature_names)

df['medHouseVal']=cal_housing.target

corr_matrix = df.corr()

print("correlation matrix:")
print(corr_matrix)
plt.figure(figsize=(8,6))
plt.imshow(corr_matrix, cmap='coolwarm',interpolation='nearest', aspect='auto')
plt.colorbar(label='correlation coefficient')


plt.xticks(range(len(corr_matrix.columns)),corr_matrix.columns,rotation=90)
plt.yticks(range(len(corr_matrix.columns)),corr_matrix.columns)
plt.title("correlation matrix Heatmap")
plt.tight_layout()
plt.show()
plt.figure(figuresize=(10,10))
scatter_matrix(df,alpha=0.2,figsize=(12,12))
plt.subtitle("pair plot of california housing feature")
plt.show()
