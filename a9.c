import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_olivetti_faces
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

faces = fetch_olivetti_faces()
X = faces.data 
y = faces.target 

X_train, X_test, y_train, y_test= train_test_split(X, y, test_size=0.2, random_state=42)

gnb= GaussianNB()
gnb.fit(X_train, y_train)

y_pred= gnb.predict(X_test)

accuracy = accuracy_score(y_test, y_pred)



print(f"Accuracy: {accuracy * 100:.2f}%")
fig, axes = plt.subplots(2, 5, figsize=(10, 5))
axes = axes.flatten()
for i, ax in enumerate(axes):
    ax.imshow(X_test[i].reshape(64, 64), cmap='gray')
    ax.set_title(f"Pred: {y_pred[i]}\nTrue: {y_test[i]}")
    ax.axis('off')
plt.tight_layout()
plt.show()
