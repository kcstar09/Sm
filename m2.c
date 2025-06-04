import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_california_housing
from pandas.plotting import scatter_matrix


cal_housing = fetch_california_housing()
df = pd.DataFrame(cal_housing.data, columns=cal_housing.feature_names)
df['MedHouseVal'] = cal_housing.target  


corr_matrix = df.corr()

print("Correlation Matrix:")
print(corr_matrix)


plt.figure(figsize=(8, 6))
plt.imshow(corr_matrix, cmap='coolwarm', interpolation='nearest', aspect='auto')
plt.colorbar(label='Correlation Coefficient')
plt.xticks(range(len(corr_matrix.columns)), corr_matrix.columns, rotation=90)
plt.yticks(range(len(corr_matrix.columns)), corr_matrix.columns)
plt.title("Correlation Matrix Heatmap")
plt.tight_layout()
plt.show()
