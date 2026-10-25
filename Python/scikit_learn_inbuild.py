
# to save any trained model

import joblib
# Save
joblib.dump(trained_model, 'startup_model.pkl')
# Load
model = joblib.load('startup_model.pkl')

# Split into training and testing dataset

from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test = train_test_split(x,y,test_size = 0.25,random_state = 0)

# Linear Regression Model

from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(x_test,y_test)
result = regressor.predict(x_test)

# Encoding Catagorical Data (mostly used for multiple linear regression)

# Label Encoder
from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()
x[:,2] = le.fit_transform(x[:,2])    # Output [2, 1, 0, 1]

# OneHot Encoder
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
ct = ColumnTransformer(transformers=[('encoder', OneHotEncoder(), [1])], remainder='passthrough')
x = np.array(ct.fit_transform(x))
# Output
# [[0. 0. 1.]
#  [0. 1. 0.]
#  [1. 0. 0.]
#  [0. 1. 0.]]

# Multiple Linear Regression

# 1] Encoding Catagorical Data
# 2] Split into training and testing dataset
# 3] fit x and y into LinearRegression
# 4] predict

# Polynomial Regression

from sklearn.preprocessing import PolynomialFeatures
poly_reg = PolynomialFeatures(degree = 4)
x_poly = poly_reg.fit_transform(x)
lin_reg_2 = LinearRegression()
lin_reg_2.fit(x_poly, y)
lin_reg_2.predict(poly_reg.fit_transform([[6.5]]))

# Feature Scaling (must required when your algorithm is based on euclidean distance)

from sklearn.preprocessing import StandardScaler
sc_x = StandardScaler()
sc_y = StandardScaler()
x = sc_x.fit_transform(x)
y = sc_y.fit_transform(y.reshape(-1, 1))

# Support Vector Regression

from sklearn.svm import SVR
regressor = SVR(kernel = 'rbf')
regressor.fit(x, y)

# Decision Tree Regression

from sklearn.tree import DecisionTreeRegressor
regressor = DecisionTreeRegressor(random_state = 0)
regressor.fit(x, y)

# Random Forest Regression

from sklearn.ensemble import RandomForestRegressor
regressor = RandomForestRegressor(n_estimators = 300, random_state = 0 )
# n_estimators is the number of trees in the forest
regressor.fit(x, y)

# Confusion Matrix

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test, y_pred)
print(cm)

# Logistc Regression

from sklearn.linear_model import LogisticRegression
model = LogisticRegression()
model.fit(x_train,y_train)

# KNN - K Nearest Neighbours

from sklearn.neighbors import KNeighborsClassifier
model = KNeighborsClassifier()
model.fit(x_train,y_train)

# Support Vector Classification

from sklearn.svm import SVC
classifier = SVC(kernel = 'linear',random_state=0)
classifier.fit(x, y)

# Naive bayes classification

from sklearn.naive_bayes import GaussianNB
model = GaussianNB()
model.fit(x_train,y_train)

# Random forest Classifier

from sklearn.ensemble import RandomForestClassifier
model = RandomForestClassifier(n_estimators=10,criterion='entropy',random_state=0)
model.fit(x_train,y_train)

# Dendogram

import scipy.cluster.hierarchy as sch
dendogram = sch.dendrogram(sch.linkage(x,method='ward'))
plt.title('dendogram')
plt.xlabel('customers')
plt.ylabel('euclidean distances')
plt.show()

# Cleaning the text for Natural Language Processing (NLP)

import re
from nltk.corpus import stopwords
import nltk
from nltk.stem.porter import PorterStemmer
nltk.download('stopwords')
ps = PorterStemmer()

corpus = []
n = len(dataset['Review'])
for i in range(0,n):
    review = re.sub('[^a-zA-Z]',' ',dataset['Review'][i])
    review = review.lower()
    review = review.split()
    review = [ps.stem(word) for word in review if not word in stopwords.words('english')]
    review = ' '.join(review)
    corpus.append(review)

#  to score model
from sklearn.metrics import confusion_matrix, accuracy_score
cm = confusion_matrix(y_test, y_pred)
print(cm)
accuracy_score(y_test, y_pred)

# Initialising ANN

import keras
from keras.models import Sequential
from keras.layers import Dense

ann = Sequential()
ann.add(Dense(units=6,activation='relu'))
ann.add(Dense(units=6,activation='relu'))
ann.add(Dense(units=1,activation='sigmoid'))
ann.compile(optimizer='adam',loss='binary_crossentropy',metrics=['accuracy'])

ann.fit(x_train,y_train,batch_size=10,epochs=100)

y_pred = ann.predict(x_test)

# Initialising CNN

import tensorflow as tf

cnn = tf.keras.models.Sequential()

cnn.add(tf.keras.layers.Conv2D(filters=32, kernel_size=3, activation='relu', input_shape=[64, 64, 3])) #Convolution
cnn.add(tf.keras.layers.MaxPool2D(pool_size=2, strides=2)) #pooling

cnn.add(tf.keras.layers.Conv2D(filters=32, kernel_size=3, activation='relu'))  # Convolution
cnn.add(tf.keras.layers.MaxPool2D(pool_size=2, strides=2)) # pooling

cnn.add(tf.keras.layers.Flatten()) #Flattening

cnn.add(tf.keras.layers.Dense(units=128, activation='relu')) #Full connection
cnn.add(tf.keras.layers.Dense(units=1, activation='sigmoid'))

cnn.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])



