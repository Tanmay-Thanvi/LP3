import pandas as pd
import numpy as np

from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC

from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, accuracy_score, precision_score, recall_score, f1_score

import warnings
warnings.filterwarnings("ignore")

df = pd.read_csv("/content/drive/MyDrive/ML_Assigments/emails.csv")

df

"""Data Preprocessing"""

df.drop(columns=['Email No.'],inplace=True)

df.columns

# df['Prediction']=df['Prediction'].replace({1:'Spam',0:'Not Spam'})

# df

df=df.dropna()

df.isna().sum()

df.shape

"""Model Implementation"""

def evaluate_model(model_name,y_test,y_pred):
  print("---- Evaluation Result ----")
  print("Name of Model : ",model_name)
  print("Accuracy : ",accuracy_score(y_test,y_pred))
  print("Precision : ",precision_score(y_test, y_pred))
  print("Recall : ",recall_score(y_test, y_pred))
  print("F1 Score : ",f1_score(y_test, y_pred))
  print("\nConfusion Matrix : \n",confusion_matrix(y_test,y_pred))

"""Feature Selection and Dataset Split"""

# Feature Selection
X=df.drop(['Prediction'],axis=1)
Y=df[['Prediction']]

# Splitting Dataset
x_train,x_test,y_train,y_test=train_test_split(X,Y,test_size=0.4,random_state=1)

"""KNN Model"""

# Model Building
kn = KNeighborsClassifier()
kn.fit(x_train,y_train)
y_pred_knn = kn.predict(x_test)

# Evaluation
evaluate_model("KNN",y_test,y_pred_knn)

"""SVC Model"""

# Model Building
svc = SVC()
svc.fit(x_train,y_train)
y_pred_svc = svc.predict(x_test)

# Evaluation
evaluate_model("SVC",y_test,y_pred_svc)