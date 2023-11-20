from google.colab import drive
drive.mount('/content/drive')

# Load the Dataset
data = pd.read_csv("/content/drive/MyDrive/ML_Assigments/uber.csv")

import pandas as pd
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import r2_score, mean_squared_error
from math import sqrt

# Data preprocessing
data = data.drop(columns=['Unnamed: 0', 'key']) # not in shete

# Drop rows with missing values
data.dropna(inplace=True)

# Convert pickup_datetime to datetime object
data['pickup_datetime'] = pd.to_datetime(data['pickup_datetime'])

# Extract features from pickup_datetime
data['hour'] = data['pickup_datetime'].dt.hour
data['day'] = data['pickup_datetime'].dt.day
data['month'] = data['pickup_datetime'].dt.month
data['year'] = data['pickup_datetime'].dt.year

# Drop the original pickup_datetime column
data.drop(columns=['pickup_datetime'], inplace=True)

# Identify outliers
sns.boxplot(x=data['fare_amount'])

# Remove Outliers
q_low = data["fare_amount"].quantile(0.01)
q_hi  = data["fare_amount"].quantile(0.99)
data = data[(data["fare_amount"] < q_hi) & (data["fare_amount"] > q_low)]

# Check the correlation
data.corr()

correlation_matrix = data.corr()
sns.heatmap(correlation_matrix, annot=True)

# Splitting the data into training and testing sets
X = data.drop(columns=['fare_amount'])
y = data['fare_amount']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Linear Regression
lr = LinearRegression()
lr.fit(X_train, y_train)
lr_pred = lr.predict(X_test)

# Random Forest Regression
rf = RandomForestRegressor(n_estimators=100)
rf.fit(X_train, y_train)
rf_pred = rf.predict(X_test)

# Evaluation
def evaluate_model(true, pred):
    r2 = r2_score(true, pred)
    rmse = sqrt(mean_squared_error(true, pred))
    return r2, rmse

lr_r2, lr_rmse = evaluate_model(y_test, lr_pred)
rf_r2, rf_rmse = evaluate_model(y_test, rf_pred)

print("Linear Regression:")
print(f"R-squared: {lr_r2}, RMSE: {lr_rmse}")

print("\nRandom Forest Regression:")
print(f"R-squared: {rf_r2}, RMSE: {rf_rmse}")