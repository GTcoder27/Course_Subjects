import pandas as pd
import numpy as np




arr = np.array([1,2,3,4,5])
pd.Series(arr)
data = {
    "Name" : ["girish","partho","bhushan"],
    "Age" : [21,22,23],
    "City" : ["Palandur","Nagpur","Pulgaon"]
}
df = pd.DataFrame(data)
data2 = {
    "A":[1,2,4,5,np.nan],
    "B":[np.nan,3,6,7,4],
    "C":[6,7,2,np.nan,3]
}
df1 = df2 = pd.DataFrame(data2)


df['horsepower'] = pd.to_numeric(df['horsepower'],errors='coerce') # convert to numeric


df.drop('City',axis=1)      # axis=1 is column and axis=0 is row
df.drop(['City','Salary'],axis=1)
inplace=True                # used for change in main data and not making another copy 
df.iloc[1]                  # similar to accessing the list (also supports slicing)
df[(df["Age"] > 20) & (df["City"] == "Nagpur")]

df2.isna().sum()
df2.dropna()        # delete rows which having null values 
df2.fillna(0)       # fill 0 to all null values
pd.merge(df1,df2,on='employee_id') # another parameters are how='inner' or 'outer' or 'left' or 'right'
pd.concat(df1,df2)                 # join 2 dataframes 
df1.join(df2,how='outer')
cat = df.groupby("Category")       # cat is an object which cannot be print
for i,v in cat:
    print(i)
    print(v)
# example:  cat = df.groupby(["Catagory","Store"])["Sales"].sum()
#           print(cat)

df["Sales"].agg(['mean','min','max','sum'])     # gives all at one time
pd.pivot_table(df,values="Sales",index="Region",columns="Product")  # values should be numeric only 
pd.pivot_table(df,values=["Sales","Units"],index="Region",columns="Product")  
pd.crosstab(df['Region'],df['Product'])     # gives counts  

df.shape
df.columns
df.info()
df.describe()
def square(x):
    return x**2
df["new_Sales"] = df["Sales"].apply(square)     # you can also apply lamda function

pd.read_csv(r"file.csv")
pd.read_excel(r"file.xlsx")
pd.read_json(r"file.json")
df.head()
df.sort_values(by='Sales')
df['region'].value_counts()  
df['Sales'].nlargest(2).iloc[1]         # 2nd largest 











