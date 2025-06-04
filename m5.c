import numpy as np
from sklearn.neighbors import KNeighborsClassifier

np.random.seed(0)
x = np.linspace(100, 1, 100).reshape(-1, 1)  

x_train = x[:50]
y_train = np.array([0.0 if val <= 50 else 1.0 for val in x_train.flatten()])
x_test = x[50:]

k_values = [1, 2, 3, 4, 5, 20, 30]
print("KNN Classifier Predictions for x[51] to x[100]:\n")

for k in k_values:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(x_train, y_train)
    y_pred = knn.predict(x_test)

    print(f"Results for k={k}:")
    for i, (x_val, label) in enumerate(zip(x_test, y_pred), start=51):
        class_name = 'Class 1' if label == 0 else 'Class 2'
        print(f"x[{i}] = {x_val[0]:.4f} => predicted: {class_name}")
    print("__" * 10)
