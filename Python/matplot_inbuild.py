import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


x = [3,4,6,3,2,2]
y = [9,4,7,3,2,2]
plt.plot(x,y)
plt.title("title")
plt.xlabel("xlabel")
plt.ylabel("ylabel")


fig = plt.figure(figsize=(5,5))
ax = fig.add_axes([0,0,0.4,0.8])
ax.set_title("timepass graph")
ax.set_xlabel("G")
ax.set_ylabel("T")
ax.boxplot(x)
ax.plot(x,y,color='red',label='line1')
ax.legend()
fig.show()



fig ,(ax1,ax2) = plt.subplots(1,2)

ax1.plot(x,y,color='g',label='line1')
ax1.set_title("title1 hai ",fontsize=25)
ax1.set_xlabel("xlabel1 hai ",fontsize=20)
ax1.set_ylabel("ylabel1 hai",fontsize=20)

ax2.plot(x,y,color='r',label='line2')
ax2.set_title("title2 hai ",fontsize=25)
ax2.set_xlabel("xlabel1 hai ",fontsize=20)
ax2.set_ylabel("ylabel2 hai",fontsize=20)

fig.tight_layout() # used for not to overlap subplots over each other 
fig.show()


fig.savefig("plot1.png")



#  Types of charts 
ax.plot(df['weight'],label='weight',linestyle='--',lineweight=2)   # linechart
ax.plot(df['horsepower'],label='horsepower')    # we can add more than 1 line graphs in one figure


ax.boxplot(df['price'])                             # boxplot
ax.boxplot([df['price'],df['age']],widths=0.5)      # boxplot
ax.scatter(df['horsepower'],df['mpg'])              # scatterplot

grouped_df = df.groupby(['model_year']).count()[['name']]
grouped_df.reset_index(inplace=True)
ax.bar(grouped_df['model_year'],grouped_df['name'])   # barplot

ax.hist(df['horsepower'],bins=20)                     # histogram
ax.pie(df['count'],labels=df['country'])              # piechart
# parameters for pie char if 3 plots are there
# expload -> to get an elevated view for the selected pie. example: [0.5,0,0]
# colors -> array to customize the colors for the plot. example:['r','g','b']
# autopct -> to add the percentage of the distribution in the pie chart. example:'%0.1f%%'
# shadow -> to add shadow to the plot. example: True
# startangle -> to change the starting angle of the pie chart. example:250







