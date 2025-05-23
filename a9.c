import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_olivetti_faces
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
# Load the Olivetti Faces dataset
faces = fetch_olivetti_faces()
X = faces.data # Each image is flattened into a 1D array (4096 pixels)
y = faces.target # Labels: 0 to 39 (40 people)
# Split into train and test sets
# Let's use 80% for training and 20% for testing
X_train, X_test, y_train, y_test= train_test_split(X, y, test_size=0.2, random_state=42)
# Create and train the Naive Bayes classifier
gnb= GaussianNB()
gnb.fit(X_train, y_train)
# Predict on the test data
y_pred= gnb.predict(X_test)
# Compute accuracy
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy: {accuracy * 100:.2f}%")

print(classification_report(y_test, y_pred))
# Confusion matrix
print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))
# OPTIONAL: Plot some test images with their predictions
fig, axes = plt.subplots(2, 5, figsize=(10, 5))
axes = axes.flatten()
for i, ax in enumerate(axes):
    ax.imshow(X_test[i].reshape(64, 64), cmap='gray')
    ax.set_title(f"Pred: {y_pred[i]}\nTrue: {y_test[i]}")
    ax.axis('off')
    plt.tight_layout()
    plt.show()
