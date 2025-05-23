from sklearn.datasets import load_breast_cancer
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import numpy as np
# Step 1: Load the dataset
data = load_breast_cancer()
X = data.data
y = data.target
feature_names = data.feature_names
target_names = data.target_names
print("Features:", feature_names)
print("Target classes:", target_names)
# Step 2: Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y,
test_size=0.2, random_state=42)
# Step 3: Train the Decision Tree Classifier
clf = DecisionTreeClassifier(random_state=42)
clf.fit(X_train, y_train)

# Step 4: Predict on the test set
y_pred = clf.predict(X_test)
# Step 5: Evaluate the accuracy
accuracy = accuracy_score(y_test,
y_pred)
print("Model Accuracy:", accuracy)

new_sample = X_test[0].reshape(1,
-1)
predicted_class =clf.predict(new_sample)
print("New Sample Prediction:",
target_names[predicted_class[0]])
print("Actual Class:",
target_names[y_test[0]])
