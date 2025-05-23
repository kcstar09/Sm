import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler



iris=datasets.load_iris()
x=iris.data
y=iris.target
scaler=StandardScaler()
x_scaled=scaler.fit_transform(x)
pca=PCA(n_components=2)
x_pca=pca.fit_transform(x_scaled)
plt.figure(figsize=(8, 6))
colors = ['purple', 'cyan', 'hotpink']
labels=iris.target_names
for i in range(len(colors)):
    plt.scatter( x_pca[y == i, 0],x_pca[y == i, 1],
    color=colors[i], label=labels[i] )
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.title('PCA on Iris Dataset')
plt.legend()
plt.grid()
plt.show()
print("Explained variance ratio:",pca.explained_variance_ratio_)
