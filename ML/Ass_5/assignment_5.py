import pandas as pd
import numpy as np

import warnings
warnings.filterwarnings("ignore")

df = pd.read_csv('/content/drive/MyDrive/ML_Assigments/sales_data_sample.csv', encoding='unicode_escape')

df

"""Data Preprocessing"""

from sklearn.preprocessing import StandardScaler

sc = StandardScaler()
scaled_data = sc.fit_transform(df[['QUANTITYORDERED','SALES']])
scaled_data

"""K Means Clustering (10 Clusters)"""

from sklearn.cluster import KMeans

# 10 times clusters were formed
wcss=[]
for i in range(0,10):
  kmeans = KMeans(n_clusters = i+1)
  kmeans.fit(scaled_data)
  wcss.append(kmeans.inertia_)

import matplotlib.pyplot as plt
plt.plot(range(1,11),wcss,marker='o')
for i, (x, y) in enumerate(zip(range(1, 11), wcss)):
    plt.annotate(f'({x}, {y:.2f})', xy=(x, y), xytext=(-15, 10), textcoords='offset points', ha='left')

optimal_k=3
kmeans = KMeans(n_clusters=optimal_k)
df['Cluster_No.'] = kmeans.fit_predict(scaled_data)

df['Cluster_No.']

centroids = kmeans.cluster_centers_
print(centroids)

import seaborn as sns
plt.scatter(0,0)
for i in range(optimal_k):
  plt.scatter(df[df['Cluster_No.']==i]['QUANTITYORDERED'],df[df['Cluster_No.']==i]['SALES'])

# Add labels, title, and legend to the plot
plt.xlabel('No. of Ordered Quantity')
plt.ylabel('Sales')
plt.title('Clusters of Products')
plt.legend()

# Show the plot
plt.show()

sns.scatterplot(data=df,x='QUANTITYORDERED',y='SALES',hue='Cluster_No.')
plt.title('Clusters of Products')

# Show the plot
plt.show()