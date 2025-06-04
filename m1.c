import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_california_housing


cal_housing = fetch_california_housing()
df = pd.DataFrame(cal_housing.data, columns=cal_housing.feature_names)
df['MedHouseVal'] = cal_housing.target  

print(df.head())
print("\nSummary statistics:")
print(df.describe())


for col in df.columns:
    plt.figure()
    plt.hist(df[col])  
    plt.title(f"Histogram of {col}")
    plt.xlabel(col)
    plt.ylabel("Frequency")
    plt.show()


for col in df.columns:
    plt.figure()
    plt.boxplot(df[col], vert=True)  
    plt.title(f"Box Plot of {col}")
    plt.ylabel(col)
    plt.show()
